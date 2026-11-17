"""Explicit advisory repair with synthetic git/CI; no real remote or game input."""
import contextlib
import io
import json
from pathlib import Path
import sys
from types import SimpleNamespace
import unittest
from unittest.mock import patch

from test_flow_operations import Operations as Fixture
from test_flow import flow, git
import flow_lane as lane
import flow_repair as repair

setup = Fixture.setUp
enqueue = Fixture.enqueue
del Fixture

class AdvisoryRepair(unittest.TestCase):
    def setUp(self):
        setup(self)
        exclude = Path(git(self.root, 'rev-parse', '--git-path', 'info/exclude'))
        if not exclude.is_absolute(): exclude = self.root / exclude
        exclude.parent.mkdir(parents=True, exist_ok=True)
        with exclude.open('a') as stream: stream.write('\n__pycache__/\n')

    enqueue = enqueue

    def change(self, path='.gitattributes', body='*.sha256 text eol=lf\n'):
        target=self.root/path;target.parent.mkdir(parents=True,exist_ok=True);target.write_text(body)
        git(self.root,'add',path);git(self.root,'commit','--quiet','-m','synthetic advisory repair')
        return git(self.root,'rev-parse','HEAD')

    def report(self, base, workflow='Advisory target hashes', status='completed'):
        return dict(commit=base,result='red',runs=[
            dict(workflow='Infrastructure checks',status='completed',conclusion='success',run_id=1),
            dict(workflow='Publish research report',status='completed',conclusion='success',run_id=2),
            dict(workflow=workflow,status=status,conclusion='failure',run_id=3)])

    def commands(self, base, report):
        original=lane.subprocess.run
        def run(argv,*args,**kwargs):
            if 'tools/ci_status.py' in argv:
                sha=argv[argv.index('--commit')+1]
                return SimpleNamespace(returncode=1 if sha==base else 0,
                    stdout=json.dumps(report) if sha==base else 'GREEN',stderr='')
            if argv[:3]==['gh','workflow','run']:
                self.dispatched.append(argv);return SimpleNamespace(returncode=0,stdout='',stderr='')
            return original(argv,*args,**kwargs)
        self.dispatched=[]
        return run

    def test_exact_related_repair_records_base_keeps_all_checks_and_does_not_drain_acceptances(self):
        self.enqueue()
        base=git(self.repo.origin,'rev-parse','main');candidate=self.change()
        with patch.object(lane.subprocess,'run',side_effect=self.commands(base,self.report(base))), \
             patch.object(flow,'pre_push_checks',wraps=flow.pre_push_checks) as checks:
            result=lane.publish_tooling(self.root,self.fdir,python=sys.executable,ci_wait=0,repair_red=base)
        checks.assert_called_once()
        self.assertEqual(result['repair_red'],base)
        self.assertEqual(result['repair']['candidate'],candidate)
        self.assertEqual(result['repair']['changed_paths'],['.gitattributes'])
        self.assertEqual(result['repair']['workflows'],['Advisory target hashes'])
        self.assertTrue(result['repair_dispatched'])
        self.assertEqual(result['state'],'done')
        self.assertEqual(git(self.repo.origin,'rev-parse','main'),candidate)
        self.assertTrue(all(lane.read(p)['state']=='queued' for p in (self.fdir/'lane/queue').glob('*.json')))
        self.assertEqual(len(self.dispatched),1)
        saved=lane.read(self.fdir/'lane/tooling'/(result['id']+'.json'))
        self.assertEqual(saved['repair']['red_sha'],base)

    def test_unrelated_source_and_acceptance_paths_are_refused_before_full_checks(self):
        base=git(self.repo.origin,'rev-parse','main');self.change('unrelated.txt','unrelated')
        with patch.object(lane.subprocess,'run',side_effect=self.commands(base,self.report(base))), \
             patch.object(flow,'pre_push_checks',side_effect=AssertionError('must refuse before checks')):
            with self.assertRaisesRegex(flow.FlowError,'unrelated'):
                lane.publish_tooling(self.root,self.fdir,python=sys.executable,ci_wait=0,repair_red=base)
        self.assertEqual(git(self.repo.origin,'rev-parse','main'),base)
        self.assertFalse(self.dispatched)

    def test_default_publish_still_refuses_real_required_red(self):
        base=git(self.repo.origin,'rev-parse','main');self.change()
        with patch.object(lane.subprocess,'run',side_effect=self.commands(base,self.report(base,'Infrastructure checks'))):
            with self.assertRaisesRegex(flow.FlowError,'origin CI is not green'):
                lane._publish_legacy_tooling(self.root,self.fdir,python=sys.executable,ci_wait=0)
        self.assertEqual(git(self.repo.origin,'rev-parse','main'),base)

    def test_pending_required_unknown_and_stale_status_never_authorize_a_repair(self):
        base=git(self.repo.origin,'rev-parse','main');candidate=self.change()
        reports=[self.report(base,'Infrastructure checks'),self.report(base,'Unknown job'),
                 self.report(base,status='in_progress'),dict(self.report(base),commit='b'*40)]
        for report in reports:
            with self.subTest(report=report),patch.object(lane.subprocess,'run',side_effect=self.commands(base,report)):
                with self.assertRaises(flow.FlowError):repair.approve(self.root,base,candidate,base,sys.executable,0)
        with self.assertRaisesRegex(flow.FlowError,'no longer origin'):
            repair.approve(self.root,base,candidate,'b'*40,sys.executable,0)
        with self.assertRaisesRegex(flow.FlowError,'exact full'):
            repair.validate_sha('a47c3be5')

    def test_documentation_alone_does_not_count_as_a_failed_job_input(self):
        base=git(self.repo.origin,'rev-parse','main');candidate=self.change('docs/ci-hash-check.md','synthetic')
        with patch.object(lane.subprocess,'run',side_effect=self.commands(base,self.report(base))):
            with self.assertRaisesRegex(flow.FlowError,'actual inputs'):
                repair.approve(self.root,base,candidate,base,sys.executable,0)

    def test_cli_forwards_explicit_repair_sha(self):
        with patch('flow_preflight.preflight', return_value=dict(ok=True, problem=None, rebased=False)), \
                patch.object(lane,'publish_tooling',return_value={}) as publish,contextlib.redirect_stdout(io.StringIO()):
            self.assertEqual(flow.main(['--root',str(self.root),'--flow-dir',str(self.fdir),
                'tooling-push','--repair-red','a'*40]),0)
        self.assertEqual(publish.call_args.kwargs['repair_red'],'a'*40)

if __name__=='__main__':unittest.main()
