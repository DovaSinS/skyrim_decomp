"""Snapshot invalidation, trusted head lint context and affected-unit lookup; synthetic sources."""
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

TOOLS = Path(__file__).resolve().parents[1] / 'tools'
sys.path.insert(0, str(TOOLS))
import revision_cache as cache
import git_context
import ci_target_hash_check as ci
import check


class RevisionTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        self.git('init', '-q')
        self.git('config', 'user.name', 'Synthetic Tester')
        self.git('config', 'user.email', 'tester@example.invalid')
        self.write('.gitignore', '.local/\n')
        self.write('reconstruction/a/A.cpp', '#include "A.h"\n')
        self.write('reconstruction/a/A.h', '// synthetic header\n')
        self.write('reconstruction/b/B.cpp', '#include "B.h"\n')
        self.write('reconstruction/b/B.h', '// independent header\n')
        self.write('tools/tool.py', '# synthetic tool\n')
        self.git('add', '.')
        self.git('commit', '-qm', 'synthetic baseline')

    def git(self, *args):
        return subprocess.check_output(['git', *args], cwd=self.root).decode().strip()

    def write(self, name, text):
        path = self.root / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text)

    def test_working_staged_tools_and_untracked_evidence_invalidate(self):
        start = cache.snapshot(self.root)
        self.assertEqual(start, cache.snapshot(self.root, staged=True))
        self.write('reconstruction/a/A.h', '// changed header\n')
        working = cache.snapshot(self.root)
        self.assertNotEqual(start, working)
        self.assertEqual(start, cache.snapshot(self.root, staged=True))
        self.git('add', 'reconstruction/a/A.h')
        staged = cache.snapshot(self.root, staged=True)
        self.assertNotEqual(start, staged)
        self.assertEqual(staged, cache.snapshot(self.root))
        self.write('findings/new.md', 'new untracked evidence\n')
        self.assertNotEqual(staged, cache.snapshot(self.root))
        self.assertEqual(staged, cache.snapshot(self.root, staged=True))
        self.write('tools/tool.py', '# changed checker\n')
        self.assertNotEqual(staged, cache.snapshot(self.root, staged=True))

    def test_ignored_public_header_changes_invalidate_working_snapshot(self):
        self.write('.git/info/exclude', '*.ignored.h\n')
        start = cache.snapshot(self.root)
        self.write('reconstruction/a/Extra.ignored.h', '// ignored header\n')
        created = cache.snapshot(self.root)
        self.assertNotEqual(start, created)
        self.write('reconstruction/a/Extra.ignored.h', '// ignored header changed\n')
        self.assertNotEqual(created, cache.snapshot(self.root))

    def test_metadata_success_reused_but_changed_input_and_failure_rechecked(self):
        with patch.object(check, 'ROOT', self.root), patch.object(check, '_load_uncached', return_value={'checked': True}) as load:
            self.assertEqual(check.load(publication_revision='synthetic-publication-scan'), {'checked': True})
            self.assertEqual(check.load(publication_revision='synthetic-publication-scan'), {'checked': True})
            self.assertEqual(load.call_count, 1)
            self.write('reconstruction/a/A.h', '// invalid modification\n')
            load.side_effect = ValueError('synthetic gate refusal')
            for _ in range(2):
                with self.assertRaisesRegex(ValueError, 'gate refusal'):
                    check.load(publication_revision='synthetic-publication-scan')
            self.assertEqual(load.call_count, 3)

    def test_publication_content_key_does_not_trust_git_stat_or_assume_unchanged(self):
        revisions = []
        check.check_git(self.root, content_revision=revisions)
        self.git('update-index', '--assume-unchanged', 'reconstruction/a/A.h')
        self.write('reconstruction/a/A.h', '// changed source hidden from git diff\n')
        self.assertEqual(self.git('diff', '--name-only'), '')
        check.check_git(self.root, content_revision=revisions)
        self.assertNotEqual(revisions[0], revisions[1])

    def test_staged_scan_cache_binds_index_tools_and_current_private_denylist(self):
        self.assertEqual(check.check_git(self.root, staged=True), 6)
        with patch.object(check, 'index_blob', side_effect=AssertionError('unnecessary blob reread')):
            self.assertEqual(check.check_git(self.root, staged=True), 6)
        self.write('.local/anonymity.json', json.dumps({'forbidden_strings': ['synthetic header']}))
        with self.assertRaisesRegex(ValueError, 'Anonymous sibling guard'):
            check.check_git(self.root, staged=True)

    def test_staged_cache_rechecks_changed_private_workflow_policy(self):
        self.assertEqual(check.check_git(self.root, staged=True), 6)
        with patch.object(check, 'index_blob', side_effect=AssertionError('unexpected reread')):
            self.assertEqual(check.check_git(self.root, staged=True), 6)
        self.write('.local/publication-forbidden.json',
                   json.dumps({'forbidden_strings': ['synthetic header']}))
        with self.assertRaisesRegex(ValueError, 'Private workflow guard'):
            check.check_git(self.root, staged=True)

    def test_immutable_head_metadata_and_blobs_ignore_working_edits(self):
        first, entries = git_context.tree_entries(self.root, 'HEAD')
        self.write('reconstruction/a/A.h', '// uncommitted\n')
        second, again = git_context.tree_entries(self.root, 'HEAD')
        self.assertEqual((first, entries), (second, again))
        self.assertEqual(git_context.blobs(self.root, entries, ['reconstruction/a/A.h']),
                         {'reconstruction/a/A.h': b'// synthetic header\n'})
        self.git('add', 'reconstruction/a/A.h')
        self.git('commit', '-qm', 'new snapshot')
        self.assertNotEqual(first, git_context.tree_entries(self.root, 'HEAD')[0])

    def test_affected_index_reused_and_changed_includes_rebuild(self):
        header = 'reconstruction/a/A.h'
        expected = [{'unit': 'reconstruction/a/A.cpp', 'rva': None, 'symbol': None, 'recipe': ci.DEFAULT_RECIPE}]
        self.assertEqual(ci.requests(self.root, [header], {}), expected)
        with patch('check_source_digest.include_closure', side_effect=AssertionError('whole-tree rebuild')):
            self.assertEqual(ci.requests(self.root, [header], {}), expected)
        self.write('reconstruction/b/B.cpp', '#include "../a/A.h"\n')
        result = ci.requests(self.root, [header], {})
        self.assertEqual({r['unit'] for r in result}, {'reconstruction/a/A.cpp', 'reconstruction/b/B.cpp'})
        self.write('reconstruction/a/A.h', '#include "missing.h"\n')
        with self.assertRaises(ValueError):
            ci.requests(self.root, [header], {})

    def test_dependencies_never_materialize_absolute_or_parent_paths(self):
        sources = {'reconstruction/a/A.cpp': b'// Evidence: /tmp/private\n// Recipe: ../private\n#include </etc/passwd>\n'}
        names = git_context.lint_dependencies(sources)
        self.assertFalse(any(n.startswith('/') or '..' in Path(n).parts for n in names))


if __name__ == '__main__':
    unittest.main()
