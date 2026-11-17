"""Lifecycle retention for finished working copies; retain evidence and Git refs."""
from contextlib import ExitStack, contextmanager
import fcntl
import hashlib
import json
import os
import re
from pathlib import Path
import shutil
import subprocess
import uuid

import flow as f
import flow_lane as lane

FINISHED = {'done', 'retired', 'stale', 'failed'}
TIERS = ('first', 'fallback', 'strong')
_AUTOMATIC_STATE = {}


def finished(receipt):
    integrated = receipt.get('integrated') or {}
    return (receipt.get('state') in FINISHED
            and integrated.get('ci') != 'pending'
            and not (integrated.get('pushed') and integrated.get('ci') not in ('green', 'red', 'red-advisory-superseded'))
            and (integrated.get('ci') != 'red-advisory-superseded'
                 or (receipt.get('state') == 'done' and integrated.get('superseded_by')
                     and integrated.get('ci_supersession'))))


def claim_harvest(root, queue, unit, tier):
    directory = f.drafts.task_dir(root, unit)
    done_path = f.wq.tier_dir(queue, 'done', tier) / (unit['key'] + '.json')
    done = f.drafts.read(done_path, {})
    harvest = (done.get('harvest') or f.drafts.read(directory / ('harvest-' + tier + '.json'))
               or f.drafts.read(directory / 'harvest.json', {}))
    f.refuse(not any((f.wq.tier_dir(q.parent, 'claims', t) / (unit['key'] + '.lock')).exists()
                     for q in (root / '.local/queue').glob('*/queue.tsv') for t in TIERS),
             'draft claim is open or drafting')
    f.refuse(done_path.is_file() and harvest.get('tier') == tier and bool(harvest.get('commit')),
             'no completed unit harvest for this tier')
    commit = harvest['commit']
    f.refuse(len(commit) == 40 and all(c in '0123456789abcdef' for c in commit), 'invalid harvest commit')
    f.refuse(f.git(root, 'cat-file', '-t', commit, check=False) == 'commit', 'harvest commit missing from object store')
    return harvest


def candidates(root, fdir, prune_claims=False, input_paths=()):
    if input_paths:
        for tree in input_paths:
            yield Path(tree).absolute(), None, 'explicit retained input', ('input', ''), None
        return
    for receipt in (fdir / 'lane/runs').glob('*.json'):
        r = lane.read(receipt)
        if Path(r['id']).name != r['id'] or r['id'] in ('.', '..'):
            continue
        # Include every retry working copy, not just the last tree recorded by the run.
        for tree in (fdir / 'lane/trees' / r['id']).glob('*'):
            if tree.name.isdecimal():
                yield tree, None, 'lane ' + r['id'], ('lane', r['id']), receipt
        # Isolation snapshots borrow the outer run's lifecycle, not their frozen receipts.
        for isolation in (fdir / 'lane/isolation').glob(r['id'] + '*'):
            suffix = isolation.name.removeprefix(r['id'])
            if suffix and not (suffix.startswith('-') and suffix[1:].isdecimal()):
                continue
            for tree in (isolation / 'lane/trees' / r['id']).glob('*'):
                if tree.name.isdecimal():
                    yield tree, None, 'lane isolation ' + r['id'], ('lane', r['id']), receipt
    for state_path in (fdir / 'reconfirm').glob('*/state.json'):
        state = lane.read(state_path)
        tree = state_path.parent / 'tree'
        if state.get('view') == str(tree):
            yield tree, None, 'reconfirmation ' + state_path.parent.name, ('reconfirm', state_path.parent.name), state_path
    for g in f.groups(fdir).values():
        rerun = g.get('rerun') or {}
        if (g.get('sampled') and not rerun.get('not_agree', [True])
                and set(rerun.get('agree', [])) == set(g['sampled'])
                and (g.get('rerun_dispatched') or '') <= rerun.get('recorded', '')):
            yield (fdir / 'rerun' / g['name'] / 'tree', g['source_revision'],
                   'AGREE rerun ' + g['name'], ('rerun', g['name']), None)
    if prune_claims:
        seen = set()
        for queue in (root / '.local/queue').glob('*/queue.tsv'):
            for unit in f.wq.read_queue(queue.parent):
                for tier in TIERS:
                    tree = root / '.local/worktrees/draft' / (unit['key'] + '-' + tier)
                    if tree not in seen:
                        seen.add(tree)
                        yield tree, None, 'draft ' + unit['key'], ('draft', unit['key']), (queue.parent, unit, tier)


