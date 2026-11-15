"""Local memoization of successful checks on exact content snapshots.

No acceptance evidence is cached here. Changed source, tools, metadata, paths or modes get a
new key; failures are never saved. Publication results bind the immutable index and the current
private denylist; working file contents are always scanned.
"""
import hashlib
import json
from pathlib import Path
import subprocess


def snapshot(root, staged=False):
    root = Path(root)
    records = subprocess.check_output(['git', 'ls-files', '--stage', '-z'], cwd=root)
    h = hashlib.sha256(b'check-snapshot-v1\0' + records)
    untracked = []
    if not staged:
        changed = subprocess.check_output(['git', 'diff', '--name-only', '-z'], cwd=root).split(b'\0')
        untracked = subprocess.check_output(['git', 'ls-files', '--others', '--exclude-standard', '-z'], cwd=root).split(b'\0')
        # Include ignored public context too: an ignored header can affect include resolution,
        # and ignored evidence can affect existence checks. Never walk private storage.
        ignored = subprocess.check_output(['git', 'ls-files', '--others', '--ignored', '--exclude-standard', '-z',
                                            '--', 'reconstruction', 'builds', 'data', 'findings', 'reports', 'docs'],
                                           cwd=root).split(b'\0')
        for raw in sorted(set(changed + untracked + ignored) - {b''}):
            path = root / raw.decode()
            h.update(raw + b'\0')
            if path.is_symlink():
                h.update(b'symlink')
            elif path.is_file():
                h.update(hashlib.sha256(path.read_bytes()).digest())
                h.update(str(path.stat().st_mode).encode())
            else:
                h.update(b'missing')
    # Staged validation still executes the tools of the current checkout.
    for path in sorted((root / 'tools').rglob('*')):
        if path.suffix in ('.py', '.json') and path.is_file() and '__pycache__' not in path.parts:
            h.update(path.relative_to(root).as_posix().encode() + b'\0')
            h.update(hashlib.sha256(path.read_bytes()).digest())
    # Lint optionally verifies the notice against the private pinned checkout's licence.
    from lint_reconstruction import LICENCE_FILES, LOCAL_SOURCES
    for name in sorted(LICENCE_FILES.values()):
        path = LOCAL_SOURCES / name
        h.update(name.encode() + b'\0')
        h.update(hashlib.sha256(path.read_bytes()).digest() if path.is_file() else b'missing')
    # The same snapshot has different skeleton semantics before and after staging.
    h.update(b'\0'.join(sorted(filter(None, untracked))))
    return h.hexdigest()


def read(root, namespace, key):
    try:
        return json.loads((Path(root) / '.local/revision-cache' / namespace / (key + '.json')).read_text())
    except (OSError, ValueError):
        return None


def save(root, namespace, key, value):
    import os
    import tempfile
    directory = Path(root) / '.local/revision-cache' / namespace
    try:
        directory.mkdir(parents=True, exist_ok=True)
        with tempfile.NamedTemporaryFile(mode='w', dir=directory, delete=False) as out:
            json.dump(value, out)
            path = Path(out.name)
        os.replace(path, directory / (key + '.json'))
    except OSError:
        pass  # A read-only checkout still runs all checks.
