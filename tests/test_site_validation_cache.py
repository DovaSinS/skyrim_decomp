"""Site cache reuse requires a new complete publication scan and exact-content validation."""
import json
import os
from pathlib import Path
import sys
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import build_site as site
import check
from test_revision_cache import RevisionTests as _Fixture

setup, git, write = _Fixture.setUp, _Fixture.git, _Fixture.write
del _Fixture


class SiteCache(unittest.TestCase):
    setUp, git, write = setup, git, write

    def test_unchanged_content_reuses_metadata_but_always_scans_publication(self):
        with patch.object(site, 'ROOT', self.root), patch.object(check, 'ROOT', self.root), \
                patch.object(check, '_load_uncached', return_value={'checked': True}) as load, \
                patch.object(site, 'check_git', wraps=check.check_git) as scan:
            self.assertEqual(site.validated_data(), {'checked': True})
            self.assertEqual(site.validated_data(), {'checked': True})
            self.assertEqual(load.call_count, 1)
            self.assertEqual(scan.call_count, 2)

    def test_changed_source_tools_recipe_metadata_or_ignored_context_revalidates_and_never_caches_failure(self):
        for path in ['reconstruction/a/A.h', 'tools/tool.py', 'reconstruction/recipes/test.json',
                     'data/progress.json', 'reports/synthetic.json', 'reconstruction/a/Extra.ignored.h']:
            with self.subTest(path=path), patch.object(site, 'ROOT', self.root), \
                    patch.object(check, 'ROOT', self.root), \
                    patch.object(check, '_load_uncached', return_value={'checked': path}) as load:
                site.validated_data()
                self.write(path, '// changed synthetic input\n')
                load.side_effect = ValueError('synthetic gate refusal')
                for _ in range(2):
                    with self.assertRaisesRegex(ValueError, 'gate refusal'):
                        site.validated_data()
                self.assertEqual(load.call_count, 3)

    def test_hidden_worktree_edit_and_changed_private_policy_still_refuse(self):
        with patch.object(site, 'ROOT', self.root), patch.object(check, 'ROOT', self.root), \
                patch.object(check, '_load_uncached', return_value={'checked': True}) as load:
            site.validated_data()
            self.git('update-index', '--assume-unchanged', 'reconstruction/a/A.h')
            self.write('reconstruction/a/A.h', '// hidden changed header\n')
            self.assertEqual(self.git('diff', '--name-only'), '')
            load.side_effect = ValueError('synthetic changed unit')
            with self.assertRaisesRegex(ValueError, 'changed unit'):
                site.validated_data()
            self.assertEqual(load.call_count, 2)
            self.write('.local/publication-forbidden.json', json.dumps({'forbidden_strings': ['hidden changed']}))
            with self.assertRaisesRegex(ValueError, 'Private workflow guard'):
                site.validated_data()
            self.assertEqual(load.call_count, 2, 'privacy scan must precede cached metadata or diagnostics')

    def test_corrupt_cache_is_a_miss_and_binary_or_symlink_still_refuses(self):
        with patch.object(site, 'ROOT', self.root), patch.object(check, 'ROOT', self.root), \
                patch.object(check, '_load_uncached', return_value={'checked': True}) as load:
            site.validated_data()
            for path in (self.root / '.local/revision-cache/metadata').glob('*.json'):
                path.write_text('not JSON')
            site.validated_data()
            self.assertEqual(load.call_count, 2)
            target = self.root / 'reconstruction/a/A.h'
            target.write_bytes(b'private\0binary')
            with self.assertRaisesRegex(ValueError, 'binary content'):
                site.validated_data()
            target.unlink()
            target.symlink_to('A.cpp')
            with self.assertRaisesRegex(ValueError, 'missing file/symlink'):
                site.validated_data()
            self.assertEqual(load.call_count, 2)


if __name__ == '__main__':
    unittest.main()
