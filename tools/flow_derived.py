"""Merge lane inputs without merging generated presentations or losing inventory data."""
from contextlib import contextmanager
from datetime import datetime
import json
from pathlib import Path
import subprocess
import tempfile

import flow as f


# Deliberately closed set: no source, evidence, symbol map or acceptance record belongs here.
DERIVED_FILES = frozenset({
    'reconstruction/INDEX.md',
    'docs/progress.svg', 'docs/progress-map.svg',
    'docs/model-trend.svg', 'docs/progress-trend.svg',
})
PROGRESS = 'data/progress.json'
START, END = '<!-- model-trend-totals -->', '<!-- /model-trend-totals -->'
MISSING = object()


def choose(base, ours, theirs, where):
    if ours == theirs or theirs == base:
        return ours
    if ours == base:
        return theirs
    raise f.FlowError('conflicting source data: ' + where)


def merge_progress(base, ours, theirs):
    """Rows are atomic: disjoint additions/acceptances commute; competing row edits refuse."""
    result = {}
    for key in sorted(base.keys() | ours.keys() | theirs.keys()):
        values = [d.get(key, MISSING) for d in (base, ours, theirs)]
        if key == 'functions':
            indices = []
            for rows in values:
                f.refuse(isinstance(rows, list), 'inventory functions must be a list')
                index = {row['id']: row for row in rows}
                f.refuse(len(index) == len(rows), 'duplicate inventory identity')
                indices.append(index)
            ordered = dict.fromkeys(row['id'] for rows in values[1:] for row in rows)
            merged = {fid: choose(*(index.get(fid, MISSING) for index in indices),
                                  PROGRESS + ':functions:' + fid)
                      for fid in indices[0].keys() | indices[1].keys() | indices[2].keys()}
            value = [merged[fid] for fid in ordered if merged[fid] is not MISSING]
        elif key == 'updated_at' and all(isinstance(v, str) for v in values):
            # A timestamp is metadata about the combined input, never acceptance evidence.
            value = max(values, key=lambda v: datetime.fromisoformat(v.replace('Z', '+00:00')))
        else:
            value = choose(*values, PROGRESS + ':' + key)
        if value is not MISSING:
            result[key] = value
    return result


def readme_source(text):
    if text.count(START) != 1 or text.count(END) != 1:
        return None
    prefix, tail = text.split(START)
    if END not in tail:
        return None
    return prefix + START + '\n' + END + tail.split(END)[1]


def blob(tree, revision, path):
    result = subprocess.run(['git', 'show', revision + ':' + path], cwd=tree, capture_output=True)
    return result.stdout if result.returncode == 0 else None


@contextmanager
def derived_driver(tree, paths):
    """Candidate-local attributes; even overlapping generated edits never reach a text driver."""
    path = Path(f.git(tree, 'rev-parse', '--git-path', 'info/attributes'))
    if not path.is_absolute():
        path = tree / path
    before = path.read_bytes() if path.exists() else None
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_bytes((before or b'') + b'\n' + ''.join(
        f'/{name} merge=lane-derived\n' for name in sorted(paths)).encode())
    try:
        yield
    finally:
        if before is None:
            path.unlink()
        else:
            path.write_bytes(before)


def merge(tree, revision, *, no_ff=True):
    """Retain both immutable parents, merge real inputs, discard all derived input contents.

    The caller regenerates once after the tooling batch, before checking/publishing the tree.
    A real conflict leaves Git's merge state for the caller's normal abort/reset handling.
    """
    tree = Path(tree)
    ours = f.git(tree, 'rev-parse', 'HEAD')
    base = f.git(tree, 'merge-base', ours, revision)
    partial = {}
    progress = [blob(tree, rev, PROGRESS) for rev in (base, ours, revision)]
    if all(value is not None for value in progress):
        inputs = [json.loads(v) for v in progress]
        merged = merge_progress(*inputs)
        partial[PROGRESS] = (progress[1] if merged == inputs[1] else
                             (json.dumps(merged, indent=2, ensure_ascii=False) + '\n').encode())
    readmes = [blob(tree, rev, 'README.md') for rev in (base, ours, revision)]
    if all(value is not None for value in readmes):
        sources = [readme_source(v.decode()) for v in readmes]
        if all(value is not None for value in sources):
            with tempfile.TemporaryDirectory(prefix='lane-readme-') as tmp:
                paths = [Path(tmp) / str(i) for i in range(3)]
                for path, value in zip(paths, sources):
                    path.write_text(value)
                result = subprocess.run(['git', 'merge-file', '-p', str(paths[1]), str(paths[0]), str(paths[2])],
                                        capture_output=True)
            f.refuse(result.returncode == 0, 'conflicting source prose: README.md')
            totals = readmes[1].decode().split(START)[1].split(END)[0]
            partial['README.md'] = result.stdout.decode().replace(START + '\n' + END,
                                                                 START + totals + END, 1).encode()
    with derived_driver(tree, DERIVED_FILES | partial.keys()):
        try:
            f.git(tree, '-c', 'merge.lane-derived.driver=true', 'merge', '--quiet', '--no-edit',
                  *(['--no-ff'] if no_ff else []), '--no-commit', revision)
        except f.FlowError:
            conflicts = set(f.git(tree, 'diff', '--name-only', '--diff-filter=U').splitlines())
            if not conflicts or not conflicts <= DERIVED_FILES | partial.keys():
                raise
    if not (tree / f.git(tree, 'rev-parse', '--git-path', 'MERGE_HEAD')).exists():
        return  # Already integrated.
    # A trivial Git merge may have selected theirs without invoking a driver. Never retain it.
    for name in DERIVED_FILES:
        before = blob(tree, ours, name)
        if before is None:
            f.git(tree, 'rm', '--quiet', '--force', '--ignore-unmatch', '--', name)
        else:
            (tree / name).parent.mkdir(parents=True, exist_ok=True)
            (tree / name).write_bytes(before)
            f.git(tree, 'add', '--', name)
    for name, value in partial.items():
        (tree / name).write_bytes(value)
        f.git(tree, 'add', '--', name)
    f.git(tree, 'commit', '--quiet', '--no-edit')


def regenerate(tree, python):
    """Regenerate tracked views from the merged data using that tree's own generators."""
    for tool in ('build_index.py', 'build_progress_svg.py', 'build_model_trend.py'):
        f.run([python, 'tools/' + tool], tree, tool)
    # New presentation generators may arrive in the tooling input before this runner is upgraded.
    if (Path(tree) / 'tools/build_leaderboard.py').is_file():
        f.run([python, 'tools/build_leaderboard.py'], tree, 'build_leaderboard.py')
    paths = f.changed(tree, DERIVED_FILES | {'README.md', 'LEADERBOARD.md', 'data/contributors.json'})
    if paths:
        f.git(tree, 'add', '--', *paths)
        f.run([python, 'tools/check.py', '--staged'], tree, 'check.py --staged')
        f.git(tree, 'commit', '--quiet', '-m', 'Regenerate merged lane views')
