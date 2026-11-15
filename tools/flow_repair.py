"""Explicit, recorded, tooling-only repairs of known failed advisory workflow inputs.

This is not a green result for the base. Full checks, FF push and new-head CI remain mandatory.
Required/unknown workflow failures, pending CI, stale SHAs and unrelated changes fail closed.
"""
import datetime as dt
import json
import re
import subprocess

import flow as f

# Keep this deliberately scoped. A new repairable workflow needs an explicit reviewed mapping;
# this option cannot suppress Infrastructure/Pages or change comparator/acceptance evidence.
INPUTS = {
    'Advisory target hashes': (
        '.gitattributes', '.github/workflows/ci-target-hash.yml',
        'tools/target_hashes.py', 'tools/ci_target_hash_check.py', 'tools/ci_toolchain.py',
        'tools/ci_hash_check.py', 'tools/ci_msvc_install.ps1', 'tools/toolchain/',
        'data/target-hashes/'),
    'Public MSVC hash self-test': (
        '.gitattributes', '.github/workflows/ci-hash-check.yml',
        'tools/ci_hash_check.py', 'tools/ci_msvc_install.ps1', 'tools/ci_toolchain.py',
        'tools/toolchain/'),
}
SUPPORT = ('docs/ci-hash-check.md', 'tests/test_target_hashes.py', 'tests/test_ci_toolchain.py')


def validate_sha(value):
    f.refuse(isinstance(value, str) and re.fullmatch(r'[0-9a-f]{40}', value),
             '--repair-red requires the exact full lowercase red SHA')
    return value


def matches(path, patterns):
    return any(path.startswith(pattern) if pattern.endswith('/') else path == pattern for pattern in patterns)


def approve(root, base, candidate, red_sha, python, ci_wait):
    validate_sha(red_sha)
    f.refuse(base == red_sha, 'repair red SHA is no longer origin head; inspect the new base')
    result = subprocess.run([python, 'tools/ci_status.py', '--commit', base, '--wait', str(ci_wait), '--json'],
                            cwd=root, capture_output=True, text=True)
    try:
        report = json.loads(result.stdout)
    except ValueError:
        raise f.FlowError('repair CI status is not available as JSON') from None
    f.refuse(result.returncode == 1 and report.get('commit') == base and report.get('result') == 'red',
             'repair requires reproduced RED CI for the exact origin SHA')
    runs = report.get('runs', [])
    f.refuse(runs and all(r.get('status') == 'completed' for r in runs),
             'repair cannot bypass missing or pending CI')
    failed = [r for r in runs if r.get('conclusion') not in ('success', 'skipped', 'neutral')]
    f.refuse(failed and all(r.get('workflow') in INPUTS for r in failed),
             'required or unknown workflow failure is not eligible for advisory repair')
    workflows = sorted({r['workflow'] for r in failed})
    changed = f.git(root, 'diff', '--name-only', base, candidate).splitlines()
    patterns = tuple(p for name in workflows for p in INPUTS[name])
    f.refuse(changed and all(matches(path, patterns + SUPPORT) for path in changed),
             'repair contains unrelated paths or function acceptance changes')
    for workflow in workflows:
        f.refuse(any(matches(path, INPUTS[workflow]) for path in changed),
                 'repair must touch actual inputs of every failed workflow')
    return dict(red_sha=base, candidate=candidate, workflows=workflows,
                run_ids=[r['run_id'] for r in failed], changed_paths=changed,
                observed_at=dt.datetime.now(dt.timezone.utc).isoformat())


WORKFLOW_FILES = {'Advisory target hashes': 'ci-target-hash.yml',
                  'Public MSVC hash self-test': 'ci-hash-check.yml'}


def dispatch(root, branch, repair):
    """Called under the lane lease, before releasing the freshly pushed branch for other work."""
    for workflow in repair['workflows']:
        result = subprocess.run(['gh', 'workflow', 'run', WORKFLOW_FILES[workflow], '--ref', branch],
                                cwd=root, capture_output=True, text=True)
        f.refuse(result.returncode == 0, 'repair workflow dispatch failed; resume its receipt')
    return dt.datetime.now(dt.timezone.utc).isoformat()
