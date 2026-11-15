"""Readiness checks precede primary, second-pass and family Reviewer dispatch; synthetic only."""
import contextlib
import io
import json
from pathlib import Path
import sys
import tempfile
import unittest
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]
sys.path[:0] = [str(ROOT / 'tools'), str(ROOT / 'tests')]
import flow
import lint_review_readiness as lint
import test_flow as fixtures


class ReadinessDispatch(unittest.TestCase):
    def test_four_grounds_have_mechanical_findings(self):
        cases = (
            ('plausible_source', lint.plausible_source_problems('Synthetic.cpp', 'int param_1;')),
            ('provenance', lint.origin_statement_problems('Synthetic.cpp', '// Source exposure: binary-analysis\n')),
            ('publication_hygiene', lint.truncated_mit_problems('Synthetic.h', '// MIT License\n')),
            ('claim_scope', lint.claim_scope_problems('Synthetic.cpp', '// This proves semantic equivalence.\n')),
        )
        for ground, findings in cases:
            with self.subTest(ground=ground):
                self.assertTrue(findings)
        self.assertEqual(lint.plausible_source_problems('Synthetic.cpp', 'int count;'), [])
        self.assertEqual(lint.claim_scope_problems('Synthetic.cpp', '// Byte match only; names remain guesses.'), [])

    def test_cli_runs_existing_lint_without_weakening_it(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            path = root / 'Synthetic.cpp'
            path.write_text('// Origin: original work.\nint local_28;\n')
            with patch.object(lint.existing, 'lint_tree', return_value=['existing lint failure']) as existing, \
                    contextlib.redirect_stdout(io.StringIO()) as out:
                self.assertEqual(lint.main(['--root', str(root), 'Synthetic.cpp']), 1)
            existing.assert_called_once_with(root, ['Synthetic.cpp'])
            self.assertIn('existing lint failure', out.getvalue())
            self.assertIn('plausible_source', out.getvalue())

    def test_next_actions_orders_lint_before_each_primary_and_sample_dispatch(self):
        with tempfile.TemporaryDirectory() as directory:
            repo = fixtures.Repo(Path(directory))
            with patch('claims.sync_safe'), patch('claims.cached', return_value=(fixtures.github_claims.ClaimIndex(), None)):
                flow.review_group(repo.root, repo.fdir)
                actions = flow.next_actions(repo.root, repo.fdir, online=False)
            reviews = [(i, text) for i, (kind, text) in enumerate(actions)
                       if kind == 'dispatch' and 'Reviewer for' in text]
            self.assertGreaterEqual(len(reviews), 2)
            for i, text in reviews:
                kind, command = actions[i-1]
                self.assertEqual(kind, 'run')
                self.assertIn('lint_review_readiness.py', command)
                for ground in ('plausible_source', 'provenance', 'publication_hygiene', 'claim_scope'):
                    self.assertIn(ground, command)
                self.assertIn('only after', text.lower())
            for group in flow.groups(repo.fdir).values():
                brief = (repo.root / group['brief']).read_text()
                self.assertIn('before dispatching this Reviewer', brief)


if __name__ == '__main__':
    unittest.main()
