"""Synthetic ownership locks, including an exporter that exited without Python cleanup."""
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import staged_exports


class StagedExports(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)

    def test_live_export_is_locked_and_normal_exit_cleans(self):
        with staged_exports.directory(self.root) as directory:
            tree = Path(directory)
            (tree / 'fixture').write_text('synthetic')
            self.assertEqual(staged_exports.reap(self.root), [])
            self.assertTrue(tree.is_dir())
        self.assertFalse(tree.exists())

    def test_abrupt_exit_is_reaped_without_touching_unowned_data(self):
        code = ('import sys,os;sys.path.insert(0,sys.argv[1]);import staged_exports;'
                'c=staged_exports.directory(sys.argv[2]);p=c.__enter__();'
                'open(p+"/fixture","w").write("synthetic");os._exit(0)')
        subprocess.run([sys.executable, '-c', code, str(Path(staged_exports.__file__).parent),
                        str(self.root)], check=True)
        other = self.root / '.local/check-exports/export-unowned'
        other.mkdir()
        (other / 'keep').write_text('user fixture')
        removed = staged_exports.reap(self.root)
        self.assertEqual(len(removed), 1)
        self.assertTrue((other / 'keep').exists())
        self.assertEqual(staged_exports.reap(self.root), [])
