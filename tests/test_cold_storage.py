"""Synthetic archive transport; no real host, account, private inputs or network."""
import json
from pathlib import Path
import shutil
import subprocess
import sys
import tarfile
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import cold_storage as cold


class ColdStorage(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.archive = self.root / '.local/archive/cleanup/fixture'
        self.archive.mkdir(parents=True)
        (self.archive / 'evidence').write_text('synthetic evidence\n')
        (self.archive / 'receipt.json').write_text(json.dumps(dict(removed=True)))
        self.remote = self.root / 'remote.tar.gz'
        self.config = dict(directory='D:/fixture/cold', host='fixture@example.test',
                           mkdir=['fixture-mkdir'], copy=['fixture-copy'],
                           hash=['fixture-hash', '{path}'], min_age_seconds=0)

    def transport(self, args, **kwargs):
        if args[0] == 'fixture-copy':
            shutil.copyfile(args[1], self.remote)
        return subprocess.CompletedProcess(args, 0,
            stdout=cold.digest(self.remote) if args[0] == 'fixture-hash' else '', stderr='')

    def test_verified_archive_restores_and_manifest_precedes_deletion(self):
        original = shutil.rmtree
        def remove(path, *args, **kwargs):
            if Path(path) == self.archive:
                value = json.loads((self.root / '.local/offload-manifest.json').read_text())
                self.assertFalse(value['items'][-1]['mac_deleted'])
                self.assertEqual(value['items'][-1]['sha256'], cold.digest(self.remote))
            return original(path, *args, **kwargs)
        with patch.object(cold.subprocess, 'run', side_effect=self.transport), patch.object(cold.shutil, 'rmtree', side_effect=remove):
            item = cold.offload(self.root, self.archive, self.config)
        self.assertTrue(item['mac_deleted'])
        self.assertFalse(item['quarantined'])
        self.assertGreater(item['size_bytes'], 0)
        self.assertFalse(self.archive.exists())
        with tarfile.open(self.remote) as package:
            self.assertEqual(package.extractfile('fixture/evidence').read(), b'synthetic evidence\n')

    def test_hash_failure_retains_original_without_success_manifest(self):
        def bad(args, **kwargs):
            return subprocess.CompletedProcess(args, 0, stdout='0' * 64, stderr='')
        with patch.object(cold.subprocess, 'run', side_effect=bad), self.assertRaisesRegex(ValueError, 'SHA-256 mismatch'):
            cold.offload(self.root, self.archive, self.config)
        self.assertTrue((self.archive / 'evidence').is_file())
        self.assertFalse((self.root / '.local/offload-manifest.json').exists())

    def test_child_change_during_transport_retains_original(self):
        def changed(args, **kwargs):
            result = self.transport(args, **kwargs)
            if args[0] == 'fixture-hash':
                (self.archive / 'evidence').write_text('changed fixture\n')
            return result
        with patch.object(cold.subprocess, 'run', side_effect=changed), self.assertRaisesRegex(ValueError, 'changed'):
            cold.offload(self.root, self.archive, self.config)
        self.assertTrue(self.archive.exists())

    def test_new_live_reference_retains_original(self):
        calls = iter([False, True])
        with patch.object(cold.subprocess, 'run', side_effect=self.transport), self.assertRaisesRegex(ValueError, 'active'):
            cold.offload(self.root, self.archive, self.config, lambda _: next(calls))
        self.assertTrue(self.archive.exists())

    def test_automatic_only_offloads_successful_cold_receipts(self):
        config = self.root / '.local/cold-storage.json'
        config.write_text(json.dumps(self.config))
        failed = self.archive.parent / 'failed'
        failed.mkdir()
        (failed / 'receipt.json').write_text(json.dumps(dict(removed=False)))
        with patch.object(cold.subprocess, 'run', side_effect=self.transport):
            result = cold.automatic(self.root)
        self.assertEqual(len(result), 1)
        self.assertTrue(result[0]['mac_deleted'])
        self.assertTrue(failed.exists())

    def test_explicit_legacy_mode_offloads_completed_failed_copy_not_original(self):
        original = self.root / 'original-dirty'
        original.mkdir()
        (original / 'keep').write_text('uncommitted synthetic work')
        (self.archive / 'receipt.json').write_text(json.dumps(dict(removed=False, tree=str(original))))
        config = self.root / '.local/cold-storage.json'
        config.write_text(json.dumps(dict(self.config, include_failed_archives=True)))
        with patch.object(cold.subprocess, 'run', side_effect=self.transport):
            result = cold.automatic(self.root)
        self.assertEqual(len(result), 1)
        self.assertTrue(result[0]['mac_deleted'])
        self.assertEqual((original / 'keep').read_text(), 'uncommitted synthetic work')

    def test_store_offload_keeps_borrowed_objects_and_all_refs(self):
        import flow_lane as lane
        fdir = self.root / '.local/flow'
        tree = fdir / 'lane/trees/finished/0'
        tree.mkdir(parents=True)
        subprocess.run(['git', 'init', '--quiet', str(tree)], check=True)
        (tree / 'fixture').write_text('original synthetic')
        for args in [('add', 'fixture'), ('-c', 'user.name=Fixture', '-c', 'user.email=fixture@example.test',
                                        'commit', '--quiet', '-m', 'fixture')]:
            subprocess.run(['git', '-C', str(tree), *args], check=True)
        (tree / 'fixture').unlink()
        lane.write(fdir / 'lane/runs/finished.json', dict(id='finished', state='done', integrated=None))
        borrower = self.root / 'borrower'
        subprocess.run(['git', 'clone', '--quiet', '--shared', str(tree), str(borrower)], check=True)
        config = dict(self.config, object_store_roots=[str(self.root)])
        self.assertEqual(cold.finished_stores(self.root, fdir, config, lambda _: False), [])
        shutil.rmtree(borrower)
        with patch.object(cold.subprocess, 'run', side_effect=self.transport):
            rows = cold.finished_stores(self.root, fdir, config, lambda _: False)
        self.assertEqual(len(rows), 1)
        self.assertTrue(rows[0]['mac_deleted'])
        self.assertFalse(tree.exists())
        with tarfile.open(self.remote) as package:
            self.assertTrue(any(name.endswith('/.git/HEAD') for name in package.getnames()))

    def test_no_config_is_opt_in_and_symlink_is_never_traversed(self):
        self.assertEqual(cold.automatic(self.root), [])
        link = self.archive.parent / 'link'
        link.symlink_to(self.archive, target_is_directory=True)
        with self.assertRaisesRegex(ValueError, 'symlinked'):
            cold.offload(self.root, link, self.config)
        self.assertTrue(self.archive.exists())
