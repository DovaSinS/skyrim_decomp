"""Fast checks before registering a tooling publication."""
from pathlib import Path
import subprocess
import sys


def preflight(root, main_checkout, rebase=False):
    root, main_checkout = Path(root).resolve(), Path(main_checkout).resolve()
    rebased = False

    def result(problem=None):
        return dict(ok=problem is None, problem=problem, rebased=rebased)

    def git(where, *args):
        return subprocess.run(['git', '-C', str(where), *args], capture_output=True, text=True)

    fetched = git(main_checkout, 'fetch', 'origin', 'main')
    if fetched.returncode:
        return result('fetch failed: ' + (fetched.stderr.strip() or fetched.stdout.strip()))
    sha = git(main_checkout, 'rev-parse', 'origin/main')
    if sha.returncode:
        return result('cannot resolve origin/main: ' + sha.stderr.strip())
    ci = subprocess.run([sys.executable, 'tools/ci_status.py', '--without-advisory',
                         '--commit', sha.stdout.strip()], cwd=main_checkout, capture_output=True, text=True)
    if ci.returncode:
        lines = (ci.stdout or ci.stderr).splitlines()
        return result('main is not green: ' + (lines[0] if lines else 'no output'))
    ahead = git(main_checkout, 'rev-list', '--count', 'origin/main..HEAD')
    changes = git(main_checkout, 'status', '--porcelain', '--', 'tools', 'tests')
    if ahead.returncode or changes.returncode or ahead.stdout.strip() != '0' or changes.stdout.strip():
        return result('main checkout has unpublished changes')
    fetched_input = git(root, 'fetch', 'origin', 'main')
    if fetched_input.returncode:
        return result('input fetch failed: ' + fetched_input.stderr.strip())
    ancestor = git(root, 'merge-base', '--is-ancestor', sha.stdout.strip(), 'HEAD')
    if ancestor.returncode:
        if not rebase:
            return result('input is based on an old main; rerun with --rebase')
        if root == main_checkout:
            return result('cannot rebase the main checkout')
        attempt = git(root, 'rebase', sha.stdout.strip())
        if attempt.returncode:
            files = git(root, 'diff', '--name-only', '--diff-filter=U').stdout.strip().splitlines()
            git(root, 'rebase', '--abort')
            return result('rebase conflict: ' + (', '.join(files) or attempt.stderr.strip()))
        rebased = True
    return result()
