"""p123 adapter: CI hash status is an extra advisory signal, never acceptance evidence.

The caller must supply GitHub's check-run API response (not PR-controlled JSON). A PR workflow
can itself be replaced: even a successful exact-head check is untrusted for acceptance. Intake,
two-host local comparison, independent Reviewer and integration still run unconditionally.
"""
WORKFLOW_JOB = 'target-hashes'


def advisory_hash_signal(check_runs, head_sha):
    runs = [r for r in check_runs if r.get('head_sha') == head_sha
            and r.get('name') == WORKFLOW_JOB
            and r.get('app', {}).get('slug') == 'github-actions']
    if not runs:
        state = 'absent'
    else:
        latest = max(runs, key=lambda r: r['id'])
        state = (latest.get('conclusion') or 'pending') if latest.get('status') == 'completed' else 'pending'
    return dict(kind='target-hash-ci', head_sha=head_sha, state=state, advisory=True,
                acceptance='not-evaluated')
