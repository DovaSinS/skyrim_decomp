"""Original synthetic concurrent publications: generated views never arbitrate source data."""
import copy
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import flow
import flow_derived as derived
import flow_lane as lane
import flow_tooling
from test_flow import git
from test_flow_lane import PushLane as _PushLane

lane_setup, enqueue, run_lane = _PushLane.setUp, _PushLane.enqueue, _PushLane.lane
del _PushLane


class DerivedMerge(unittest.TestCase):
    def setUp(self):
        tmp = tempfile.TemporaryDirectory(prefix='derived-merge-')
        self.addCleanup(tmp.cleanup)
        self.root = Path(tmp.name)
        git(self.root, 'init', '--quiet', '-b', 'main')
        git(self.root, 'config', 'user.name', 'Synthetic')
        git(self.root, 'config', 'user.email', 'synthetic@example.invalid')
        for path in derived.DERIVED_FILES:
            self.write(path, 'synthetic base view\n')
        self.write('README.md', 'Original prose\n' + derived.START + '\nbase totals\n' + derived.END + '\n')
        self.data = dict(functions=[dict(id='a', status='mapped'), dict(id='b', status='mapped')],
                         updated_at='2000-01-01T00:00:00Z', phase='Synthetic')
        self.progress(self.data)
        self.write('source.txt', 'original source\n')
        self.base = self.commit()

    def write(self, name, text):
        path = self.root / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text(text)

    def progress(self, data):
        self.write(derived.PROGRESS, json.dumps(data, indent=2) + '\n')

    def commit(self):
        git(self.root, 'add', '--', *derived.DERIVED_FILES, derived.PROGRESS, 'README.md', 'source.txt')
        git(self.root, 'commit', '--quiet', '-m', 'original synthetic input')
        return git(self.root, 'rev-parse', 'HEAD')

    def tip(self, member, view, prose=None):
        data = copy.deepcopy(self.data)
        data['functions'][member]['status'] = 'matched'
        data['functions'].append(dict(id=view, status='mapped'))
        data['updated_at'] = f'2000-01-0{member + 2}T00:00:00Z'
        self.progress(data)
        for path in derived.DERIVED_FILES:
            self.write(path, view + '\n')
        self.write('README.md', (prose or 'Original prose') + '\n' + derived.START + '\n' + view + '\n' + derived.END + '\n')
        return self.commit()

    def test_every_derived_conflict_is_discarded_and_disjoint_rows_survive(self):
        incoming = self.tip(0, 'incoming', 'Updated prose')
        git(self.root, 'checkout', '--quiet', '--detach', self.base)
        before = self.tip(1, 'current')
        attributes = self.root / '.git/info/attributes'
        attributes.write_text('# original candidate attributes\n')
        derived.merge(self.root, incoming)
        data = flow.inventory(self.root)
        self.assertEqual([fn['status'] for fn in data['functions'][:2]], ['matched', 'matched'])
        self.assertEqual({fn['id'] for fn in data['functions']}, {'a', 'b', 'incoming', 'current'})
        self.assertEqual(data['updated_at'], '2000-01-03T00:00:00Z')
        for path in derived.DERIVED_FILES:
            self.assertEqual((self.root / path).read_text(), 'current\n')
        self.assertEqual((self.root / 'README.md').read_text(),
                         'Updated prose\n' + derived.START + '\ncurrent\n' + derived.END + '\n')
        self.assertEqual(attributes.read_text(), '# original candidate attributes\n')
        self.assertEqual(git(self.root, 'rev-list', '--parents', '-1', 'HEAD').split()[1:], [before, incoming])

    def test_unchanged_source_bytes_and_current_totals_are_preserved_until_regeneration(self):
        progress = (self.root / derived.PROGRESS).read_bytes()
        readme = (self.root / 'README.md').read_bytes()
        self.write('README.md', readme.decode().replace('base totals', 'stale incoming totals'))
        incoming = self.commit()
        git(self.root, 'checkout', '--quiet', '--detach', self.base)
        derived.merge(self.root, incoming)
        self.assertEqual((self.root / derived.PROGRESS).read_bytes(), progress)
        self.assertEqual((self.root / 'README.md').read_bytes(), readme)

    def test_source_conflict_bounces_and_does_not_poison_next_input(self):
        self.write('source.txt', 'incoming source\n')
        incoming = self.tip(0, 'incoming')
        git(self.root, 'checkout', '--quiet', '--detach', self.base)
        self.write('source.txt', 'current source\n')
        before = self.tip(1, 'current')
        accepted, dropped = flow_tooling.merge(self.root, [dict(id='bad', revision=incoming, root=str(self.root))])
        self.assertFalse(accepted)
        self.assertEqual(len(dropped), 1)
        self.assertEqual(git(self.root, 'rev-parse', 'HEAD'), before)
        self.assertFalse(git(self.root, 'status', '--porcelain'))
        self.assertFalse((self.root / '.git/info/attributes').exists())

    def test_competing_row_edits_and_readme_prose_still_refuse(self):
        for kind in ('row', 'prose'):
            with self.subTest(kind=kind):
                git(self.root, 'reset', '--hard', self.base)
                incoming = self.tip(0, 'incoming', 'Incoming prose' if kind == 'prose' else None)
                git(self.root, 'checkout', '--quiet', '--detach', self.base)
                self.tip(1, 'current', 'Current prose' if kind == 'prose' else None)
                if kind == 'row':
                    data = flow.inventory(self.root)
                    data['functions'][0]['name'] = 'competing metadata'
                    self.progress(data)
                    self.commit()
                with self.assertRaisesRegex(flow.FlowError, 'conflicting source'):
                    derived.merge(self.root, incoming)

    def test_generated_modify_delete_conflict_does_not_bounce(self):
        incoming = self.tip(0, 'incoming')
        git(self.root, 'checkout', '--quiet', '--detach', self.base)
        git(self.root, 'rm', '--quiet', '--', 'docs/progress.svg')
        git(self.root, 'commit', '--quiet', '-m', 'delete synthetic generated view')
        derived.merge(self.root, incoming)
        self.assertFalse((self.root / 'docs/progress.svg').exists())

    def test_duplicate_rows_and_other_source_data_conflicts_refuse(self):
        for key in ('functions', 'phase'):
            ours, theirs = copy.deepcopy(self.data), copy.deepcopy(self.data)
            if key == 'functions':
                theirs[key].append(theirs[key][0])
            else:
                ours[key], theirs[key] = 'Ours', 'Theirs'
            with self.assertRaises(flow.FlowError):
                derived.merge_progress(self.data, ours, theirs)