def check_live(fdir, tree, owner, metadata):
    if owner[0] == 'lane':
        receipt = lane.read(metadata)
        f.refuse(finished(receipt), 'receipt is running, queued or awaiting CI')
        f.refuse(not lane.owner_alive(receipt.get('owner')), 'receipt has a live owner')
    if owner[0] == 'rerun':
        current = f.load_group(fdir, owner[1])
        rerun = current.get('rerun') or {}
        f.refuse(not rerun.get('not_agree', [True])
                 and set(rerun.get('agree', [])) == set(current.get('sampled', []))
                 and (current.get('rerun_dispatched') or '') <= rerun.get('recorded', ''),
                 'rerun no longer complete and AGREE')
    if owner[0] == 'reconfirm':
        state = lane.read(metadata)
        f.refuse(state.get('phase') == 'queued', 'reconfirmation is not finished')
        requests = [lane.read(p) for p in (fdir / 'lane/queue').glob('*.json')
                    if lane.read(p).get('root') == str(tree)]
        f.refuse(bool(requests) and all(r.get('state') == 'done' for r in requests),
                 'reconfirmation has unfinished selections')
    for name in ('queue', 'tooling-queue', 'tooling', 'runs'):
        for path in (fdir / 'lane' / name).glob('*.json'):
            value = lane.read(path)
            pending = (value.get('integrated') or {}).get('pushed') and not finished(value)
            if value.get('state') in ('queued', 'running') or pending or lane.owner_alive(value.get('owner')):
                # Origins, nested selections and saved commands can also retain inputs.
                pattern = re.compile(re.escape(str(tree)) + r"(?=$|[/\s'\"])")
                def references(obj):
                    if isinstance(obj, str):
                        yield obj
                    elif isinstance(obj, dict):
                        for key, child in obj.items():
                            yield from references(key)
                            yield from references(child)
                    elif isinstance(obj, list):
                        for child in obj:
                            yield from references(child)
                f.refuse(not any(pattern.search(value) for value in references(value)),
                         'queued/running input')


def process_paths():
    """Read-only process/open-file snapshot; never stop another worker."""
    commands = subprocess.run(['ps', '-axo', 'pid,command'], capture_output=True, text=True, check=True).stdout
    if shutil.which('lsof'):
        handles = subprocess.run(['lsof', '-nP', '-Fpn'], capture_output=True, text=True)
        if handles.returncode not in (0, 1):
            raise OSError('cannot inspect open files for retention')
        return commands + '\n' + handles.stdout
    proc = Path('/proc')
    if not (proc / 'self/fd').is_dir():
        raise OSError('cannot inspect open files for retention: no lsof or /proc fd')
    paths = []
    for process in proc.iterdir():
        if not process.name.isdigit():
            continue
        try:
            descriptors = list((process / 'fd').iterdir())
            for descriptor in descriptors:
                try:
                    paths.append(os.readlink(descriptor))
                except FileNotFoundError:
                    pass
        except FileNotFoundError:
            continue
        except OSError as exc:
            raise OSError('cannot inspect open files for retention: /proc access denied') from exc
    return commands + '\n' + '\n'.join(paths)


def path_in_use(tree, processes):
    return bool(re.search(re.escape(str(tree)) + r"(?=$|[/\s'\"])", processes, re.M))


