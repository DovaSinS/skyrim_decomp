"""Control belongs to the recorded process or the running service; progress is measured."""
import json
import contextlib
import io
import os
from pathlib import Path
import signal
import socket
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import flow
import flow_lane as lane
import flow_heartbeat as heartbeat


class LaneControl(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        self.fdir = self.root / '.local/flow'
        self.path = self.fdir / 'lane/runs/example.json'
        self.record = dict(id='example', state='running', branch='main', items=[], tooling=[], integrated=None,
                           owner=dict(pid=99999999, birth='foreign', host=socket.gethostname()))
        lane.write(self.path, self.record)

    def test_foreign_stop_and_retire_refuse_before_signal_or_mutation(self):
        before = self.path.read_bytes()
        with lane.lane_lock(self.fdir), patch.object(lane.os, 'kill') as kill:
            for command in (lane.stop_run, lane.retire):
                with self.subTest(command=command.__name__), self.assertRaisesRegex(flow.FlowError, "never kill a lane process you didn't start"):
                    command(self.root, self.fdir, 'example', 'foreign watchdog')
        kill.assert_not_called()
        self.assertEqual(self.path.read_bytes(), before)

    def test_cli_refuses_foreign_control_and_unknown_birth_is_not_ownership(self):
        before = self.path.read_bytes()
        output = io.StringIO()
        with contextlib.redirect_stderr(output), patch.object(lane.os, 'kill') as kill:
            for command in ('lane-stop', 'lane-retire'):
                self.assertEqual(flow.main(['--root', str(self.root), '--flow-dir', str(self.fdir),
                                            command, 'example', '--reason', 'foreign caller']), 1)
        kill.assert_not_called()
        self.assertIn('only the lane service or its recorded owner', output.getvalue())
        self.assertEqual(self.path.read_bytes(), before)
        unknown = dict(lane.process_owner(), birth=None)
        self.record['owner'] = unknown
        lane.write(self.path, self.record)
        with patch.object(lane, 'process_owner', return_value=unknown), self.assertRaises(flow.FlowError):
            lane.retire(self.root, self.fdir, 'example', 'unknown process identity')

    def test_recorded_owner_can_retire_without_a_service_role(self):
        self.record['owner'] = lane.process_owner()
        lane.write(self.path, self.record)
        self.assertEqual(lane.retire(self.root, self.fdir, 'example', 'own run')['state'], 'retired')

    def test_only_active_locked_service_role_can_retire_dead_foreign_owner(self):
        with lane.service_authority(self.fdir):
            self.assertTrue(lane.service_caller(self.fdir))
            result = lane.retire(self.root, self.fdir, 'example', 'service recovery', requeue_stale=True)
        self.assertEqual(result['state'], 'retired')
        self.assertFalse(lane.service_caller(self.fdir))
        lane.write(self.fdir / 'lane/service/worker-owner.json', dict(lane.process_owner(), active=True))
        self.assertFalse(lane.service_caller(self.fdir))  # A marker without its held lock is insufficient.

    def test_authorized_stop_checks_birth_and_signals_only_recorded_pid(self):
        self.record['owner'] = lane.process_owner()
        lane.write(self.path, self.record)
        with patch.object(lane.os, 'kill') as kill:
            lane.stop_run(self.root, self.fdir, 'example', 'own stop')
        kill.assert_called_once_with(os.getpid(), signal.SIGTERM)
        self.assertEqual(lane.read(self.path)['stop_reason'], 'own stop')
        self.assertIn('intentionally stopped', lane.read(self.path)['error'])
        with lane.service_authority(self.fdir), patch.object(lane, 'owner_alive', return_value=False), patch.object(lane.os, 'kill') as kill:
            with self.assertRaisesRegex(flow.FlowError, 'no signal sent'):
                lane.stop_run(self.root, self.fdir, 'example', 'PID reused')
        kill.assert_not_called()

    def test_heartbeat_distinguishes_liveness_from_measured_progress(self):
        self.record['owner'] = lane.process_owner()
        self.record['details_sidecar'] = dict(sha256='a'*64, fields=['origins'])
        lane.write(self.path, self.record)
        pulse = heartbeat.Heartbeat(self.fdir)
        samples = [dict(phase='silent acceptance', step=1, cpu_seconds=n, process_count=2, log_bytes=0) for n in (1, 2, 2)]
        with patch.object(pulse, 'sample', side_effect=samples), patch.object(flow, 'utc', side_effect=['first', 'second', 'third']):
            pulse.tick(); pulse.tick(); result = pulse.tick()
        self.assertEqual(result['alive_at'], 'third')
        self.assertEqual(result['progress_at'], 'second')
        saved = json.loads(self.path.read_text())
        self.assertEqual(saved['details_sidecar'], self.record['details_sidecar'])
        self.assertEqual(saved['heartbeat'], result)
        self.record['owner'] = dict(self.record['owner'], birth='replacement')
        lane.write(self.path, self.record)
        before = self.path.read_bytes()
        pulse.tick()
        self.assertEqual(self.path.read_bytes(), before)

    def test_real_blocked_command_keeps_a_receipt_heartbeat(self):
        self.record['owner'] = lane.process_owner()
        lane.write(self.path, self.record)
        with heartbeat.observe(self.fdir, interval=0.05):
            lane.save_run(self.fdir, self.record)
            flow.run([sys.executable, '-c', 'import time; time.sleep(1)'], self.root, 'synthetic long check',
                     log_path=self.root / 'synthetic.log')
        pulse = lane.read(self.path)['heartbeat']
        self.assertEqual(pulse['phase'], 'synthetic long check')
        self.assertIn('alive_at', pulse)
        self.assertIn('progress_at', pulse)
        self.assertGreaterEqual(pulse['process_count'], 1)

    def test_cpu_clock_formats(self):
        self.assertEqual(heartbeat.cpu_seconds('01:02.50'), 62.5)
        self.assertEqual(heartbeat.cpu_seconds('1:02:03'), 3723)
        self.assertEqual(heartbeat.cpu_seconds('2-01:02:03'), 176523)


if __name__ == '__main__':
    unittest.main()
