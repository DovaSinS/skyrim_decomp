"""Honest local scheduling: source/metadata-only exemption, otherwise the full suite.

Exact-SHA CI always runs the complete inventory. Dynamic imports, generated commands and
computed file reads make a partial Python dependency graph insufficient to exclude tests.
"""
import subprocess

DERIVED = frozenset({'reconstruction/INDEX.md', 'LEADERBOARD.md', 'data/contributors.json',
                     'docs/progress.svg', 'docs/progress-map.svg', 'docs/model-trend.svg',
                     'docs/progress-trend.svg'})


def git(root, *args):
    return subprocess.check_output(['git', *args], cwd=root, stderr=subprocess.PIPE)


def changed(root, base, revision='HEAD'):
    # No rename inference: a rename retains both the deleted and added dependency identities.
    return [p.decode() for p in git(root, 'diff', '--no-renames', '--name-only', '-z', base, revision).split(b'\0') if p]


def source_only(root, base, revision='HEAD'):
    if not base:
        return False
    paths = changed(root, base, revision)
    for path in paths:
        if path.endswith('.py'):
            return False
        if path.startswith('reconstruction/recipes/'):
            return False
        if path.startswith(('reconstruction/', 'reports/')) or path in DERIVED | {'data/progress.json'}:
            continue
        if path == 'README.md':
            start, end = '<!-- model-trend-totals -->', '<!-- /model-trend-totals -->'
            def outside(ref):
                text = git(root, 'show', ref + ':README.md').decode()
                if text.count(start) != 1 or text.count(end) != 1:
                    return None
                before, rest = text.split(start)
                if end not in rest:
                    return None
                return before, rest.split(end)[1]
            try:
                before, after = outside(base), outside(revision)
            except subprocess.CalledProcessError:
                return False
            if before is not None and before == after:
                continue
        return False
    return bool(paths)


def select(root, base, revision, modules):
    """Never exclude a tooling test based on incomplete dependency inference."""
    if not base:
        return set(modules), 'full: no comparison base'
    try:
        if source_only(root, base, revision):
            return set(), 'source/metadata only: validator, acceptance, derived views and site; full suite in CI'
    except (ValueError, UnicodeError, OSError, subprocess.CalledProcessError):
        return set(modules), 'full: comparison unavailable'
    return set(modules), 'full: non-source change (dynamic dependencies are not inferred)'
