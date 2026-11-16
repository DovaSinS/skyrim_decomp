"""Owned temporary index exports; dead exporters cannot leave full checkouts indefinitely."""
from contextlib import contextmanager
import file_lock as fcntl
import json
from pathlib import Path
import shutil
import tempfile


def reap(root):
    base = Path(root) / '.local/check-exports'
    base.mkdir(parents=True, exist_ok=True)
    removed = []
    # Serialize reapers: Windows requires closing the owner's handle before removal.
    with (base / '.reap.lock').open('a') as reaper:
        fcntl.flock(reaper, fcntl.LOCK_EX)
        for slot in base.glob('export-*'):
            if slot.is_symlink() or not (slot / 'owner.json').is_file():
                continue
            if json.loads((slot / 'owner.json').read_text()) != {'kind': 'staged-index-export', 'schema': 1}:
                continue
            if (slot / 'owner.lock').is_symlink():
                continue
            with (slot / 'owner.lock').open('a') as handle:
                try:
                    fcntl.flock(handle, fcntl.LOCK_EX | fcntl.LOCK_NB)
                except BlockingIOError:
                    continue
            shutil.rmtree(slot)
            removed.append(str(slot))
    return removed


@contextmanager
def directory(root):
    reap(root)
    base = Path(root) / '.local/check-exports'
    slot = Path(tempfile.mkdtemp(prefix='export-', dir=base))
    try:
        with (slot / 'owner.lock').open('a') as handle:
            fcntl.flock(handle, fcntl.LOCK_EX)
            (slot / 'owner.json').write_text(json.dumps(dict(kind='staged-index-export', schema=1)))
            tree = slot / 'tree'
            tree.mkdir()
            yield str(tree)
    finally:
        reap(root)
