"""Synthetic queue recovery, scheduler ownership, and service publication boundaries."""
import json
from pathlib import Path
import shutil
import socket
import subprocess
import sys
import tempfile
import unittest
from types import SimpleNamespace
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import flow
import flow_lane as lane
import lane_service as service
from test_flow import Repo, git


class LaneService(unittest.TestCase):
    def setUp(self):
        self.tmp = Path(tempfile.mkdtemp()).resolve()
        self.addCleanup(shutil.rmtree, self.tmp)
        self.repo = Repo(self.tmp)
        self.root, self.fdir = self.repo.root, self.repo.fdir
        # Functional queue/service fixtures must not depend on the host volume's free space.
        # Dedicated admission/refusal tests override admit itself and keep the real floor tests.
        disk = patch.object(service.resource_admission.shutil, 'disk_usage',
                            return_value=SimpleNamespace(free=20_000_000_000))
        disk.start()
        self.addCleanup(disk.stop)
        self.owner = dict(pid=99999999, birth='not alive', host=socket.gethostname())
        self.config = dict(root=str(self.root), flow_dir=str(self.fdir), python=sys.executable,
                           branch='main', ci_wait=0, soft_free_gb=10, environment={})

    def stale(self, **fields):
        item = lane.enqueue(self.root, self.fdir, 'review', ['g1'])
        item.update(state='stale', run='dead')
        tooling = dict(id='tool', state='stale', run='dead', root=str(self.root), revision='a' * 40,
                       base='b' * 40, branch='main', queued_at=flow.utc(), paths=['tools/example.py'])
        r = dict(id='dead', state='stale', branch='main', root=str(self.root), owner=self.owner,
                 items=[item], tooling=[tooling], integrated=None, **fields)
        lane.save_run(self.fdir, r)
        return r

    def test_dead_recovery_retains_evidence_and_requeues_both_kinds(self):
        r = self.stale()
        review = self.root / '.local/reviews/keep.md'
        review.parent.mkdir(parents=True, exist_ok=True)
        review.write_text('Original synthetic approval retained')
        before = review.read_bytes()
        with patch.object(lane, 'run_lane', return_value=dict(state='empty')) as publish:
            result = service.worker(self.config)
        self.assertEqual(result['recovered'][0]['run'], 'dead')
        for directory, key in (('queue', r['items'][0]['id']), ('tooling-queue', 'tool')):
            current = lane.read(self.fdir / 'lane' / directory / (key + '.json'))
            self.assertEqual(current['state'], 'queued')
            self.assertNotIn('run', current)
            self.assertEqual(current['recovered_from'], 'dead')
        self.assertEqual(lane.read(self.fdir / 'lane/runs/dead.json')['state'], 'retired')
        self.assertEqual(review.read_bytes(), before)
        self.assertFalse(publish.call_args.kwargs['sync_claims'])

    def test_recovery_does_not_overwrite_new_owner_or_completed_queue(self):
        r = self.stale()
        path = self.fdir / 'lane/queue' / (r['items'][0]['id'] + '.json')
        current = dict(r['items'][0], state='running', run='new-owner')
        lane.write(path, current)
        with lane.service_authority(self.fdir):
            lane.retire(self.root, self.fdir, 'dead', 'recover', requeue_stale=True)
        self.assertEqual(lane.read(path), current)

    def test_live_foreign_failed_and_pushed_receipts_are_not_retired(self):
        r = self.stale()
        path = self.fdir / 'lane/runs/dead.json'
        for changes in (dict(owner=lane.process_owner()),
                        dict(owner=dict(self.owner, host='other-machine')),
                        dict(error='binding mismatch'), dict(integrated=dict(pushed='yes'))):
            candidate = dict(r, **changes)
            lane.write(path, candidate)
            with self.subTest(changes=changes), lane.service_authority(self.fdir), self.assertRaises(flow.FlowError):
                lane.retire(self.root, self.fdir, 'dead', 'recover', requeue_stale=True)
            self.assertEqual(lane.read(path), candidate)

    def test_busy_tick_does_no_network_or_receipt_mutation(self):
        self.stale()
        private = self.fdir / 'lane/service'
        private.mkdir()
        config = private / 'config.json'
        lane.write(config, self.config)
        with lane.lane_lock(self.fdir), patch.object(service.subprocess, 'run') as run:
            self.assertEqual(service.run_once(config)['state'], 'busy')
        run.assert_not_called()
        self.assertEqual(lane.read(self.fdir / 'lane/runs/dead.json')['state'], 'stale')

    def test_disk_refusal_precedes_fetch_and_recovery(self):
        self.stale()
        private = self.fdir / 'lane/service'
        private.mkdir()
        config = private / 'config.json'
        lane.write(config, self.config)
        with patch.object(service.resource_admission, 'admit', side_effect=ValueError('disk floor')), \
                patch.object(service.subprocess, 'run') as run, patch.object(lane, 'owner_alive', return_value=False):
            with self.assertRaisesRegex(ValueError, 'disk floor'):
                service.run_once(config)
        run.assert_not_called()
        self.assertEqual(lane.read(self.fdir / 'lane/runs/dead.json')['state'], 'stale')

    def test_pushed_checkpoint_resumes_ci_without_requeue(self):
        r = self.stale()
        r['integrated'] = dict(pushed='now', commit='a' * 40)
        lane.write(self.fdir / 'lane/runs/dead.json', r)
        with patch.object(lane, 'finish_run', return_value=r) as finish, \
                patch.object(lane, 'retire') as retire, patch.object(lane, 'run_lane') as run:
            self.assertEqual(service.worker(self.config)['state'], 'finished-ci')
        self.assertFalse(finish.call_args.kwargs['sync_claims'])
        retire.assert_not_called()
        run.assert_not_called()

    def test_enqueue_only_records_tip_without_publisher_or_base_guard(self):
        path = self.root / 'tools/example.py'
        path.write_text('# Original synthetic tooling\n')
        git(self.root, 'add', 'tools/example.py')
        git(self.root, 'commit', '--quiet', '-m', 'synthetic tooling input')
        with patch('flow_preflight.preflight', return_value=dict(ok=True, problem=None, rebased=False)), \
                patch.object(lane, 'publish_tooling') as publish, patch.object(lane, 'require_base_tools') as base:
            self.assertEqual(flow.main(['--root', str(self.root), '--flow-dir', str(self.fdir),
                                        'tooling-push', '--enqueue-only']), 0)
        publish.assert_not_called()
        base.assert_not_called()
        items = service.records(self.fdir, 'tooling-queue')
        self.assertEqual(len(items), 1)
        self.assertEqual(items[0]['revision'], git(self.root, 'rev-parse', 'HEAD'))
        self.assertEqual(items[0]['state'], 'queued')

    def test_service_signal_logs_and_exits_by_signal_instead_of_a_saved_exception(self):
        tools = str(Path(service.__file__).resolve().parent)
        code = ("import sys,signal; sys.path.insert(0, sys.argv[1]); import lane_service; "
                "lane_service.stopped(signal.SIGTERM, None)")
        result = subprocess.run([sys.executable, '-c', code, tools], capture_output=True, text=True)
        self.assertEqual(result.returncode, -15)
        event = json.loads(result.stderr)
        self.assertEqual(event['event'], 'service-signal')
        self.assertEqual(event['signal'], 15)

    def test_fresh_origin_runtime_records_signal_without_publisher_timeout(self):
        # A real local git remote supplies a tiny synthetic service, no network or game data.
        script = self.root / 'tools/lane_service.py'
        script.write_text('import os, signal\nos.kill(os.getpid(), signal.SIGTERM)\n')
        git(self.root, 'add', 'tools/lane_service.py')
        git(self.root, 'commit', '--quiet', '-m', 'synthetic signal worker')
        git(self.root, 'push', '--quiet', 'origin', 'main')
        self.stale()
        private = self.fdir / 'lane/service'
        private.mkdir()
        config = private / 'config.json'
        lane.write(config, self.config)
        result = service.run_once(config)
        self.assertEqual(result['returncode'], -15)
        self.assertEqual(result['signal'], 15)
        self.assertEqual(result['state'], 'failed')
        self.assertEqual(result['runtime'], git(self.root, 'rev-parse', 'HEAD'))
        self.assertTrue(Path(result['log']).is_file())
        runtime = private / 'origin-tools'
        sparse_path = Path(git(runtime, 'rev-parse', '--path-format=absolute', '--git-path', 'info/sparse-checkout'))
        self.assertTrue(sparse_path.is_file())


if __name__ == '__main__':
    unittest.main()
