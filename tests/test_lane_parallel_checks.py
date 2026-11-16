"""Original subprocess fixtures: overlapping checks retain every failure and the site gate."""
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch

sys.path[:0] = [str(Path(__file__).resolve().parents[1] / 'tools')]
import flow
import flow_lane as lane
import flow_tooling
from test_flow import git
from test_flow_lane import PushLane as _Fixture

setup_lane, enqueue_lane, run_lane = _Fixture.setUp, _Fixture.enqueue, _Fixture.lane
del _Fixture


class ParallelChecks(unittest.TestCase):
    def setUp(self):
        tmp = tempfile.TemporaryDirectory(prefix='parallel-checks-')
        self.addCleanup(tmp.cleanup)
        self.root = Path(tmp.name)
        git(self.root, 'init', '--quiet')
        git(self.root, 'config', 'user.name', 'Synthetic')
        git(self.root, 'config', 'user.email', 'synthetic@example.invalid')
        (self.root / '.gitignore').write_text('.local/\ndist/\n')
        (self.root / 'tools').mkdir()
        # Check and suite must overlap; site waits for the check's exact-content metadata pass.
        script = '''from pathlib import Path
import sys, time
name = Path(__file__).stem
local = Path('.local'); local.mkdir(exist_ok=True)
(local / (name + '.started')).touch()
deadline = time.monotonic() + 5
while len(list(local.glob('*.started'))) < 2:
 if time.monotonic() > deadline: raise RuntimeError('checks did not overlap')
 time.sleep(0.01)
if name == 'build_site': assert (local / 'check.finished').exists()
(local / (name + '.finished')).touch()
if (local / (name + '.fail')).exists(): sys.exit(1)
if (local / (name + '.mutate')).exists(): Path('tracked.txt').write_text('changed')
print('synthetic ' + name)
'''
        for name in ('check', 'test_suite', 'build_site'):
            (self.root / 'tools' / (name + '.py')).write_text(script)
        (self.root / 'tracked.txt').write_text('original')
        git(self.root, 'add', '--', '.gitignore', 'tools', 'tracked.txt')
        git(self.root, 'commit', '--quiet', '-m', 'original synthetic checks')
        self.commit = git(self.root, 'rev-parse', 'HEAD')
        self.logs = self.root / '.local/logs'

    def checks(self):
        return flow.pre_push_checks(self.root, self.commit, sys.executable,
                                    candidate=True, log_dir=self.logs)

    def test_check_and_suite_overlap_with_site_after_check_and_individual_logs_and_timings(self):
        self.checks()
        report = json.loads((self.logs / 'timings.json').read_text())
        self.assertEqual(set(report['stages']), {'check', 'tests', 'site'})
        for name, result in report['stages'].items():
            self.assertTrue(result['passed'])
            self.assertGreaterEqual(result['seconds'], 0)
            self.assertIn('synthetic', (self.logs / (name + '.log')).read_text())
        self.assertLessEqual(max(v['seconds'] for v in report['stages'].values()), report['seconds'])

    def test_each_original_failure_blocks_and_all_started_checks_are_joined(self):
        for tool, stage in (('check', 'check'), ('test_suite', 'tests'), ('build_site', 'site')):
            with self.subTest(stage=stage):
                local = self.root / '.local'
                local.mkdir(exist_ok=True)
                for path in local.glob('*.*'):
                    path.unlink()
                (local / (tool + '.fail')).touch()
                with self.assertRaises(flow.FlowError):
                    self.checks()
                self.assertEqual(len(list(local.glob('*.finished'))), 3)
                report = json.loads((self.logs / 'timings.json').read_text())
                self.assertFalse(report['stages'][stage]['passed'])
                self.assertEqual(sum(v['passed'] for v in report['stages'].values()), 2)

    def test_tracked_mutation_still_blocks_after_all_checks(self):
        (self.root / '.local').mkdir()
        (self.root / '.local/build_site.mutate').touch()
        with self.assertRaisesRegex(flow.FlowError, 'checks changed tracked candidate files'):
            self.checks()

    def test_dirty_or_wrong_commit_never_starts_a_check(self):
        (self.root / 'tracked.txt').write_text('dirty')
        with self.assertRaisesRegex(flow.FlowError, 'differs from its commit'):
            self.checks()
        self.assertFalse(self.logs.exists())
        git(self.root, 'checkout', '--', 'tracked.txt')
        with self.assertRaisesRegex(flow.FlowError, 'differs from its commit'):
            flow.pre_push_checks(self.root, '0' * 40, sys.executable, candidate=True)
        self.assertFalse(self.logs.exists())


class SiteOnce(unittest.TestCase):
    setUp, enqueue, lane = setup_lane, enqueue_lane, run_lane

    def test_function_lane_builds_site_once_and_records_build_and_check_stages(self):
        self.enqueue()
        with patch.object(flow, 'run', wraps=flow.run) as commands:
            result = self.lane()
        sites = [c for c in commands.call_args_list if 'tools/build_site.py' in c.args[0]]
        self.assertEqual(len(sites), 1)
        self.assertEqual(result['integrated']['ci'], 'green')
        self.assertTrue({'clone_fetch_checkout', 'tooling_merge', 'integrate', 'staged_guard', 'commit'}
                        <= result['build_wall_seconds'].keys())
        self.assertIn('push', result['integrated']['wall_seconds'])
        report = json.loads((Path(result['checks_log_dir']) / 'timings.json').read_text())
        # This fixture creates a README without generated markers, so it correctly stays full.
        self.assertEqual(set(report['stages']), {'check', 'tests', 'site'})

    def test_tooling_lane_builds_site_once_and_requires_full_suite(self):
        (self.root / 'new-tool.txt').write_text('original synthetic tooling')
        git(self.root, 'add', '--', 'new-tool.txt')
        git(self.root, 'commit', '--quiet', '-m', 'synthetic tooling')
        flow_tooling.enqueue(self.root, self.fdir, 'main')
        with patch.object(flow, 'run', wraps=flow.run) as commands:
            result = self.lane()
        self.assertEqual(sum('tools/build_site.py' in c.args[0] for c in commands.call_args_list), 1)
        report = json.loads((Path(result['checks_log_dir']) / 'timings.json').read_text())
        self.assertEqual(set(report['stages']), {'check', 'tests', 'site'})
        self.assertTrue(all(v['passed'] for v in report['stages'].values()))

    def test_site_failure_still_prevents_function_push(self):
        (self.root / 'tools/build_site.py').write_text('raise RuntimeError("synthetic site failure")\n')
        git(self.root, 'add', '--', 'tools/build_site.py')
        git(self.root, 'commit', '--quiet', '-m', 'synthetic site refusal')
        git(self.root, 'push', '--quiet', 'origin', 'HEAD:main')
        before = git(self.repo.origin, 'rev-parse', 'main')
        self.enqueue()
        with self.assertRaisesRegex(flow.FlowError, 'build_site.py'):
            self.lane()
        self.assertEqual(git(self.repo.origin, 'rev-parse', 'main'), before)


if __name__ == '__main__':
    unittest.main()
