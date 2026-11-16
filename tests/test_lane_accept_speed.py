"""p141: unchanged decisions/output bytes, indexed planning and lock-free observers; synthetic only."""
import importlib.util
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools'), str(ROOT / 'tests')]
import accept_function as af
import flow
import flow_lane as lane
import lane_accept
import test_acceptance_batch as fixtures
from flow_state import state_lock

spec = importlib.util.spec_from_file_location('lane_accept_before_p141', ROOT / 'tests/fixtures/lane_accept_before_p141.py')
legacy = importlib.util.module_from_spec(spec)
spec.loader.exec_module(legacy)


class EquivalentAcceptance(unittest.TestCase):
    def setUp(self):
        self.case = fixtures.AcceptanceBatchTests('runTest')
        self.case.setUp()
        self.addCleanup(self.case.doCleanups)
        self.root, self.when = self.case.root, self.case.when

    def test_old_and_new_decisions_and_all_public_bytes(self):
        good = self.case.requests(self.case.fx.later[:3])
        bad = dict(good[0], functions=['no-such-function'])
        duplicate = dict(good[0])
        for requests, preview in ((good, False), (good + [bad], True), (good + [duplicate], False)):
            with self.subTest(requests=len(requests), preview=preview):
                before = self.case.public()
                expected = legacy.accept(self.root, requests, self.when, prepare_only=preview)
                for dropped in expected['dropped']:
                    dropped['next'] = ('Run flow.py next-actions with the same --flow-dir, '
                                       'correct the named input, then retry.')
                expected_files = self.case.public()
                self.case.restore(before)
                actual = lane_accept.accept(self.root, requests, self.when, prepare_only=preview)
                timings = actual.pop('wall_seconds')
                self.assertGreaterEqual(timings['total'], 0)
                self.assertEqual(actual, expected)
                self.assertEqual(self.case.public(), expected_files)
                self.case.restore(before)

    def test_recorded_profile_does_not_read_unneeded_session_events(self):
        request = self.case.requests(self.case.fx.later[:1])[0]
        directory = self.root / '.local/flow'
        lane.write(directory / 'groups/recorded.json', dict(task_id='performance', profile='cheap'))
        (directory / 'events.jsonl').write_text('not JSON: unrelated session event\n')
        with af.acceptance_batch(self.root, compact_plans=True):
            self.assertEqual(af.review_profile(self.root, 'performance', 'cheap'), 'cheap')
            with self.assertRaisesRegex(af.Refused, 'recorded review group'):
                af.review_profile(self.root, 'performance', 'full')

    def test_old_and_new_sample_and_family_transaction(self):
        requests, before, public, restore = self.case.fx.combined_sample_inputs()
        expected = legacy.accept(self.root, requests, self.when)
        expected_files = public()
        restore(before)
        actual = lane_accept.accept(self.root, requests, self.when)
        actual.pop('wall_seconds')
        self.assertEqual(actual, expected)
        self.assertEqual(public(), expected_files)

    def test_sparse_plans_and_profile_index_are_built_once(self):
        requests = self.case.requests(self.case.fx.later[:3])
        with af.acceptance_batch(self.root, compact_plans=True):
            with patch.object(af, 'active_profile', wraps=af.active_profile) as profile:
                plans = [af.accept_reviews(self.root, [r], self.when, prepare_only=True) for r in requests]
            self.assertEqual(profile.call_count, 1)
            self.assertTrue(all(isinstance(plan[1]['functions'], dict) for plan in plans))
            self.assertEqual([len(plan[1]['functions']) for plan in plans], [1, 1, 1])


class ReceiptsAndStatus(unittest.TestCase):
    def setUp(self):
        tmp = tempfile.TemporaryDirectory()
        self.addCleanup(tmp.cleanup)
        self.root = Path(tmp.name)
        self.fdir = self.root / '.local/flow'
        self.path = self.fdir / 'lane/runs/synthetic.json'

    def receipt(self):
        return dict(id='synthetic', root=str(self.root), branch='main', items=[], state='running',
                    owner=lane.process_owner(), integrated=dict(commit='a'*40, pushed=None, checks=None,
                    files=[f'reports/synthetic/0x{i:x}.json' for i in range(4000)]),
                    origins=[dict(entries={str(i): dict(id=f'synthetic-{i}', status='mapped') for i in range(4000)})],
                    input_pins={str(i): 'b'*64 for i in range(4000)})

    def test_compact_round_trip_digest_and_snapshot(self):
        receipt = self.receipt()
        compact = lane.compact_receipt(self.path, receipt)
        lane.write(self.path, compact)
        self.assertLess(self.path.stat().st_size, 2000)
        self.assertEqual(lane.read(self.path), receipt)
        with tempfile.TemporaryDirectory() as directory:
            frozen = Path(directory) / 'snapshot'
            lane.snapshot(self.fdir, frozen)
            self.assertEqual(lane.read(frozen / 'lane/runs/synthetic.json'), receipt)
        sidecar = self.path.parent / 'details' / (compact['details_sidecar']['sha256'] + '.json')
        sidecar.write_text('{}')
        with self.assertRaisesRegex(flow.FlowError, 'digest differs'):
            lane.read(self.path)
        self.assertEqual(lane.read(self.path, details=False), compact)

    def test_save_sidecar_contains_final_tooling_item_states(self):
        receipt = self.receipt()
        receipt['tooling'] = [dict(id='tool', state='queued')]
        def update(fdir, value, finished):
            value['tooling'][0]['state'] = 'running'
        with patch('flow_tooling.save_items', side_effect=update):
            lane.save_run(self.fdir, receipt)
        self.assertEqual(lane.read(self.path), receipt)
        self.assertEqual(lane.read(self.path)['tooling'][0]['state'], 'running')

    def test_status_returns_while_both_locks_are_held_without_loading_sidecar(self):
        receipt = self.receipt()
        lane.write(self.path, lane.compact_receipt(self.path, receipt))
        # Status needs no detail; unavailable member detail must not prevent observation.
        for path in (self.path.parent / 'details').glob('*'):
            path.unlink()
        with lane.lane_lock(self.fdir, purpose='integration'), state_lock(self.fdir):
            result = subprocess.run([sys.executable, str(ROOT / 'tools/flow.py'), '--root', str(self.root),
                                     '--flow-dir', str(self.fdir), 'lane-status'], capture_output=True, text=True, timeout=5)
        self.assertEqual(result.returncode, 0, result.stderr)
        status = json.loads(result.stdout)
        self.assertEqual(status['runs'][0]['status'], 'running')
        self.assertTrue(status['runs'][0]['lane_busy'])

    def test_gate_file_checks_run_outside_state_lock(self):
        receipt = self.receipt()
        path = self.root / 'pin.txt'
        path.write_text('synthetic')
        import hashlib
        receipt['gate_dependencies'] = [dict(request={}, bindings={}, pins={str(path): hashlib.sha256(path.read_bytes()).hexdigest()})]
        with patch.object(lane, 'state_lock', side_effect=AssertionError('read-only checks took state lock')):
            self.assertFalse(lane.requeue_changed_gates(self.root, self.fdir, receipt))


if __name__ == '__main__':
    unittest.main()