class LaneDerivedIntegration(unittest.TestCase):
    setUp, enqueue, lane = lane_setup, enqueue, run_lane

    def test_tooling_push_regenerates_all_views_on_the_merged_inventory(self):
        # Concurrent origin and tooling change different rows and all generated files.
        data = flow.inventory(self.root)
        data['functions'][0]['name'] = 'Incoming synthetic name'
        (self.root / derived.PROGRESS).write_text(json.dumps(data))
        for name in derived.DERIVED_FILES | {'README.md'}:
            path = self.root / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text('stale incoming synthetic view\n')
        git(self.root, 'add', '--', derived.PROGRESS, *derived.DERIVED_FILES, 'README.md')
        git(self.root, 'commit', '--quiet', '-m', 'synthetic inventory tooling')
        item = flow_tooling.enqueue(self.root, self.fdir, 'main')
        other = self.tmp / 'concurrent'
        git(self.root, 'clone', '--quiet', '--branch', 'main', str(self.repo.origin), str(other))
        git(other, 'config', 'user.name', 'Synthetic')
        git(other, 'config', 'user.email', 'synthetic@example.invalid')
        data = flow.inventory(other)
        data['functions'][1]['name'] = 'Current synthetic name'
        (other / derived.PROGRESS).write_text(json.dumps(data))
        for name in derived.DERIVED_FILES:
            path = other / name
            path.parent.mkdir(parents=True, exist_ok=True)
            path.write_text('stale current synthetic view\n')
        git(other, 'add', '--', derived.PROGRESS, *derived.DERIVED_FILES)
        git(other, 'commit', '--quiet', '-m', 'synthetic concurrent inventory')
        git(other, 'push', '--quiet', 'origin', 'main')
        result = self.lane()
        self.assertFalse(result['tooling_dropped'])
        self.assertEqual(result['tooling_accepted'][0]['id'], item['id'])
        self.assertEqual(result['integrated']['ci'], 'green')
        tree = Path(result['tree'])
        merged = flow.inventory(tree)
        self.assertEqual([fn['name'] for fn in merged['functions'][:2]],
                         ['Incoming synthetic name', 'Current synthetic name'])
        for name in derived.DERIVED_FILES | {'README.md'}:
            self.assertEqual((tree / name).read_bytes(), (tree / derived.PROGRESS).read_bytes())
        self.assertTrue(git(tree, 'merge-base', '--is-ancestor', item['revision'], 'HEAD') == '')


if __name__ == '__main__':
    unittest.main()
