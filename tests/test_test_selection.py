"""Local selection never narrows CI; dependency and uncertain-edge fixtures are original."""
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import test_selection as selection


class Selection(unittest.TestCase):
    def setUp(self):
        tmp = tempfile.TemporaryDirectory(prefix='test-selection-')
        self.addCleanup(tmp.cleanup)
        self.root = Path(tmp.name)
        self.git('init', '--quiet')
        self.git('config', 'user.name', 'Synthetic')
        self.git('config', 'user.email', 'synthetic@example.invalid')
        for path, text in {
            'tools/leaf.py': 'VALUE = 1\n',
            'tools/helper.py': 'from leaf import VALUE\n',
            'tests/test_direct.py': 'import leaf\n',
            'tests/test_transitive.py': 'from helper import VALUE\n',
            'tests/test_unrelated.py': 'import unittest\n',
            'tests/test_dynamic.py': 'from importlib import import_module as load\nload(input())\n',
            'tests/test_command.py': 'import subprocess as sp\nsp.run(input())\n',
            'tests/test_file.py': 'from pathlib import Path\nPath(input()).read_text()\n',
            '.gitignore': '.local/\n',
        }.items():
            self.write(path, text)
        self.modules = {path.stem for path in (self.root / 'tests').glob('test_*.py')}
        self.base = self.commit()

    def git(self, *args):
        return subprocess.check_output(['git', *args], cwd=self.root, text=True).strip()

    def write(self, path, text):
        target = self.root / path
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_text(text)

    def commit(self):
        self.git('add', '--all')
        self.git('commit', '--quiet', '-m', 'original synthetic dependency fixture')
        return self.git('rev-parse', 'HEAD')

    def selected(self):
        self.commit()
        return selection.select(self.root, self.base, 'HEAD', self.modules)

    def test_tool_changes_run_every_module_including_unrelated_and_opaque_callers(self):
        self.write('tools/leaf.py', 'VALUE = 2\n')
        selected, reason = self.selected()
        self.assertEqual(selected, self.modules)
        self.assertTrue(reason.startswith('full:'))

    def test_removed_import_and_deleted_module_keep_the_old_test_edges(self):
        self.write('tests/test_direct.py', '# import removed\n')
        self.write('tools/helper.py', '# transitive import removed\n')
        (self.root / 'tools/leaf.py').unlink()
        selected, _ = self.selected()
        self.assertTrue({'test_direct', 'test_transitive'} <= selected)

    def test_relative_package_import_and_subprocess_literal_paths(self):
        self.write('tools/pkg/__init__.py', '')
        self.write('tools/pkg/leaf.py', 'VALUE = 1\n')
        self.write('tools/pkg/helper.py', 'from . import leaf\n')
        self.write('tests/test_direct.py', 'import pkg.helper\n')
        self.write('tests/test_transitive.py', 'COMMAND = "tools/pkg/leaf.py"\n')
        self.base = self.commit()
        self.write('tools/pkg/leaf.py', 'VALUE = 2\n')
        selected, reason = self.selected()
        self.assertTrue({'test_direct', 'test_transitive'} <= selected)
        self.assertTrue(reason.startswith('full:'))

    def test_changed_test_is_always_selected(self):
        self.write('tests/test_unrelated.py', 'import unittest\n# changed test\n')
        selected, _ = self.selected()
        self.assertIn('test_unrelated', selected)

    def test_computed_self_path_stays_opaque_even_in_a_fixture_owning_module(self):
        self.write('tests/test_computed.py', '''import tempfile
from pathlib import Path
class T:
 def setup(self):
  self.tmp = tempfile.TemporaryDirectory()
  self.root = Path(__file__).resolve().parents[1] / "tools"
  self.name = "leaf" + ".py"
 def test_source(self):
  return (self.root / self.name).read_text()
''')
        self.modules.add('test_computed')
        self.base = self.commit()
        self.write('tools/leaf.py', 'VALUE = 3\n')
        selected, reason = self.selected()
        self.assertIn('test_direct', selected)
        self.assertIn('test_computed', selected)
        self.assertTrue(reason.startswith('full:'))

    def test_computed_file_reads_through_helpers_and_git_show_are_also_opaque(self):
        self.write('tools/reader.py', 'def read(path):\n return path.read_text()\n')
        self.write('tests/test_reader.py', 'from reader import read\n')
        self.write('tests/test_git.py', 'import subprocess as sp\n'
                   'def read(path):\n return sp.check_output(["git", "show", path])\n')
        self.modules.update({'test_reader', 'test_git'})
        self.base = self.commit()
        self.write('tools/leaf.py', 'VALUE = 4\n')
        selected, reason = self.selected()
        self.assertTrue({'test_direct', 'test_reader', 'test_git'} <= selected)
        self.assertTrue(reason.startswith('full:'))

    def test_unmapped_and_unparseable_inputs_fall_back_to_full(self):
        for path, text in [('tools/new.py', 'VALUE = 1\n'), ('tools/leaf.py', 'not Python!!!')]:
            with self.subTest(path=path):
                self.git('reset', '--hard', self.base)
                self.write(path, text)
                selected, reason = self.selected()
                self.assertEqual(selected, self.modules)
                self.assertTrue(reason.startswith('full:'))

    def test_shared_core_changes_always_run_the_full_inventory(self):
        for path in ['tools/check.py', 'tools/check_source_digest.py', 'tools/flow_lane.py',
                     'tools/accept_function.py', 'tools/verifier/compare.py', 'tools/test_suite.py',
                     'tools/test_selection.py', 'tools/source_digest.py', 'tools/revision_cache.py',
                     'tools/compare.py', 'tools/compare_internal.py', 'tools/pecoff.py']:
            with self.subTest(path=path):
                self.write(path, '# original synthetic core change\n')
                selected, reason = self.selected()
                self.assertEqual(selected, self.modules)
                self.assertTrue(reason.startswith('full:'))

    def test_workflow_and_recipe_references_select_covering_modules(self):
        for path in ['.github/workflows/synthetic.yml', 'reconstruction/recipes/synthetic.json']:
            with self.subTest(path=path):
                self.git('reset', '--hard', self.base)
                self.write('tests/test_direct.py', 'INPUT = ' + repr(path) + '\n')
                self.write(path, '{}\n')
                self.base = self.commit()
                self.write(path, '{"changed":true}\n')
                selected, reason = self.selected()
                self.assertIn('test_direct', selected)
                self.assertTrue(reason.startswith('full:'), reason)

    def test_reconstruction_reports_and_all_derived_views_need_no_local_unit_tests(self):
        for path in ['reconstruction/a/A.cpp', 'reconstruction/a/A.h', 'reports/synthetic/report.json',
                     'data/progress.json', *selection.DERIVED]:
            self.write(path, 'original synthetic metadata\n')
        selected, reason = self.selected()
        self.assertEqual(selected, set())
        self.assertIn('full suite in CI', reason)

    def test_generated_readme_totals_only_and_renamed_tool_is_not_a_source_only_push(self):
        self.write('README.md', 'prose<!-- model-trend-totals -->old<!-- /model-trend-totals -->')
        self.base = self.commit()
        self.write('README.md', 'prose<!-- model-trend-totals -->new<!-- /model-trend-totals -->')
        self.assertEqual(self.selected()[0], set())
        self.write('README.md', 'different prose<!-- model-trend-totals -->new<!-- /model-trend-totals -->')
        self.assertEqual(self.selected()[0], self.modules)
        self.git('reset', '--hard', self.base)
        (self.root / 'reconstruction').mkdir()
        self.git('mv', 'tools/leaf.py', 'reconstruction/leaf.py')
        selected, _ = self.selected()
        self.assertIn('test_direct', selected)

    def test_no_base_keeps_the_full_inventory(self):
        self.assertEqual(selection.select(self.root, None, 'HEAD', self.modules)[0], self.modules)


if __name__ == '__main__':
    unittest.main()
