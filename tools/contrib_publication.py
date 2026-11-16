"""Screen exactly the contributor material a publication method will retain.

Squash is the outside-intake default: inspect tip blobs and the squashed diff. A history-
preserving merge also screens every retained ancestor. No PR hooks or tools are executed.
"""
from pathlib import Path
import re
import subprocess

from contrib_screen import MAX_BYTES, STANDARD_HEADERS, screen

UNIT = re.compile(r'reconstruction/([a-z][a-z0-9_]*)/([A-Z][A-Za-z0-9_]*)\.(h|cpp)\Z')
SHA = re.compile(r'[0-9a-f]{40}\Z')


class PublicationRejected(ValueError):
    """A fixed, publication-safe reason; never include source or Git diagnostics."""


def screen_publication(root, base, head, *, merge_method='squash', headers=STANDARD_HEADERS,
                       max_files=120, git=None):
    """Return files, diff, merge_method and resolved base/head; raise on refused content.

    Optional git(*args) returns bytes and lets intake keep command diagnostics in its private
    log. Transport/process errors propagate: they are retryable, not completed rejections.
    Callers still screen the complete tip include closure and apply lint/readiness/review gates.
    """
    if merge_method not in ('squash', 'merge'):
        raise PublicationRejected('unsupported contributor merge method')
    if git is None:
        def git(*args):
            return subprocess.run(['git', *args], cwd=Path(root), check=True,
                                  capture_output=True, timeout=120).stdout
    base = git('rev-parse', '--verify', '--end-of-options', str(base) + '^{commit}').decode().strip()
    head = git('rev-parse', '--verify', '--end-of-options', str(head) + '^{commit}').decode().strip()
    if not SHA.fullmatch(base) or not SHA.fullmatch(head):
        raise PublicationRejected('invalid contributor publication revision')
    rows = git('diff', '--name-status', '--no-renames', f'{base}...{head}').decode().splitlines()
    files = []
    for row in rows:
        status, name = row.split('\t', 1)
        if status not in ('A', 'M') or not UNIT.fullmatch(name):
            raise PublicationRejected('PR scope includes unsupported paths, deletions or renames')
        files.append(dict(path=name, status=status))
    if not files:
        raise PublicationRejected('PR scope includes unsupported paths, deletions or renames')
    if len(files) > max_files:
        raise PublicationRejected('PR file-count resource cap exceeded')
    commits = [head]
    if merge_method == 'merge':
        commits = git('rev-list', '--reverse', f'{base}..{head}').decode().splitlines()
        if not 0 < len(commits) <= 100:
            raise PublicationRejected('PR history exceeds the 100-commit resource cap')
    diffs, total = [], 0
    for commit in commits:
        if merge_method == 'squash':
            names = [f['path'] for f in files]
            comparison = f'{base}...{head}'
        else:
            parents = git('rev-list', '--parents', '-n', '1', commit).decode().split()[1:]
            if len(parents) != 1:
                raise PublicationRejected('contributor merge commits need maintainer intake')
            names = git('diff-tree', '--no-commit-id', '--name-only', '-r', '--no-renames', commit).decode().splitlines()
            if any(not UNIT.fullmatch(n) for n in names):
                raise PublicationRejected('unpublished history changes files outside contributor scope')
            comparison = parents[0]
        for name in names:
            mode = git('ls-tree', commit, '--', name).decode().split()
            if not mode or mode[0] != '100644':
                raise PublicationRejected('non-regular source file or historical deletion')
            if int(git('cat-file', '-s', f'{commit}:{name}')) > MAX_BYTES:
                raise PublicationRejected('deterministic screen: file-size-cap')
            codes = screen(git('show', f'{commit}:{name}'), name, headers=headers)
            if codes:
                raise PublicationRejected('deterministic screen: ' + ', '.join(codes))
        args = ['diff', '--no-ext-diff', '--no-textconv', comparison]
        if merge_method == 'merge':
            args.append(commit)
        diff = git(*args, '--')
        total += len(diff)
        if total > 1024 * 1024:
            raise PublicationRejected('PR publication diff exceeds the 1 MiB screen cap')
        # Squash commit messages are project-generated; ancestor messages are not published.
        metadata = git('show', '-s', '--format=fuller', commit) if merge_method == 'merge' else b''
        diffs.append((metadata + b'\n' + diff).decode('utf-8'))
    return dict(files=files, diff='\n'.join(diffs), merge_method=merge_method, base=base, head=head)
