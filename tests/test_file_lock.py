"""Cross-process exclusion and kernel release; original synthetic payloads only."""
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import file_lock as lock


class FileLock(unittest.TestCase):
    def test_nonblocking_lock_excludes_child_and_release_preserves_payload(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / 'payload'; path.write_bytes(b'original synthetic payload')
            code = ('import sys;sys.path.insert(0,sys.argv[1]);import file_lock as f;'
                    'h=open(sys.argv[2],"a");f.flock(h,f.LOCK_EX|f.LOCK_NB)')
            args = [sys.executable, '-c', code, str(Path(lock.__file__).parent), str(path)]
            with path.open('a') as handle:
                lock.flock(handle, lock.LOCK_EX)
                child = subprocess.run(args, capture_output=True)
                self.assertNotEqual(child.returncode, 0)
                self.assertIn(b'BlockingIOError', child.stderr)
                lock.flock(handle, lock.LOCK_UN)
                self.assertEqual(subprocess.run(args, capture_output=True).returncode, 0)
            self.assertEqual(path.read_bytes(), b'original synthetic payload')

    def test_abrupt_process_exit_releases_empty_file_lock(self):
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp) / 'empty'; path.touch()
            code = ('import os,sys;sys.path.insert(0,sys.argv[1]);import file_lock as f;'
                    'h=open(sys.argv[2],"a");f.flock(h,f.LOCK_EX);os._exit(0)')
            subprocess.run([sys.executable, '-c', code, str(Path(lock.__file__).parent), str(path)], check=True)
            with path.open('a') as handle:
                lock.flock(handle, lock.LOCK_EX | lock.LOCK_NB)
            self.assertEqual(path.read_bytes(), b'')