def prune_isolation(root, fdir, processes):
    """Move terminal snapshot metadata to cold archives, retaining borrowed Git stores."""
    results = []
    for snapshot in (fdir / 'lane/isolation').glob('*'):
        run = snapshot.name.split('-')[0]
        receipt = fdir / 'lane/runs' / (run + '.json')
        if not receipt.is_file() or snapshot.is_symlink():
            continue
        value = lane.read(receipt)
        if not finished(value) or lane.owner_alive(value.get('owner')) or path_in_use(snapshot, processes):
            continue
        trees = list((snapshot / 'lane/trees').glob('*/*'))
        if any(set(p.name for p in tree.iterdir()) != {'.git'} for tree in trees if tree.is_dir()):
            continue
        try:
            check_live(fdir, snapshot, ('lane', run), receipt)
        except f.FlowError:
            continue
        paths = [snapshot / name for name in ('groups', 'imports', 'combined', 'versions.json',
                                              'events.jsonl', 'lane/queue', 'lane/runs',
                                              'lane/tooling', 'lane/tooling-queue', 'lane/owner.json')]
        paths = [path for path in paths if path.exists()]
        if not paths:
            continue
        archive = fdir.parent / 'archive/cleanup' / ('isolation-' + snapshot.name)
        # Never overwrite a previous archive after an interrupted move.
        archive = archive.with_name(archive.name + '-' + uuid.uuid4().hex)
        for path in paths:
            dest = archive / 'files' / path.relative_to(snapshot)
            dest.parent.mkdir(parents=True, exist_ok=True)
            shutil.move(str(path), dest)
        row = dict(tree=str(snapshot), archive=str(archive), removed=True,
                   proof='terminal isolation metadata; Git object stores retained')
        lane.write(archive / 'receipt.json', row)
        results.append(row)
    return results


def archive_evidence(tree, archive, lane_copy, all_untracked=False):
    """Clean tracked files remain recoverable from Git; archive private evidence only."""
    tracked = set(f.git(tree, 'ls-files', '-z').split('\0'))
    links = {}
    for directory, dirs, files in os.walk(tree, followlinks=False):
        for name in dirs + files:
            path = Path(directory) / name
            if path.is_symlink():
                links[str(path.relative_to(tree))] = os.readlink(path)
        dirs[:] = [d for d in dirs if d != '.git' and not (Path(directory) / d).is_symlink()]
        for name in files:
            src = Path(directory) / name
            rel = src.relative_to(tree)
            if rel == Path('.git'):
                continue
            evidence = (all_untracked or src.suffix.lower() in ('.json', '.jsonl', '.log', '.txt', '.stdout', '.stderr')
                        or any(p in ('handoffs', 'reviews') or 'logs' in p for p in rel.parts[:-1])
                        or '.local' in rel.parts
                        or lane_copy and src.suffix.lower() in ('.cpp', '.h', '.py'))
            if not src.is_symlink() and str(rel) not in tracked and evidence:
                dest = archive / 'files' / rel
                dest.parent.mkdir(parents=True, exist_ok=True)
                if src.stat().st_size <= 8 * 1024 ** 2:
                    shutil.copy2(src, dest)
                else:
                    # Keep large logs without doubling their disk footprint.
                    shutil.move(str(src), dest)
    if all_untracked:
        for name, args in (('index-changes.patch', ('--cached', 'HEAD')),
                           ('unstaged-changes.patch', ())):
            patch = f.git(tree, '--no-optional-locks', 'diff', '--binary', *args)
            if patch:
                (archive / name).write_text(patch)
    if lane_copy:
        patch = f.git(tree, '--no-optional-locks', 'diff', '--binary', 'HEAD')
        if patch:
            (archive / 'working-changes.patch').write_text(patch)
    lane.write(archive / 'links.json', links)


@contextmanager
def cleanup_lock(fdir, blocking=True):
    with (fdir / 'cleanup/.cleanup.lock').open('a') as handle:
        fcntl.flock(handle, fcntl.LOCK_EX | (0 if blocking else fcntl.LOCK_NB))
        try:
            yield
        finally:
            fcntl.flock(handle, fcntl.LOCK_UN)


