"""Mapped enrollment is transport only; real synthetic acceptance makes the same decisions."""
import copy
from datetime import datetime, timezone
import json
from pathlib import Path
import shutil
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path[:0] = [str(Path(__file__).resolve().parents[1] / 'tools')]
import accept_function as af
import build_index
import flow
import flow_lane as lane
import lane_accept
from test_flow import git
from test_flow_lane import PushLane as _PushLane, stub_accept
from test_acceptance_flow import FlowFixture

lane_setup, enqueue, run_lane = _PushLane.setUp, _PushLane.enqueue, _PushLane.lane
del _PushLane


class EnrollmentLane(unittest.TestCase):
    setUp, enqueue, lane = lane_setup, enqueue, run_lane

    def unenroll(self):
        data = flow.inventory(self.root)
        (self.root / af.PROGRESS).write_text(json.dumps(dict(data, functions=[])))
        git(self.root, 'add', '--', af.PROGRESS)
        git(self.root, 'commit', '--quiet', '-m', 'synthetic public base without enrollment')
        git(self.root, 'push', '--quiet', 'origin', 'main')
        (self.root / af.PROGRESS).write_text(json.dumps(data))
        return data

    def test_new_rows_and_acceptance_publish_together_and_shadow_flags_are_not_carried(self):
        data = self.unenroll()
        for fn in data['functions']:
            fn.update(status='matched', named=False, drafter_model='synthetic-model')
        (self.root / af.PROGRESS).write_text(json.dumps(data))
        self.enqueue()
        def accept(tree, requests, python):
            rows = flow.inventory(tree)['functions']
            self.assertTrue(all(fn['status'] == 'mapped' and 'named' not in fn for fn in rows))
            self.assertTrue(all(fn['drafter_model'] == 'synthetic-model' for fn in rows))
            self.assertEqual(sum(len(r['enrollments']) for r in requests), 3)
            return stub_accept(tree, requests, python)
        with patch.object(lane, 'accept', side_effect=accept):
            result = self.lane()
        self.assertFalse(result['dropped'])
        self.assertEqual(result['integrated']['accepted'], 3)
        self.assertEqual(result['integrated']['ci'], 'green')
        self.assertTrue(all(fn['status'] == 'matched' for fn in flow.inventory(Path(result['tree']))['functions']))

    def test_committed_mapped_enrollment_can_use_with_metadata(self):
        self.unenroll()
        git(self.root, 'add', '--', af.PROGRESS)
        git(self.root, 'commit', '--quiet', '-m', 'synthetic mapped-only enrollment')
        for name in self.names:
            lane.enqueue(self.root, self.fdir, 'review', [name], with_metadata=True)
        result = self.lane(push=False)
        self.assertFalse(result['dropped'])
        self.assertEqual(result['integrated']['accepted'], 3)

    def test_unrelated_new_rows_stay_out_of_the_lane_selection(self):
        data = self.unenroll()
        extra = dict(data['functions'][0], id='unselected-synthetic', rva=0x9000)
        data['functions'].append(extra)
        (self.root / af.PROGRESS).write_text(json.dumps(data))
        self.enqueue(self.names[:1])
        result = self.lane(push=False)
        self.assertFalse(result['dropped'])
        self.assertNotIn(extra['id'], {fn['id'] for fn in flow.inventory(Path(result['tree']))['functions']})

    def test_inventory_source_edits_and_acceptance_flags_in_history_refuse(self):
        data = self.unenroll()
        for mutation in ('matched', 'named', 'existing', 'phase'):
            before, after = copy.deepcopy(data), copy.deepcopy(data)
            if mutation in ('matched', 'named'):
                before['functions'] = []
                if mutation == 'matched':
                    after['functions'][0]['status'] = 'matched'
                else:
                    after['functions'][0]['named'] = False
            elif mutation == 'existing':
                after['functions'][0]['size'] += 1
            else:
                after['phase'] = 'not enrollment'
            with self.subTest(mutation=mutation), self.assertRaises(flow.FlowError):
                flow.enrollment_delta(before, after)


class RealEnrollment(FlowFixture, unittest.TestCase):
    def test_new_enrollment_keeps_acceptance_and_two_host_refusal_identical(self):
        review = self.review_file('review-enrollment', [self.block()])
        # Only original synthetic source and comparator records enter these temporary trees.
        with tempfile.TemporaryDirectory(prefix='enrollment-') as tmp:
            baseline = Path(tmp) / 'baseline'
            shutil.copytree(self.root, baseline)
            fn = next(fn for fn in self.progress()['functions'] if fn['id'] == self.fn['id'])
            enrollment = dict({k: v for k, v in fn.items() if k != 'named'}, status='mapped')
            for invalid in (False, True):
                source, tree = Path(tmp) / f'source-{invalid}', Path(tmp) / f'tree-{invalid}'
                shutil.copytree(baseline, source)
                if invalid:
                    record = json.loads((source / fn['report']).read_text())
                    record['runs'][1]['compiled_on'] = record['runs'][0]['compiled_on']
                    record['runs'][1]['compared_on'] = record['runs'][0]['compared_on']
                    (source / fn['report']).write_text(json.dumps(record))
                shutil.copytree(source, tree)
                data = flow.inventory(tree)
                data['functions'] = [row for row in data['functions'] if row['id'] != fn['id']]
                (tree / af.PROGRESS).write_text(json.dumps(data))
                flow.carry_into_tree(source, tree, [flow.hexrva(fn['rva'])], {flow.hexrva(fn['rva']): fn},
                                     harvests={}, enrollments=[enrollment])
                build_index.write_index(flow.inventory(tree), tree)
                when = datetime(2000, 1, 4, tzinfo=timezone.utc)
                def accept(root):
                    request = dict(kind='review', review=str(root / review.relative_to(self.root)),
                                   functions=[fn['id']], profile='cheap')
                    result = lane_accept.accept(root, [request], when)
                    result.pop('wall_seconds')
                    return result
                expected, actual = accept(source), accept(tree)
                # Request paths name each private copy; compare the actual decision/reason.
                self.assertEqual(bool(actual['accepted']), bool(expected['accepted']))
                self.assertEqual([d['reason'] for d in actual['dropped']], [d['reason'] for d in expected['dropped']])
                self.assertEqual(bool(actual['accepted']), not invalid)
                self.assertEqual({row['id']: row for row in flow.inventory(tree)['functions']},
                                 {row['id']: row for row in flow.inventory(source)['functions']})


if __name__ == '__main__':
    unittest.main()
