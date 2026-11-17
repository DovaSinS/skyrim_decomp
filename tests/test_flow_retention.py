"""Working-copy retention uses tiny original repositories and private synthetic evidence."""
import fcntl
import json
import os
from pathlib import Path
import subprocess
import shutil
import sys
import tempfile
import time
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import flow_cleanup as retention
import flow_lane as lane


class ProcessPaths(unittest.TestCase):
    @unittest.skipUnless(os.path.isdir('/proc/self/fd'), '/proc file descriptors unavailable')
    def test_proc_fallback_finds_open_file(self):
        with tempfile.NamedTemporaryFile() as opened, patch.object(retention.shutil, 'which', return_value=None):
            self.assertTrue(retention.path_in_use(Path(opened.name), retention.process_paths()))


class Retention(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        self.base = Path(self.temporary.name).resolve()
        self.root = self.base / 'root'
        self.root.mkdir()
        self.fdir = self.root / '.local/flow'
        self.checkout(self.root)

    def git(self, tree, *args):
        return subprocess.run(['git', '-C', str(tree), *args], check=True,
                              capture_output=True, text=True).stdout.strip()

    def checkout(self, tree):
        tree.mkdir(parents=True, exist_ok=True)
        self.git(tree, 'init', '--quiet')
        self.git(tree, 'config', 'user.email', 'fixture@example.test')
        self.git(tree, 'config', 'user.name', 'Synthetic fixture')
        (tree / 'tracked').write_text('original fixture\n')
        self.git(tree, 'add', 'tracked')
        self.git(tree, 'commit', '--quiet', '-m', 'fixture')
        return tree

    def candidate(self, run='finished', attempt='0', **fields):
        tree = self.checkout(self.fdir / 'lane/trees' / run / attempt)
        receipt = dict(id=run, state='done', root=str(self.root), tree=str(tree), integrated=None)
        receipt.update(fields)
        path = self.fdir / 'lane/runs' / (run + '.json')
        lane.write(path, receipt)
        return tree, path

    def test_terminal_isolation_metadata_moves_once_but_borrowed_git_survives(self):
        tree, _ = self.candidate()
        snapshot = self.fdir / 'lane/isolation/finished'
        isolated = self.checkout(snapshot / 'lane/trees/finished/0')
        lane.write(snapshot / 'groups/frozen.json', dict(synthetic=True))
        rows = retention.automatic_retention(self.root, self.fdir)
        moved = [r for r in rows if r['tree'] == str(snapshot)]
        self.assertEqual(len(moved), 1)
        self.assertTrue((isolated / '.git').is_dir())
        self.assertFalse((snapshot / 'groups').exists())
        self.assertEqual(lane.read(Path(moved[0]['archive']) / 'files/groups/frozen.json'), dict(synthetic=True))
        self.assertEqual(retention.prune_isolation(self.root, self.fdir, ''), [])

    def test_live_process_protects_finished_candidate_and_isolation(self):
        tree, _ = self.candidate()
        with patch.object(retention, 'process_paths', return_value='123 worker --root ' + str(tree) + '/nested'):
            rows = retention.automatic_retention(self.root, self.fdir)
        self.assertFalse(rows[0]['removed'])
        self.assertIn('open process', rows[0]['reason'])
        self.assertTrue((tree / 'tracked').is_file())

    def test_broken_cold_config_preserves_successful_lane_outcome(self):
        tree, _ = self.candidate()
        with patch('cold_storage.automatic', side_effect=ValueError('synthetic bad config')):
            rows = retention.automatic_retention(self.root, self.fdir, offload=True)
        self.assertFalse((tree / 'tracked').exists())
        self.assertEqual(rows[-1]['cold_storage_error'], 'synthetic bad config')
        self.assertFalse(rows[-1]['removed'])

    def test_worker_archives_use_shared_flow_storage_not_worker_disk(self):
        tree, _ = self.candidate()
        worker = self.checkout(self.base / 'worker')
        row = retention.cleanup(worker, self.fdir)[0]
        self.assertTrue(row['removed'])
        self.assertTrue(Path(row['archive']).is_relative_to(self.fdir.parent / 'archive/cleanup'))
        self.assertFalse((worker / '.local/archive').exists())

    def test_automatic_removes_retries_and_isolation_keeps_evidence_and_git(self):
        old, receipt = self.candidate(attempt='0')
        new, _ = self.candidate(attempt='1')
        isolated = self.checkout(self.fdir / 'lane/isolation/finished-1/lane/trees/finished/0')
        evidence = old / '.local/private.evidence'
        evidence.parent.mkdir()
        evidence.write_text('original synthetic private evidence\n')
        (old / 'tracked').write_text('retained working change\n')
        self.git(old, 'update-ref', 'refs/retained/fixture', 'HEAD')
        refs = self.git(old, 'show-ref')
        before = receipt.read_bytes()
        result = retention.automatic_retention(self.root, self.fdir)
        removed = {r['tree']: r for r in result if r['removed']}
        self.assertEqual(set(removed), set(map(str, (old, new, isolated))))
        archive = Path(removed[str(old)]['archive'])
        self.assertEqual((archive / 'files/.local/private.evidence').read_text(), 'original synthetic private evidence\n')
        self.assertIn('retained working change', (archive / 'working-changes.patch').read_text())
        self.assertEqual(self.git(old, 'show-ref'), refs)
        self.assertEqual(receipt.read_bytes(), before)
        self.assertTrue((self.fdir / 'cleanup/last-retention.json').is_file())
        self.assertEqual(retention.automatic_retention(self.root, self.fdir), [])

    def test_real_finish_hook_releases_owner_and_removes_completed_copy(self):
        tree, path = self.candidate(state='running', branch='main', items=[], accepted=[],
            integrated=dict(ci='green', pushed='fixture', commit='a' * 40))
        original = retention.f.git
        def git_without_network(root, *args, **kwargs):
            if args[0] == 'fetch':
                return ''
            return original(root, *args, **kwargs)
        with patch.object(retention.f, 'git', side_effect=git_without_network):
            result = lane.finish_run(self.root, self.fdir, lane.read(path), sys.executable, 0)
        self.assertEqual(result['state'], 'done')
        self.assertIsNone(result['owner'])
        self.assertTrue(result['finished_owner'])
        self.assertFalse((tree / 'tracked').exists())
        self.assertTrue((tree / '.git').is_dir())

    def test_automatic_busy_lock_returns_without_receipt_and_retries(self):
        tree, _ = self.candidate()
        directory = self.fdir / 'cleanup'
        directory.mkdir()
        with (directory / '.cleanup.lock').open('a') as owner:
            fcntl.flock(owner, fcntl.LOCK_EX | fcntl.LOCK_NB)
            started = time.monotonic()
            with patch.object(retention, 'process_paths', side_effect=AssertionError('busy lock must precede process scan')):
                self.assertEqual(retention.automatic_retention(self.root, self.fdir), [])
            self.assertLess(time.monotonic() - started, 1)
            self.assertFalse((directory / 'last-retention.json').exists())
        self.assertTrue(retention.automatic_retention(self.root, self.fdir)[0]['removed'])
        self.assertFalse((tree / 'tracked').exists())

    def test_automatic_unchanged_state_skips_cleanup_but_terminal_change_retries(self):
        tree, path = self.candidate(state='running')
        with patch.object(retention, 'cleanup', wraps=retention.cleanup) as cleaner:
            retention.automatic_retention(self.root, self.fdir)
            retention.automatic_retention(self.root, self.fdir)
            self.assertEqual(cleaner.call_count, 1)
            receipt = lane.read(path)
            receipt['state'] = 'done'
            lane.write(path, receipt)
            retention.automatic_retention(self.root, self.fdir)
            self.assertEqual(cleaner.call_count, 2)
        self.assertFalse((tree / 'tracked').exists())

    def test_pending_queued_running_unknown_and_live_owner_are_protected(self):
        trees = []
        for run, fields in (
            ('pending', dict(integrated=dict(pushed='yes', ci='pending'))),
            ('unknown', dict(integrated=dict(pushed='yes'))),
            ('queued', dict(state='queued')),
            ('running', dict(state='running')),
            ('live', dict(owner=lane.process_owner())),
        ):
            trees.append(self.candidate(run, **fields)[0])
        self.assertFalse(any(r['removed'] for r in retention.automatic_retention(self.root, self.fdir)))
        self.assertTrue(all((t / 'tracked').is_file() for t in trees))

    def test_supersession_requires_explicit_terminal_proof(self):
        tree, receipt = self.candidate(integrated=dict(pushed='yes', ci='red-advisory-superseded'))
        self.assertFalse(retention.cleanup(self.root, self.fdir)[0]['removed'])
        value = lane.read(receipt)
        value['integrated'].update(superseded_by='a' * 40, ci_supersession=dict(reason='explicit fixture authorization'))
        lane.write(receipt, value)
        self.assertTrue(retention.cleanup(self.root, self.fdir)[0]['removed'])

    def test_nested_pending_receipt_reference_protects_explicit_input(self):
        tree = self.checkout(self.base / 'other/.local/input')
        lane.write(self.fdir / 'lane/runs/pending.json', dict(id='pending', state='done',
            root=str(self.root), integrated=dict(pushed='yes', ci='pending'), items=[dict(root=str(tree))]))
        result = retention.cleanup_inputs(self.root, self.fdir, [tree])
        self.assertIn('queued/running input', result[0]['reason'])
        self.assertTrue((tree / 'tracked').is_file())
        (self.fdir / 'lane/runs/pending.json').unlink()
        self.assertTrue(retention.cleanup_inputs(self.root, self.fdir, [tree])[0]['removed'])
        self.assertTrue((tree / '.git').is_dir())

    def test_live_pin_map_key_protects_terminal_candidate(self):
        tree, _ = self.candidate()
        lane.write(self.fdir / 'lane/runs/live.json', dict(id='live', state='running',
            input_pins={str(tree / 'tracked'): 'fixture-pin'}))
        self.assertIn('queued/running input', retention.cleanup(self.root, self.fdir)[0]['reason'])
        self.assertTrue((tree / 'tracked').is_file())

    def test_explicit_input_cleanup_does_not_scan_other_candidates(self):
        unrelated, _ = self.candidate()
        requested = self.checkout(self.base / 'other/.local/input')
        rows = retention.cleanup_inputs(self.root, self.fdir, [requested])
        self.assertEqual([r['tree'] for r in rows], [str(requested)])
        self.assertTrue(rows[0]['removed'])
        self.assertTrue((unrelated / 'tracked').is_file())
        self.assertEqual(retention.cleanup_inputs(self.root, self.fdir, []), [])

    def test_saved_command_reference_protects_input(self):
        tree, _ = self.candidate()
        lane.write(self.fdir / 'lane/queue/command.json', dict(state='queued',
            resume_command='tool --root "' + str(tree) + '" --resume fixture'))
        self.assertIn('queued/running input', retention.cleanup(self.root, self.fdir)[0]['reason'])

    def test_worktree_removal_pins_detached_commit_and_keeps_registration(self):
        tree = self.fdir / 'reconfirm/worktree/tree'
        tree.parent.mkdir(parents=True)
        self.git(self.root, 'worktree', 'add', '--quiet', '--detach', str(tree), 'HEAD')
        head = self.git(tree, 'rev-parse', 'HEAD')
        lane.write(tree.parent / 'state.json', dict(phase='queued', view=str(tree)))
        lane.write(self.fdir / 'lane/queue/selection.json', dict(root=str(tree), state='done'))
        row = retention.cleanup(self.root, self.fdir)[0]
        self.assertTrue(row['removed'], row)
        self.assertFalse(tree.exists())
        self.assertEqual(self.git(self.root, 'rev-parse', 'refs/cleanup/working-copies/' + head), head)
        self.assertTrue((Path(row['archive']) / 'registration/HEAD').is_file())

    def test_explicit_dirty_worktree_archives_all_files_before_plain_removal(self):
        tree = self.root / '.local/inputs/dirty'
        tree.parent.mkdir(parents=True)
        self.git(self.root, 'worktree', 'add', '--quiet', '--detach', str(tree), 'HEAD')
        head = self.git(tree, 'rev-parse', 'HEAD')
        (tree / 'tracked').write_text('dirty tracked fixture\n')
        (tree / 'untracked.arbitrary').write_text('original untracked fixture\n')
        (tree / '.local').mkdir()
        (tree / '.local/private.unknown').write_text('original private fixture\n')
        original = retention.f.git
        with patch.object(retention.f, 'git', wraps=original) as commands:
            row = retention.cleanup_inputs(self.root, self.fdir, [tree])[0]
        self.assertTrue(row['removed'], row)
        self.assertFalse(tree.exists())
        archive = Path(row['archive'])
        self.assertEqual((archive / 'files/untracked.arbitrary').read_text(), 'original untracked fixture\n')
        self.assertEqual((archive / 'files/.local/private.unknown').read_text(), 'original private fixture\n')
        self.assertIn('dirty tracked fixture', (archive / 'unstaged-changes.patch').read_text())
        self.assertTrue((archive / 'registration/HEAD').is_file())
        self.assertEqual(self.git(self.root, 'rev-parse', 'refs/cleanup/working-copies/' + head), head)
        removals = [c.args for c in commands.call_args_list if 'remove' in c.args]
        self.assertEqual(len(removals), 1)
        self.assertNotIn('--force', removals[0])

    def test_automatic_dirty_worktree_does_not_repeat_failed_evidence_archives(self):
        tree = self.fdir / 'reconfirm/dirty/tree'
        tree.parent.mkdir(parents=True)
        self.git(self.root, 'worktree', 'add', '--quiet', '--detach', str(tree), 'HEAD')
        (tree / 'tracked').write_text('original uncommitted fixture\n')
        (tree / 'untracked').write_text('original untracked fixture\n')
        lane.write(tree.parent / 'state.json', dict(phase='queued', view=str(tree)))
        lane.write(self.fdir / 'lane/queue/selection.json', dict(root=str(tree), state='done'))
        for _ in range(2):
            rows = retention.cleanup(self.root, self.fdir)
            self.assertFalse(rows[0]['removed'])
            self.assertIn('dirty checkout', rows[0]['reason'])
        self.assertEqual((tree / 'tracked').read_text(), 'original uncommitted fixture\n')
        self.assertEqual((tree / 'untracked').read_text(), 'original untracked fixture\n')
        self.assertFalse((self.root / '.local/archive/cleanup').exists())

    def test_copied_view_removal_preserves_original_worktree_and_index(self):
        original = self.base / 'original'
        self.git(self.root, 'worktree', 'add', '--quiet', '--detach', str(original), 'HEAD')
        (original / 'tracked').write_text('original staged fixture\n')
        self.git(original, 'add', 'tracked')
        index = Path(self.git(original, 'rev-parse', '--absolute-git-dir')) / 'index'
        before = index.read_bytes()
        copy = self.root / '.local/inputs/copy'
        shutil.copytree(original, copy)
        (copy / 'tracked').write_text('copied dirty fixture\n')
        (copy / 'unknown.arbitrary').write_text('copied untracked fixture\n')
        row = retention.cleanup_inputs(self.root, self.fdir, [copy])[0]
        self.assertTrue(row['removed'], row)
        self.assertFalse(copy.exists())
        self.assertEqual(index.read_bytes(), before)
        self.assertEqual((original / 'tracked').read_text(), 'original staged fixture\n')
        self.assertIn(str(original), self.git(self.root, 'worktree', 'list', '--porcelain'))
        archive = Path(row['archive'])
        self.assertTrue((archive / 'git-marker').is_file())
        self.assertIn('copied dirty fixture', (archive / 'unstaged-changes.patch').read_text())
        self.assertEqual((archive / 'files/unknown.arbitrary').read_text(), 'copied untracked fixture\n')

    def test_independent_repository_worktree_removes_via_its_own_common_store(self):
        independent = self.checkout(self.base / 'independent')
        tree = self.root / '.local/inputs/independent'
        tree.parent.mkdir(parents=True)
        self.git(independent, 'worktree', 'add', '--quiet', '--detach', str(tree), 'HEAD')
        (tree / 'tracked').write_text('independent dirty fixture\n')
        row = retention.cleanup_inputs(self.root, self.fdir, [tree])[0]
        self.assertTrue(row['removed'], row)
        self.assertFalse(tree.exists())
        self.assertNotIn(str(tree), self.git(independent, 'worktree', 'list', '--porcelain'))
        self.assertEqual((independent / 'tracked').read_text(), 'original fixture\n')

    def test_locked_explicit_worktree_is_refused_before_archiving_or_restoring(self):
        tree = self.root / '.local/inputs/locked'
        tree.parent.mkdir(parents=True)
        self.git(self.root, 'worktree', 'add', '--quiet', '--detach', str(tree), 'HEAD')
        self.git(self.root, 'worktree', 'lock', str(tree))
        (tree / 'tracked').write_text('keep dirty fixture\n')
        row = retention.cleanup_inputs(self.root, self.fdir, [tree])[0]
        self.assertIn('locked worktree', row['reason'])
        self.assertEqual((tree / 'tracked').read_text(), 'keep dirty fixture\n')
        self.assertFalse((self.root / '.local/archive').exists())

    def test_race_rechecks_and_releases_reservation(self):
        tree, _ = self.candidate()
        original = retention.archive_evidence
        def raced(*args):
            original(*args)
            lane.write(self.fdir / 'lane/queue/new.json', dict(state='queued', root=str(tree)))
        with patch.object(retention, 'archive_evidence', side_effect=raced):
            row = retention.cleanup(self.root, self.fdir)[0]
        self.assertIn('queued/running input', row['reason'])
        self.assertTrue((tree / 'tracked').is_file())
        self.assertTrue(all(not lane.read(p)['active'] for p in (self.fdir / 'cleanup/claims').glob('*.json')))

    def test_reconfirm_waits_for_done_selection_and_owner_lock(self):
        tree = self.checkout(self.fdir / 'reconfirm/fixture/tree')
        lane.write(tree.parent / 'state.json', dict(phase='queued', view=str(tree)))
        selection = self.fdir / 'lane/queue/reconfirm.json'
        lane.write(selection, dict(root=str(tree), state='queued'))
        self.assertFalse(retention.cleanup(self.root, self.fdir)[0]['removed'])
        lane.write(selection, dict(root=str(tree), state='done'))
        with (tree.parent / '.lock').open('a') as owner:
            fcntl.flock(owner, fcntl.LOCK_EX | fcntl.LOCK_NB)
            self.assertIn('live owner', retention.cleanup(self.root, self.fdir)[0]['reason'])
        self.assertTrue(retention.cleanup(self.root, self.fdir)[0]['removed'])


if __name__ == '__main__':
    unittest.main()