def cleanup(root, fdir, dry_run=False, prune_claims=False, keep_task_prefixes=(), input_paths=(), blocking=True):
    root, fdir = Path(root).resolve(), Path(fdir).resolve()
    results = []
    (fdir / 'cleanup').mkdir(parents=True, exist_ok=True)
    # Serialize cleaners, never block an unrelated verifier/publication run.
    with cleanup_lock(fdir, blocking):
        processes = process_paths()
        for tree, commit, proof, owner, metadata in candidates(root, fdir, prune_claims, input_paths):
            if not tree.exists() or set(p.name for p in tree.iterdir()) == {'.git'}:
                continue
            row = dict(tree=str(tree), proof=proof, removed=False)
            results.append(row)
            reservation = None
            with ExitStack() as locks:
                try:
                    f.refuse(not path_in_use(tree, processes), 'checkout has an open process or file')
                    lane_copy = owner[0] in ('lane', 'input', 'reconfirm')
                    if owner[0] == 'draft':
                        f.refuse(not any(owner[1].startswith(p) for p in keep_task_prefixes), 'protected worker task')
                        queue, unit, tier = metadata
                        locks.enter_context(f.wq.locked(f.drafts.task_dir(root, unit) / 'draft-lifecycle.lock'))
                        harvest = claim_harvest(root, queue, unit, tier)
                        f.refuse(harvest.get('tree') == str(tree), 'harvest checkout path mismatch')
                        row['harvest_commit'] = harvest['commit']
                    f.refuse(not tree.is_symlink() and tree.resolve() == tree.absolute(), 'symlink checkout')
                    f.refuse(not (tree / '.git').is_symlink(), 'symlink Git metadata')
                    allowed = (root / '.local/worktrees/draft' if owner[0] == 'draft' else
                               next((p for p in tree.parents if p.name == '.local'), root / '.local')
                               if owner[0] == 'input' else fdir)
                    f.refuse(tree.is_relative_to(allowed) and tree != allowed and tree != root, 'tree outside lifecycle directory')
                    with lane.state_lock(fdir):
                        check_live(fdir, tree, owner, metadata)
                    if owner[0] == 'reconfirm':
                        import fcntl
                        handle = locks.enter_context((metadata.parent / '.lock').open('a'))
                        try:
                            fcntl.flock(handle, fcntl.LOCK_EX | fcntl.LOCK_NB)
                        except BlockingIOError:
                            raise f.FlowError('reconfirmation has a live owner') from None
                    f.refuse(Path(f.git(tree, 'rev-parse', '--show-toplevel')).resolve() == tree, 'not a checkout root')
                    if owner[0] != 'input' and (tree / '.git').is_file():
                        # Plain worktree removal refuses these changes. Check before copying
                        # evidence, or every automatic retry archives the same dirty tree again.
                        status = f.git(tree, 'status', '--porcelain', '--untracked-files=all')
                        f.refuse(not status, 'dirty checkout: ' + status[:500])
                    if not lane_copy:
                        status = f.git(tree, 'status', '--porcelain', '--untracked-files=all', '--', '.', ':(exclude).local')
                        f.refuse(not status, 'dirty checkout: ' + status[:500])
                        if commit:
                            f.refuse(f.git(tree, 'rev-parse', 'HEAD') == commit, 'checkout differs from completed commit')
                        marker = json.loads((tree / '.local/worktree-owner.json').read_text())
                        f.refuse((marker.get('kind'), marker.get('task')) == owner, 'worktree owner mismatch')
                    explicit_worktree = owner[0] == 'input' and (tree / '.git').is_file()
                    if explicit_worktree:
                        gitdir = Path(f.git(tree, 'rev-parse', '--absolute-git-dir'))
                        f.refuse(not (gitdir / 'locked').exists(), 'locked worktree')
                        registered = f.git(tree, 'worktree', 'list', '--porcelain', '-z').split('\0')
                        copied_view = not any(line.startswith('worktree ')
                            and Path(line[9:]).resolve() == tree for line in registered)
                    for directory, dirs, files in os.walk(tree, followlinks=False):
                        f.refuse(Path(directory) == tree or '.git' not in dirs + files, 'nested checkout')
                        dirs[:] = [d for d in dirs if d != '.git' and not (Path(directory) / d).is_symlink()]
                    if dry_run:
                        row['would_remove'] = True
                        continue
                    reservation = fdir / 'cleanup/claims' / (hashlib.sha256(str(tree).encode()).hexdigest() + '.json')
                    with lane.state_lock(fdir):
                        check_live(fdir, tree, owner, metadata)
                        lane.write(reservation, dict(tree=str(tree), active=True, owner=lane.process_owner()))
                    archive = fdir.parent / 'archive/cleanup' / uuid.uuid4().hex
                    archive.mkdir(parents=True)
                    if owner[0] == 'input':
                        archive_evidence(tree, archive, lane_copy, all_untracked=True)
                    else:
                        archive_evidence(tree, archive, lane_copy)
                    lane.write(archive / 'receipt.json', row)
                    if owner[0] == 'draft':
                        harvest = claim_harvest(root, queue, unit, tier)
                        f.refuse(harvest['commit'] == row['harvest_commit'], 'harvest changed during cleanup')
                        f.git(root, 'update-ref', 'refs/cleanup/harvests/' + harvest['commit'], harvest['commit'])
                    with lane.state_lock(fdir):
                        check_live(fdir, tree, owner, metadata)
                    if (tree / '.git').is_file():
                        head = f.git(tree, 'rev-parse', 'HEAD')
                        f.git(tree, 'update-ref', 'refs/cleanup/working-copies/' + head, head)
                        shutil.copytree(Path(f.git(tree, 'rev-parse', '--absolute-git-dir')), archive / 'registration')
                        if explicit_worktree:
                            shutil.copy2(tree / '.git', archive / 'git-marker')
                        if explicit_worktree and copied_view:
                            # A copied marker shares another checkout's index and registration.
                            shutil.rmtree(tree)
                        elif explicit_worktree:
                            # Every untracked file and both index/worktree deltas are archived.
                            untracked = f.git(tree, 'ls-files', '--others', '--exclude-standard', '-z').split('\0')
                            f.git(tree, 'restore', '--source=HEAD', '--staged', '--worktree', '--', '.')
                            for name in filter(None, untracked):
                                path = tree / name
                                if path.is_symlink() or path.is_file():
                                    path.unlink()
                        if not explicit_worktree or not copied_view:
                            common = Path(f.git(tree, 'rev-parse', '--path-format=absolute', '--git-common-dir'))
                            f.git(common, 'worktree', 'remove', str(tree))  # no force, branch deletion or prune
                    else:
                        # Other clones may borrow this object store. Keep .git and all its refs.
                        f.refuse((tree / '.git').is_dir(), 'not a Git checkout')
                        for path in tree.iterdir():
                            if path.name != '.git':
                                if path.is_dir() and not path.is_symlink():
                                    shutil.rmtree(path)
                                else:
                                    path.unlink()
                    row.update(removed=True, archive=str(archive))
                    lane.write(archive / 'receipt.json', row)
                except (f.FlowError, OSError, ValueError) as error:
                    row['reason'] = str(error)
                finally:
                    if reservation is not None and reservation.is_file():
                        with lane.state_lock(fdir):
                            value = lane.read(reservation)
                            value['active'] = False
                            lane.write(reservation, value)
    return results


