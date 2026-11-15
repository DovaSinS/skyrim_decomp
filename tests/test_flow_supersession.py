"""Advisory supersession preserves pushed evidence and refuses unrelated CI failures."""
import copy
import fcntl
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools'))
import flow
import flow_lane as lane
import flow_cleanup


def git(root, *args):
    return subprocess.run(['git', *args], cwd=root, check=True, capture_output=True,
                          text=True).stdout.strip()


def evidence(commit, red=False):
    runs = [dict(workflow=name, status='completed', conclusion='success', failed_steps=[], run_id=i)
            for i, name in enumerate(('Infrastructure checks', 'Publish research report', lane.ADVISORY_WORKFLOW))]
    if red:
        runs[-1].update(conclusion='failure', failed_steps=[lane.ADVISORY_STEP])
    return dict(commit=commit, result='red' if red else 'green', runs=runs)


class Supersession(unittest.TestCase):
    def setUp(self):
        private = ROOT / '.local'
        private.mkdir(exist_ok=True)
        self.tmp = tempfile.TemporaryDirectory(dir=private, prefix='test-supersession-')
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        self.fdir = self.root / '.local/flow'
        git(self.root, 'init', '--quiet')
        git(self.root, 'config', 'user.name', 'Synthetic test')
        git(self.root, 'config', 'user.email', 'test@example.invalid')
        progress = self.root / 'progress.json'
        progress.write_text('{"matched": 7}\n')
        git(self.root, 'add', 'progress.json')
        git(self.root, 'commit', '--quiet', '-m', 'synthetic original')
        self.original = git(self.root, 'rev-parse', 'HEAD')
        git(self.root, 'commit', '--quiet', '--allow-empty', '-m', 'synthetic repair')
        self.repair = git(self.root, 'rev-parse', 'HEAD')
        git(self.root, 'update-ref', 'refs/remotes/origin/main', self.repair)
        self.path = self.fdir / 'lane/runs/test-run.json'
        self.receipt = dict(id='test-run', state='running', root=str(self.root), branch='main',
                            owner=None, items=[dict(id='selected', state='running'), dict(id='held', state='running')],
                            accepted=[dict(item='selected', functions=['0x1000'])],
                            integrated=dict(commit=self.original, pushed='original timestamp', accepted=7, ci='red'))
        lane.write(self.path, self.receipt)
        self.observations = {self.original: evidence(self.original, True), self.repair: evidence(self.repair)}
        real_git = flow.git
        self.fetch = patch.object(flow, 'git', side_effect=lambda root, *args, **kwargs:
                                  '' if args[0] == 'fetch' else real_git(root, *args, **kwargs))
        self.fetch.start()
        self.addCleanup(self.fetch.stop)
        self.ci = patch.object(lane, 'ci_evidence', side_effect=lambda root, sha, python: self.observations[sha])
        self.ci.start()
        self.addCleanup(self.ci.stop)
        self.retention = patch.object(flow_cleanup, 'automatic_retention', create=True)
        self.retention_mock = self.retention.start()
        self.addCleanup(self.retention.stop)

    def finish(self, **kwargs):
        return lane.finish_superseded(self.root, self.fdir, 'test-run',
                                      kwargs.get('repair', self.repair), 'maintainer-authorized CRLF repair')

    def assert_refused(self, pattern):
        before = self.path.read_bytes()
        with self.assertRaisesRegex(flow.FlowError, pattern):
            self.finish()
        self.assertEqual(before, self.path.read_bytes())

    def test_finishes_without_rewriting_pushed_or_progress(self):
        progress = (self.root / 'progress.json').read_bytes()
        result = self.finish()
        saved = lane.read(self.path)
        self.assertEqual(result['ci'], 'red-advisory-superseded')
        self.assertEqual(saved['state'], 'done')
        self.assertEqual(saved['integrated']['commit'], self.original)
        self.assertEqual(saved['integrated']['pushed'], 'original timestamp')
        self.assertEqual(saved['integrated']['accepted'], 7)
        self.assertEqual(saved['integrated']['superseded_by'], self.repair)
        self.assertEqual(saved['integrated']['ci_supersession']['original']['result'], 'red')
        self.assertEqual([i['state'] for i in saved['items']], ['done', 'dropped'])
        self.assertEqual(lane.read(self.fdir / 'lane/queue/selected.json')['state'], 'done')
        self.assertEqual(progress, (self.root / 'progress.json').read_bytes())
        self.retention_mock.assert_called_once_with(self.root, self.fdir)
        self.finish()
        self.assertEqual(saved, lane.read(self.path))

    def test_generic_resume_preserves_supported_terminal_supersession(self):
        self.finish()
        saved = lane.read(self.path)
        with patch.object(lane, 'lane_python', return_value=sys.executable), \
                patch.object(lane.subprocess, 'run', side_effect=AssertionError('terminal CI must not be reobserved')):
            result = lane.run_lane(self.root, self.fdir, resume='test-run')
        self.assertEqual(result, saved)
        self.assertEqual(lane.read(self.path), saved)

    def test_terminal_shortcut_requires_saved_supersession_proof(self):
        self.finish()
        current = lane.read(self.path)
        current['integrated'].pop('ci_supersession')
        lane.write(self.path, current)
        @lane.ci_serialized('runs')
        def observe(root, fdir, receipt, python, ci_wait):
            return {'observed': True}
        self.assertEqual(observe(self.root, self.fdir, current, sys.executable, 0), {'observed': True})

    def test_refuses_live_owner(self):
        self.receipt['owner'] = lane.process_owner()
        lane.write(self.path, self.receipt)
        self.assert_refused('owner is still live')

    def test_refuses_unpublished_receipt(self):
        self.receipt['integrated']['pushed'] = None
        lane.write(self.path, self.receipt)
        self.assert_refused('already pushed')

    def test_refuses_non_descendant(self):
        tree = git(self.root, 'rev-parse', 'HEAD^{tree}')
        unrelated = git(self.root, 'commit-tree', tree, '-m', 'unrelated synthetic root')
        with self.assertRaisesRegex(flow.FlowError, 'not an ancestor'):
            self.finish(repair=unrelated)

    def test_refuses_unpublished_superseder(self):
        git(self.root, 'update-ref', 'refs/remotes/origin/main', self.original)
        self.assert_refused('not published')

    def test_finishes_while_unrelated_lane_is_busy(self):
        with lane.lane_lock(self.fdir):
            self.assertEqual(self.finish()['state'], 'done')

    def test_ci_observations_do_not_hold_state_lock(self):
        def observe(root, sha, python):
            subprocess.run([sys.executable, '-c',
                            'import fcntl,sys; f=open(sys.argv[1], \"a\"); '
                            'fcntl.flock(f, fcntl.LOCK_EX | fcntl.LOCK_NB)',
                            str(self.fdir / '.state.lock')], check=True, capture_output=True, timeout=5)
            return self.observations[sha]
        with patch.object(lane, 'ci_evidence', side_effect=observe):
            self.assertEqual(self.finish()['state'], 'done')

    def test_cli_dispatch_does_not_hold_state_lock(self):
        from flow_state import inherited_lock
        def execute(args, root, fdir):
            self.assertIsNone(inherited_lock())
            return 0
        with patch.object(flow, 'execute', side_effect=execute):
            self.assertEqual(flow.main(['--root', str(self.root), '--flow-dir', str(self.fdir),
                                       'lane-finish-superseded', 'test-run',
                                       '--superseding-commit', self.repair, '--reason', 'authorized repair']), 0)

    def test_refuses_active_ci_observer(self):
        lock = self.fdir / 'lane/ci-locks/test-run.lock'
        lock.parent.mkdir(parents=True)
        with lock.open('a') as handle:
            fcntl.flock(handle, fcntl.LOCK_EX | fcntl.LOCK_NB)
            self.assert_refused('CI observer is active')

    def test_refuses_other_workflow_failure(self):
        self.observations[self.original]['runs'][0]['conclusion'] = 'failure'
        self.assert_refused('not exclusively')

    def test_refuses_other_advisory_step(self):
        self.observations[self.original]['runs'][-1]['failed_steps'].append('target-hashes / Other failure')
        self.assert_refused('not exclusively')

    def test_refuses_missing_or_pending_or_red_repair(self):
        clean = copy.deepcopy(self.observations)
        for mutation in ('missing', 'pending', 'red'):
            with self.subTest(mutation=mutation):
                self.observations = copy.deepcopy(clean)
                repair = self.observations[self.repair]
                if mutation == 'missing':
                    repair['runs'].pop()
                elif mutation == 'pending':
                    repair['runs'][0]['status'] = 'in_progress'
                else:
                    repair['result'] = 'red'
                    repair['runs'][-1]['conclusion'] = 'failure'
                self.assert_refused('missing required|pending|must pass')

    def test_ci_evidence_checks_exact_commit_and_exit(self):
        self.ci.stop()
        sample = evidence(self.original, True)
        with patch.object(lane.subprocess, 'run', return_value=subprocess.CompletedProcess([], 1, json.dumps(sample), '')):
            self.assertEqual(lane.ci_evidence(self.root, self.original, sys.executable), sample)
            with self.assertRaisesRegex(flow.FlowError, 'another commit'):
                lane.ci_evidence(self.root, self.repair, sys.executable)
        with patch.object(lane.subprocess, 'run', return_value=subprocess.CompletedProcess([], 2, '', '')):
            with self.assertRaisesRegex(flow.FlowError, 'unavailable or pending'):
                lane.ci_evidence(self.root, self.original, sys.executable)


if __name__ == '__main__':
    unittest.main()
