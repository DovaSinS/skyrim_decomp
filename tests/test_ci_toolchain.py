"""Verified toolchain caches use original synthetic bytes, never actual compiler payloads."""
import contextlib
import hashlib
import io
import json
from pathlib import Path
import shutil
import sys
import tempfile
import unittest
from unittest.mock import patch

ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'tools'))
import ci_toolchain as c

class ToolchainCache(unittest.TestCase):
    def setUp(self):
        self.temp=tempfile.TemporaryDirectory();self.addCleanup(self.temp.cleanup)
        self.repo=Path(self.temp.name)/'repo';self.repo.mkdir()
        (self.repo/'tools/verifier').mkdir(parents=True)
        (self.repo/'tools/toolchain').mkdir()
        self.tree=Path(self.temp.name)/'tree';(self.tree/c.VC/'bin/Hostx64/x64').mkdir(parents=True)
        pins=[]
        for name in ('cl.exe','c1xx.dll','c2.dll','link.exe'):
            data=('synthetic '+name).encode();(self.tree/c.VC/'bin/Hostx64/x64'/name).write_bytes(data)
            pins.append(hashlib.sha256(data).hexdigest()+'  '+name)
        (self.repo/'tools/verifier/pinned.sha256').write_text('\n'.join(pins)+'\n')
        (self.repo/c.PLAN).write_text('{}\n')
        self.header=self.tree/c.SDK/'Include/10.0.19041.0/um/Synthetic.h'
        self.header.parent.mkdir(parents=True);self.header.write_text('// original synthetic header\n')
        c.write_manifest(self.repo,self.tree)

    def test_full_manifest_rejects_header_tamper_even_when_four_pins_still_match(self):
        self.assertTrue(c.verify(self.repo,self.tree))
        self.header.write_text('// changed header\n')
        self.assertTrue(c.verify_pins(self.repo,self.tree))
        self.assertFalse(c.verify(self.repo,self.tree))

    def test_missing_extra_and_changed_compiler_are_rejected(self):
        extra=self.tree/'unexpected.txt';extra.write_text('extra')
        self.assertFalse(c.verify(self.repo,self.tree));extra.unlink()
        self.header.unlink();self.assertFalse(c.verify(self.repo,self.tree))
        self.header.write_text('// original synthetic header\n')
        (self.tree/c.VC/'bin/Hostx64/x64/cl.exe').write_text('different compiler')
        self.assertFalse(c.verify(self.repo,self.tree))

    def test_cached_manifest_cannot_authorize_mutated_files(self):
        self.header.write_text('// poison')
        (self.tree/'v141-manifest.json').write_text(json.dumps(c.files(self.tree)))
        self.assertFalse(c.verify(self.repo,self.tree))
        (self.repo/'tools/toolchain/v141-files-000.json').write_text('{}')
        self.assertFalse(c.verify(self.repo,self.tree))

    def test_hit_verifies_and_corruption_discards_then_fetches_fresh(self):
        pristine=Path(self.temp.name)/'pristine';shutil.copytree(self.tree,pristine)
        def fetch(repo,tree,scratch):shutil.copytree(pristine,tree)
        with patch.object(c,'ROOT',self.repo),patch.object(c,'fetch',side_effect=fetch)as fresh,contextlib.redirect_stdout(io.StringIO()):
            self.assertEqual(c.main(['setup','--root',str(self.tree)]),0);fresh.assert_not_called()
            self.header.write_text('// altered')
            self.assertEqual(c.main(['setup','--root',str(self.tree)]),0);fresh.assert_called_once()
            self.assertTrue(c.verify(self.repo,self.tree))

    def test_root_symlink_is_discarded_without_touching_target(self):
        alias=Path(self.temp.name)/'alias';alias.symlink_to(self.tree,target_is_directory=True)
        self.assertFalse(c.verify(self.repo,alias))
        with patch.object(c,'ROOT',self.repo),patch.object(c,'fetch',side_effect=lambda repo,tree,scratch:shutil.copytree(self.tree,tree)),contextlib.redirect_stdout(io.StringIO()):
            c.main(['setup','--root',str(alias)])
        self.assertFalse(alias.is_symlink());self.assertTrue(c.verify(self.repo,alias))
        self.assertTrue(self.header.is_file())

    def test_non_microsoft_urls_and_escaping_paths_are_refused(self):
        for url in ('http://download.microsoft.com/a','https://example.org/a'):
            with self.assertRaises(ValueError):c.download(url,self.tree/'bad','0'*64)
        for path in ('../a','/absolute','C:/outside'):
            with self.assertRaises(ValueError):c.safe_path(path)

if __name__=='__main__':unittest.main()
