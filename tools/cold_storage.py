"""Verified private archive offload; transport and destinations come from ignored config."""
import datetime
import fcntl
import hashlib
import json
import os
from pathlib import Path
import shutil
import stat
import subprocess
import tarfile
import tempfile
import time


def digest(path):
    with Path(path).open('rb') as handle:
        return hashlib.file_digest(handle, 'sha256').hexdigest()


def inventory(path):
    rows = []
    for directory, dirs, files in os.walk(path, followlinks=False):
        for name in sorted(dirs + files):
            entry = Path(directory) / name
            stat = entry.lstat()
            rows.append((str(entry.relative_to(path)), stat.st_mode, stat.st_size, stat.st_mtime_ns,
                         os.readlink(entry) if entry.is_symlink() else None))
        dirs[:] = [name for name in dirs if not (Path(directory) / name).is_symlink()]
    return sorted(rows)


def write(path, value):
    path.parent.mkdir(parents=True, exist_ok=True)
    temporary = path.with_suffix('.tmp')
    temporary.write_text(json.dumps(value, indent=2) + '\n')
    temporary.replace(path)


def offload(root, path, config, in_use=lambda path: False):
    """A failed transfer, changed input, or hash mismatch always retains the original."""
    root, path = Path(root), Path(path)
    if path.is_symlink() or not path.is_dir() or in_use(path):
        raise ValueError('archive is absent, symlinked or in use')
    before = inventory(path)
    token = hashlib.sha256((str(path.resolve()) + json.dumps(before)).encode()).hexdigest()
    remote = config['directory'].rstrip('/') + '/' + token + '.tar.gz'
    manifest = Path(config.get('manifest', root / '.local/offload-manifest.json'))
    manifest.parent.mkdir(parents=True, exist_ok=True)
    with manifest.with_suffix('.lock').open('a') as lock:
        fcntl.flock(lock, fcntl.LOCK_EX)
        with tempfile.TemporaryDirectory(prefix='cold-offload-', dir=manifest.parent) as temporary:
            package = Path(temporary) / 'archive.tar.gz'
            with tarfile.open(package, 'w:gz', dereference=False) as archive:
                archive.add(path, arcname=path.name, recursive=True)
            sha = digest(package)
            subprocess.run(config['mkdir'], check=True, capture_output=True)
            subprocess.run(config['copy'] + [str(package), config['host'] + ':' + remote],
                           check=True, capture_output=True)
            command = [part.replace('{path}', remote) for part in config['hash']]
            result = subprocess.run(command, check=True, capture_output=True, text=True)
            if result.stdout.strip().lower() != sha:
                raise ValueError('remote archive SHA-256 mismatch; original retained')
            if inventory(path) != before or in_use(path):
                raise ValueError('archive changed or became active; original retained')
            item = dict(mac_path=str(path.resolve()), pc_path=remote, sha256=sha,
                        archive_bytes=package.stat().st_size, entries=len(before),
                        size_bytes=sum(row[2] for row in before if stat.S_ISREG(row[1])),
                        quarantined=False,
                        verified_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
                        mac_deleted=False, archive_format='tar.gz')
            value = json.loads(manifest.read_text()) if manifest.is_file() else dict(schema=1, items=[])
            value['items'].append(item)
            write(manifest, value)
            shutil.rmtree(path)
            item['mac_deleted'] = True
            write(manifest, value)
            return item


def object_borrowers(roots):
    """Inspect project Git stores only; symlink inputs and unrelated projects are never walked."""
    borrowers = {}
    skip = {'sources', 'analysis', 'toolchains', 'wineprefix', 'wine', 'msvc', 'drive_c',
            'node_modules', 'reconstruction', 'reports', 'packs', 'tasks', 'verifier', 'archive'}
    for root in roots:
        for directory, dirs, files in os.walk(root, followlinks=False):
            path = Path(directory)
            alternate = path / '.git/objects/info/alternates'
            if alternate.is_file():
                for name in alternate.read_text().splitlines():
                    target = Path(name)
                    if not target.is_absolute():
                        target = alternate.parent.parent / target
                    borrowers.setdefault(str(target.resolve()), []).append(str(path))
            dirs[:] = [name for name in dirs if name != '.git' and name not in skip
                       and not (path / name).is_symlink()]
    return borrowers


def finished_stores(root, fdir, config, in_use):
    """Offload terminal .git-only candidates only when no project checkout borrows them."""
    if not config.get('object_store_roots'):
        return []
    import flow_cleanup as retention
    import flow_lane as lane
    fdir = Path(fdir)
    borrowers = object_borrowers(config['object_store_roots'])
    results = []
    for tree, _, proof, owner, receipt in retention.candidates(Path(root), fdir):
        if owner[0] != 'lane' or not tree.is_dir() or tree.is_symlink():
            continue
        if set(path.name for path in tree.iterdir()) != {'.git'} or not (tree / '.git').is_dir():
            continue
        if in_use(tree) or borrowers.get(str((tree / '.git/objects').resolve())):
            continue
        reservation = fdir / 'cleanup/claims' / (hashlib.sha256(str(tree).encode()).hexdigest() + '.json')
        try:
            with lane.state_lock(fdir):
                retention.check_live(fdir, tree, owner, receipt)
                lane.write(reservation, dict(tree=str(tree), active=True, owner=lane.process_owner()))
            # Recheck borrowers/live state immediately before local deletion as well.
            def active(path):
                if in_use(path) or object_borrowers(config['object_store_roots']).get(str((path / '.git/objects').resolve())):
                    return True
                try:
                    with lane.state_lock(fdir):
                        retention.check_live(fdir, tree, owner, receipt)
                except retention.f.FlowError:
                    return True
                return False
            results.append(offload(root, tree, config, active))
        except (OSError, ValueError, subprocess.SubprocessError, retention.f.FlowError) as error:
            results.append(dict(path=str(tree), error=str(error), mac_deleted=False))
        finally:
            if reservation.is_file():
                with lane.state_lock(fdir):
                    value = lane.read(reservation)
                    value['active'] = False
                    lane.write(reservation, value)
    return results


def automatic(root, in_use=lambda path: False, config_path=None, fdir=None):
    config_path = Path(os.environ.get('SR_COLD_STORAGE_CONFIG', config_path or Path(root) / '.local/cold-storage.json'))
    if not config_path.is_file():
        return []
    config = json.loads(config_path.read_text())
    results = []
    for base in config.get('archives', [str(Path(root) / '.local/archive/cleanup')]):
        base = Path(base)
        if base.is_symlink():
            continue
        for path in sorted(base.glob('*')):
            receipt = path / 'receipt.json'
            if path.is_symlink() or not receipt.is_file():
                continue
            row = json.loads(receipt.read_text())
            eligible = row.get('removed') or (config.get('include_failed_archives')
                and row.get('removed') is False and bool(row.get('tree')))
            if not eligible or time.time() - receipt.stat().st_mtime < config.get('min_age_seconds', 3600):
                continue
            try:
                results.append(offload(root, path, config, in_use))
            except (OSError, ValueError, subprocess.SubprocessError) as error:
                results.append(dict(path=str(path), error=str(error), mac_deleted=False))
    if fdir is not None:
        results.extend(finished_stores(root, fdir, config, in_use))
    return results
