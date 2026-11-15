"""Lane runtime identity against a real local remote; all inputs are synthetic."""
from pathlib import Path
import shutil
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

from test_flow import Repo, flow, git
import flow_lane as lane


class LaneToolFreshness(unittest.TestCase):
    def setUp(self):
        self.tmp = Path(tempfile.mkdtemp()).resolve()
        self.addCleanup(shutil.rmtree, self.tmp)
        self.repo = Repo(self.tmp)
        self.root, self.fdir = self.repo.root, self.repo.fdir
        for name in ('flow.py', 'flow_lane.py', 'lane_accept.py', 'helper.py', 'profiles.json'):
            (self.root / 'tools' / name).write_text('# Original synthetic tool\n')
        git(self.root, 'add', 'tools')
        git(self.root, 'commit', '--quiet', '-m', 'synthetic lane runtime')
        git(self.root, 'push', '--quiet', 'origin', 'main')
        self.base = git(self.root, 'rev-parse', 'HEAD')
        self.runner = self.tmp / 'base-runtime'
        git(self.root, 'clone', '--quiet', '--branch', 'main', str(self.repo.origin), str(self.runner))
        tools = patch.object(flow, 'TOOLS', self.runner / 'tools')
        tools.start()
        self.addCleanup(tools.stop)
        loaded = patch.object(flow, 'LANE_TOOL_SOURCES', flow.lane_tool_sources())
        loaded.start()
        self.addCleanup(loaded.stop)

    def advance(self, path='tools/helper.py'):
        (self.root / path).write_text('# Updated original synthetic tool\n')
        git(self.root, 'add', path)
        git(self.root, 'commit', '--quiet', '-m', 'update synthetic dependency')
        git(self.root, 'push', '--quiet', 'origin', 'main')

    def test_current_base_runtime_accepts_an_old_input_checkout(self):
        git(self.root, 'checkout', '--quiet', '--detach', 'HEAD~1')
        self.assertEqual(lane.require_base_tools(self.root), self.base)

    def test_stale_lane_entrypoints_and_transitive_dependencies_are_refused(self):
        for name in ('flow.py', 'flow_lane.py', 'lane_accept.py', 'helper.py', 'profiles.json'):
            path = self.runner / 'tools' / name
            original = path.read_bytes()
            with self.subTest(name=name):
                path.write_text('# Stale synthetic runtime\n')
                with self.assertRaisesRegex(flow.FlowError, 'integration base .*tools/' + name):
                    lane.require_base_tools(self.root)
            path.write_bytes(original)

    def test_restoring_disk_does_not_refresh_already_loaded_modules(self):
        stale = dict(flow.LANE_TOOL_SOURCES, **{'tools/helper.py': '0' * 40})
        with patch.object(flow, 'LANE_TOOL_SOURCES', stale):
            with self.assertRaisesRegex(flow.FlowError, 'tools/helper.py'):
                lane.require_base_tools(self.root)

    def test_added_deleted_and_nested_imports_are_checked(self):
        extra = self.runner / 'tools/verifier/shadow.py'
        extra.parent.mkdir()
        extra.write_text('# Original synthetic shadow import\n')
        with self.assertRaisesRegex(flow.FlowError, 'tools/verifier/shadow.py'):
            lane.require_base_tools(self.root)
        extra.unlink()
        (self.runner / 'tools/helper.py').unlink()
        with self.assertRaisesRegex(flow.FlowError, 'tools/helper.py'):
            lane.require_base_tools(self.root)

    def test_stale_start_refuses_before_queue_or_receipt_mutation(self):
        self.advance()
        for entry in (lane.run_lane, lane.publish_tooling, lane._publish_legacy_tooling):
            with self.subTest(entry=entry.__name__), patch('flow_cleanup.automatic_retention') as cleanup:
                with self.assertRaisesRegex(flow.FlowError, 'tools/helper.py'):
                    entry(self.root, self.fdir, python=sys.executable)
                cleanup.assert_not_called()
                self.assertFalse((self.fdir / 'lane').exists())

    def test_cli_stale_runtime_has_actionable_refusal_without_traceback(self):
        entry = Path(__file__).resolve().parents[1] / 'tools/flow.py'
        for command in ('lane-run', 'tooling-push'):
            with self.subTest(command=command):
                result = subprocess.run([sys.executable, str(entry), '--root', str(self.root),
                                         '--flow-dir', str(self.fdir), command, '--no-wait-lane'],
                                        capture_output=True, text=True, timeout=15)
                self.assertEqual(result.returncode, 1)
                self.assertIn('lane tooling differs from integration base', result.stderr)
                self.assertIn('--root', result.stderr)
                self.assertNotIn('Traceback', result.stderr)
                self.assertFalse((self.fdir / 'lane').exists())

    def test_base_is_rechecked_after_waiting_for_build_lease(self):
        def wait(*args):
            if git(self.root, 'rev-parse', 'HEAD') == self.base:
                self.advance()
        with patch.object(lane, 'wait_for_owner', side_effect=wait), \
                patch.object(lane, 'disk_preflight'), patch.object(lane, 'recover_stale') as recover:
            with self.assertRaisesRegex(flow.FlowError, 'tools/helper.py'):
                lane.run_lane(self.root, self.fdir, python=sys.executable)
            recover.assert_not_called()
        self.assertFalse(list((self.fdir / 'lane/runs').glob('*.json')))

    def test_new_build_refuses_updated_origin_before_merging_any_input(self):
        self.advance()
        receipt = dict(id='synthetic-freshness', items=[], tooling=[], state='running')
        with patch.object(lane.resource_admission, 'admit'), patch('flow_tooling.merge') as merge:
            with self.assertRaisesRegex(flow.FlowError, 'tools/helper.py'):
                lane.build(self.root, self.fdir, receipt, sys.executable, 'main')
            merge.assert_not_called()

    def test_origin_dependency_advance_during_checks_prevents_push(self):
        (self.root / 'tooling.txt').write_text('Original synthetic candidate\n')
        git(self.root, 'add', 'tooling.txt')
        git(self.root, 'commit', '--quiet', '-m', 'synthetic candidate')
        # Advance from a separate checkout so the queued input stays immutable.
        other = self.tmp / 'concurrent'
        git(self.root, 'clone', '--quiet', '--branch', 'main', str(self.repo.origin), str(other))
        git(other, 'config', 'user.name', 'Synthetic')
        git(other, 'config', 'user.email', 'synthetic@example.invalid')
        def checks(*args, **kwargs):
            (other / 'tools/helper.py').write_text('# New origin dependency\n')
            git(other, 'add', 'tools/helper.py')
            git(other, 'commit', '--quiet', '-m', 'advance origin tools')
            git(other, 'push', '--quiet', 'origin', 'main')
        with patch.object(flow, 'pre_push_checks', side_effect=checks), \
                patch('flow_cleanup.automatic_retention'), patch.object(lane.resource_admission, 'admit'), \
                patch.object(lane, 'disk_preflight'):
            with self.assertRaisesRegex(flow.FlowError, 'tools/helper.py'):
                lane.publish_tooling(self.root, self.fdir, python=sys.executable, ci_wait=0)
        self.assertEqual(git(self.repo.origin, 'rev-parse', 'main'), git(other, 'rev-parse', 'HEAD'))
        self.assertNotIn('tooling.txt', git(other, 'ls-tree', '--name-only', 'HEAD'))

    def test_tooling_change_uses_base_runtime_and_checks_its_candidate(self):
        # A tooling candidate intentionally differs from the running base's tools.
        (self.root / 'tools/helper.py').write_text('# Candidate original tooling\n')
        git(self.root, 'add', 'tools/helper.py')
        git(self.root, 'commit', '--quiet', '-m', 'candidate tooling change')
        candidate = git(self.root, 'rev-parse', 'HEAD')
        checked = []
        def checks(tree, commit, python, **kwargs):
            self.assertNotEqual(Path(tree), self.root)
            self.assertEqual((Path(tree) / 'tools/helper.py').read_text(), '# Candidate original tooling\n')
            self.assertEqual((flow.TOOLS / 'helper.py').read_text(), '# Original synthetic tool\n')
            checked.append(commit)
        with patch.object(flow, 'pre_push_checks', side_effect=checks), \
                patch('flow_cleanup.automatic_retention'), patch.object(lane.resource_admission, 'admit'), \
                patch.object(lane, 'disk_preflight'):
            result = lane.publish_tooling(self.root, self.fdir, python=sys.executable, ci_wait=0)
        self.assertEqual(result['state'], 'done')
        self.assertEqual(checked, [result['integrated']['commit']])
        self.assertEqual(result['integrated']['ci'], 'green')
        self.assertEqual(git(self.root, 'rev-parse', 'HEAD'), candidate)
        self.assertEqual(git(self.repo.origin, 'rev-parse', 'main'), checked[0])


if __name__ == '__main__':
    unittest.main()