def retention_state(fdir):
    patterns = [f'lane/{name}/*.json' for name in ('runs', 'tooling', 'queue', 'tooling-queue')]
    patterns += ['groups/*.json', 'reconfirm/*/state.json', 'events.jsonl']
    files = sorted({path for pattern in patterns for path in fdir.glob(pattern)})
    return tuple((str(path), path.stat().st_mtime_ns, path.stat().st_size) for path in files)


def automatic_retention(root, fdir, offload=False):
    """Skip unchanged state in this process, and never wait behind an explicit cleaner."""
    fdir = Path(fdir).resolve()
    key = os.getpid(), str(fdir), offload
    state = retention_state(fdir)
    if _AUTOMATIC_STATE.get(key) == state:
        return []
    try:
        result = cleanup(root, fdir, blocking=False)
        with cleanup_lock(fdir, blocking=False):
            processes = process_paths()
            result.extend(prune_isolation(Path(root).resolve(), fdir, processes))
            if offload:
                import cold_storage
                def in_use(path):
                    if path_in_use(path, process_paths()):
                        return True
                    try:
                        with lane.state_lock(fdir):
                            check_live(fdir, path, ('input', ''), None)
                    except f.FlowError:
                        return True
                    return False
                try:
                    result.extend(cold_storage.automatic(root, in_use,
                        config_path=fdir.parent / 'cold-storage.json', fdir=fdir))
                except (OSError, ValueError, subprocess.SubprocessError) as error:
                    result.append(dict(cold_storage_error=str(error), removed=False))
    except BlockingIOError:
        return []  # A busy skip is neither a completed run nor a cached state.
    lane.write(fdir / 'cleanup/last-retention.json', dict(recorded=f.utc(), results=result))
    _AUTOMATIC_STATE[key] = state
    return result


def cleanup_inputs(root, fdir, paths, dry_run=False):
    """Explicitly authorized private input checkouts, guarded against live lane references."""
    paths = tuple(paths)
    return cleanup(root, fdir, dry_run=dry_run, input_paths=paths) if paths else []
