"""Snapshot invalidation, trusted head lint context and affected-unit lookup; synthetic sources."""
import json
from concurrent.futures import ThreadPoolExecutor
import os
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
import validation_reads


class RevisionTests(unittest.TestCase):
    def setUp(self):
        # Each synthetic repository owns its policies; publisher settings belong to its parent.
        environment = patch.dict(os.environ)
        environment.start()
        self.addCleanup(environment.stop)
        for name in ('SR_ANONYMITY_CONFIG', 'SR_PUBLICATION_FORBIDDEN_CONFIG', 'SR_LOCAL_DIR'):
            os.environ.pop(name, None)
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        self.git('init', '-q')
        self.git('config', 'user.name', 'Synthetic Tester')
        self.git('config', 'user.email', 'tester@example.invalid')
        self.git('config', 'core.autocrlf', 'false')
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
        path.write_text(text, encoding='utf-8', newline='\n')

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

    def test_explicit_policy_still_invalidates_a_cached_scan(self):
        self.assertEqual(check.check_git(self.root, staged=True), 6)
        policy = self.root / '.local/caller-policy.json'
        self.write('.local/caller-policy.json', json.dumps({'forbidden_strings': ['synthetic header']}))
        with patch.dict(os.environ, SR_ANONYMITY_CONFIG=str(policy)):
            with self.assertRaisesRegex(ValueError, 'Anonymous sibling guard'):
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

    def test_blob_hits_scan_only_new_content_and_bind_path_mode_tools_and_policy(self):
        with patch.object(check, 'inspect_payload', wraps=check.inspect_payload) as scan:
            check.check_git(self.root)
            self.assertEqual(scan.call_count, 6)  # identical index/disk bytes scanned once
            scan.reset_mock()
            with patch.object(check, 'index_blob', side_effect=AssertionError('cached blob reread')):
                check.check_git(self.root)
            scan.assert_not_called()
            self.write('reconstruction/a/A.h', '// new working content\n')
            check.check_git(self.root)
            self.assertEqual(scan.call_count, 1)
            self.git('add', 'reconstruction/a/A.h')
            scan.reset_mock()
            check.check_git(self.root)
            scan.assert_not_called()  # same successfully scanned working blob is now indexed
            self.git('update-index', '--chmod=+x', 'reconstruction/a/A.h')
            check.check_git(self.root)
            self.assertEqual(scan.call_count, 1)
            self.git('mv', 'reconstruction/a/A.h', 'reconstruction/a/Renamed.h')
            scan.reset_mock()
            check.check_git(self.root)
            self.assertEqual(scan.call_count, 1)
            self.write('tools/tool.py', '# scanner dependency edit\n')
            scan.reset_mock()
            check.check_git(self.root)
            self.assertEqual(scan.call_count, 7)  # six index blobs and changed tool on disk
            self.write('.local/anonymity.json', '{"forbidden_strings": ["synthetic-unused-denial"]}')
            scan.reset_mock()
            check.check_git(self.root)
            self.assertEqual(scan.call_count, 7)
            # Exact policy bytes matter, even when its parsed terms have not changed.
            self.write('.local/anonymity.json', '{ "forbidden_strings": ["synthetic-unused-denial"] }')
            scan.reset_mock()
            check.check_git(self.root)
            self.assertEqual(scan.call_count, 7)

    def test_disk_tamper_same_size_restored_mtime_and_assume_unchanged_is_scanned(self):
        check.check_git(self.root)
        path = self.root / 'reconstruction/a/A.h'
        stamp = path.stat()
        original = path.read_bytes()
        self.git('update-index', '--assume-unchanged', 'reconstruction/a/A.h')
        path.write_bytes(b'\0' + original[1:])
        os.utime(path, ns=(stamp.st_atime_ns, stamp.st_mtime_ns))
        for _ in range(2):
            with self.assertRaisesRegex(ValueError, 'binary content'):
                check.check_git(self.root)

    def test_working_symlink_and_index_symlink_never_hit_a_regular_file_memo(self):
        check.check_git(self.root)
        path = self.root / 'reconstruction/a/A.h'
        path.unlink()
        path.symlink_to('../b/B.h')
        with self.assertRaisesRegex(ValueError, 'missing file/symlink'):
            check.check_git(self.root)
        self.git('add', 'reconstruction/a/A.h')
        for staged in (True, False):
            with self.assertRaisesRegex(ValueError, 'symlink/submodule not approved'):
                check.check_git(self.root, staged=staged)

    def test_failed_scan_commits_no_blob_additions_or_index_success(self):
        self.write('z-bad.txt', '\0')
        self.git('add', 'z-bad.txt')
        for _ in range(2):
            with patch.object(check, 'inspect_payload', wraps=check.inspect_payload) as scan:
                with self.assertRaisesRegex(ValueError, 'binary content'):
                    check.check_git(self.root, staged=True)
                self.assertEqual(scan.call_count, 7)

    def test_shared_cache_reused_by_separate_clone_and_atomic_concurrent_writers(self):
        shared = self.root / '.local/shared-cache'
        self.git('config', 'skyrim.revisionCacheDirectory', str(shared))
        check.check_git(self.root, staged=True)
        clone = self.root / '.local/clone'
        self.git('clone', '--quiet', '--shared', '--config', 'core.autocrlf=false', str(self.root), str(clone))
        subprocess.check_call(['git', 'config', 'skyrim.revisionCacheDirectory', str(shared)], cwd=clone)
        with patch.object(check, 'index_blob', side_effect=AssertionError('clone missed shared result')):
            self.assertEqual(check.check_git(clone, staged=True), 6)

        def writer(number):
            memo = cache.BlobMemo(self.root, 'synthetic-context')
            memo.put(str(number), 'a' * 64)
            memo.commit()
            for _ in range(5):
                cache.save(self.root, 'concurrent', 'same-key', {'writer': number, 'padding': 'x' * 10000})
                saved = cache.read(self.root, 'concurrent', 'same-key')
                # Windows can refuse to open/replace a file while another reader owns it.
                # That is a conservative miss; a reader must never observe partial JSON.
                if saved is not None:
                    self.assertEqual(saved['padding'], 'x' * 10000)
        with ThreadPoolExecutor(max_workers=8) as pool:
            list(pool.map(writer, range(16)))
        self.assertEqual(len(cache.BlobMemo(self.root, 'synthetic-context').saved), 16)
        self.assertEqual(cache.read(self.root, 'concurrent', 'same-key')['padding'], 'x' * 10000)
        self.assertEqual(list((shared / 'concurrent').glob('*')), [shared / 'concurrent/same-key.json'])

    def test_cached_and_cold_scans_have_identical_results_and_diagnostics(self):
        def result(staged, cold):
            revisions = []
            with patch.object(cache, 'read', return_value=None) if cold else patch.object(cache, 'read', wraps=cache.read):
                with patch.object(cache.BlobMemo, 'get', return_value=None) if cold else patch.object(cache.BlobMemo, 'get', autospec=True, side_effect=cache.BlobMemo.get):
                    try:
                        return check.check_git(self.root, staged=staged, content_revision=revisions), revisions
                    except ValueError as error:
                        return type(error).__name__, str(error)
        for payload in ('// harmless working change\n', '\0', '\udcff', 'version https://git-lfs.github.com/spec/v1\n'):
            with self.subTest(payload=repr(payload)):
                check.check_git(self.root, staged=True)
                (self.root / 'reconstruction/a/A.h').write_bytes(payload.encode('utf-8', 'surrogateescape'))
                for staged in (False, True):
                    self.assertEqual(result(staged, False), result(staged, True))
        self.write('.local/publication-forbidden.json', '{"forbidden_strings": ["synthetic header"]}')
        self.assertEqual(result(True, False), result(True, True))

    def test_metadata_key_invalidates_on_policy_mode_ignored_and_untracked_inputs(self):
        with patch.object(check, 'ROOT', self.root), patch.object(check, '_load_uncached', return_value={'pass': True}) as load:
            def expect_new():
                before = load.call_count
                check.load(publication_revision='synthetic')
                check.load(publication_revision='synthetic')
                self.assertEqual(load.call_count, before + 1)
            expect_new()
            self.write('.local/anonymity.json', '{"forbidden_strings": ["synthetic-unused-denial"]}')
            expect_new()
            self.git('update-index', '--chmod=+x', 'reconstruction/a/A.h')
            expect_new()
            self.write('.git/info/exclude', '*.ignored.h\n')
            self.write('reconstruction/a/Extra.ignored.h', '// ignored\n')
            expect_new()
            self.write('reconstruction/a/Extra.ignored.h', '// ignored changed\n')
            expect_new()
            self.write('findings/untracked.md', 'synthetic untracked context\n')
            expect_new()

    def test_read_once_scope_reuses_bytes_and_expires_on_edit_and_next_load(self):
        path = self.root / 'reconstruction/a/A.h'
        original = Path.read_bytes
        reads = []
        def read(p):
            reads.append(p)
            return original(p)
        with patch.object(Path, 'read_bytes', read):
            with validation_reads.read_once():
                self.assertEqual(validation_reads.read_bytes(path), validation_reads.read_text(path).encode())
                self.assertEqual(len(reads), 1)
                self.write('reconstruction/a/A.h', '// edit within load\n')
                self.assertEqual(validation_reads.read_bytes(path), b'// edit within load\n')
                self.assertEqual(len(reads), 2)
            with validation_reads.read_once():
                validation_reads.read_bytes(path)
                self.assertEqual(len(reads), 3)

    def test_load_owns_a_fresh_read_once_scope_and_preserves_failure(self):
        def validate(data, target):
            path = self.root / 'builds/target.json'
            self.assertIsNotNone(validation_reads._READS.get())
            check.file_sha256(self.root, 'builds/target.json')
            self.assertIn(path.absolute(), validation_reads._READS.get())
            raise ValueError('synthetic validation refusal')
        self.write('data/progress.json', '{}')
        self.write('builds/target.json', '{}')
        for _ in range(2):
            with patch.object(check, 'ROOT', self.root), patch.object(check, 'validate', side_effect=validate):
                with self.assertRaisesRegex(ValueError, 'synthetic validation refusal'):
                    check.load()
            self.assertIsNone(validation_reads._READS.get())

    def test_ignored_symlink_target_is_part_of_revision_identity(self):
        self.write('.git/info/exclude', '*.ignored.h\n')
        path = self.root / 'reconstruction/a/A.ignored.h'
        path.symlink_to('A.h')
        before = cache.snapshot(self.root)
        path.unlink()
        path.symlink_to('../b/B.h')
        self.assertNotEqual(before, cache.snapshot(self.root))

    def test_unavailable_or_corrupt_memo_is_only_a_cache_miss(self):
        path = cache.directory(self.root) / 'publication-blobs.sqlite3'
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(b'synthetic corrupt cache')
        self.assertEqual(check.check_git(self.root), 6)
        with patch.object(cache, 'directory', return_value=path):
            self.assertEqual(check.check_git(self.root), 6)

    def test_concurrent_processes_merge_blob_entries_atomically(self):
        code = '''import sys
from pathlib import Path
sys.path.insert(0, sys.argv[1])
import revision_cache
root, number = Path(sys.argv[2]), sys.argv[3]
memo = revision_cache.BlobMemo(root, 'processes')
memo.put(number, 'a' * 64)
memo.commit()
revision_cache.save(root, 'processes', 'shared', {'writer': number, 'payload': 'x' * 50000})
'''
        processes = [subprocess.Popen([sys.executable, '-c', code, str(TOOLS), str(self.root), str(number)],
                                      stdout=subprocess.PIPE, stderr=subprocess.PIPE) for number in range(4)]
        for process in processes:
            out, err = process.communicate(timeout=60)
            self.assertEqual(process.returncode, 0, (out, err))
        self.assertEqual(set(cache.BlobMemo(self.root, 'processes').saved), {'0', '1', '2', '3'})
        self.assertEqual(cache.read(self.root, 'processes', 'shared')['payload'], 'x' * 50000)

    def test_runtime_and_loaded_scanner_identity_invalidate_shared_results(self):
        check.check_git(self.root, staged=True)
        first = cache.snapshot(self.root)
        for name in ('runtime_digest', 'TOOLS_AT_IMPORT'):
            replacement = patch.object(cache, name, return_value=b'different runtime') if name == 'runtime_digest' else patch.object(cache, name, b'different loaded code')
            with replacement, patch.object(check, 'inspect_payload', wraps=check.inspect_payload) as scan:
                self.assertNotEqual(first, cache.snapshot(self.root))
                check.check_git(self.root, staged=True)
                self.assertEqual(scan.call_count, 6)

    def test_sha1_collision_cannot_hide_changed_working_bytes(self):
        check.check_git(self.root)
        name = 'reconstruction/a/A.h'
        blob = self.git('rev-parse', ':' + name)
        path = self.root / name
        path.write_bytes(b'\0' + path.read_bytes()[1:])
        # Force the dirty bytes to have the indexed Git id. SHA-256 must still distinguish
        # them and the publication scanner must reject them on every attempt.
        with patch.object(check.hashlib, 'new') as object_hash:
            object_hash.return_value.hexdigest.return_value = blob
            for _ in range(2):
                with self.assertRaisesRegex(ValueError, 'binary content'):
                    check.check_git(self.root)


if __name__ == '__main__':
    unittest.main()
