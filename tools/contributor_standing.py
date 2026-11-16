#!/usr/bin/env python3
"""Public handle strike ledger. Only a maintainer commits confirmed events or clears."""
import argparse
import json
import os
from pathlib import Path
import re
import urllib.request

from build_leaderboard import handle, standings

ROOT = Path(__file__).resolve().parents[1]
LEDGER = 'data/contributor-strikes.json'
LABEL = 'needs maintainer'


def validate(data):
    if set(data) != {'schema', 'contributors'} or data['schema'] != 1 or not isinstance(data['contributors'], dict):
        raise ValueError('invalid contributor ledger')
    for name, row in data['contributors'].items():
        if handle(name) != name or set(row) != {'false_claims', 'cleared_strikes'}:
            raise ValueError('invalid contributor record')
        events = row['false_claims']
        if not isinstance(events, list):
            raise ValueError('false claims must be a list')
        seen = set()
        for event in events:
            if (set(event) != {'pr', 'head', 'rvas', 'check_run'}
                    or type(event['pr']) is not int or event['pr'] < 1
                    or not isinstance(event['head'], str) or not re.fullmatch(r'[0-9a-f]{40}', event['head'])
                    or type(event['check_run']) is not int or event['check_run'] < 1
                    or not isinstance(event['rvas'], list) or not event['rvas']
                    or any(not isinstance(rva, str) or not re.fullmatch(r'0x[0-9a-f]+', rva) for rva in event['rvas'])
                    or len(set(event['rvas'])) != len(event['rvas']) or event['pr'] in seen):
                raise ValueError('invalid or duplicate false claim')
            seen.add(event['pr'])
        if type(row['cleared_strikes']) is not int or not 0 <= row['cleared_strikes'] <= len(events):
            raise ValueError('invalid cleared strikes')
    return data


def load(root):
    path = root / LEDGER
    return validate(json.loads(path.read_text())) if path.exists() else dict(schema=1, contributors={})


def standing(data, author):
    name = handle(author)
    if not name:
        raise ValueError('invalid public GitHub handle')
    row = data['contributors'].get(name, dict(false_claims=[], cleared_strikes=0))
    strikes = len(row['false_claims']) - row['cleared_strikes']
    return dict(handle=name, false_claims=len(row['false_claims']), strikes=strikes,
                auto_merge_eligible=strikes < 3, label=LABEL if strikes >= 3 else None)


def false_claims(report, claimed):
    """Only an explicit claim contradicted by a completed hash comparison is a false claim.

    Compile/setup errors, unsupported layouts, absent hashes and advisory passes are excluded.
    The caller must obtain the exact-head report from a trusted CI run, never from the PR.
    """
    if report.get('error') or report.get('toolset') != 'MATCH' or report.get('kind') != 'target-hash-check':
        return []
    return sorted({r['rva'] for r in report.get('functions', []) if r.get('rva') in claimed
                   and r.get('result') == 'mismatch' and not r.get('reason')})


def api(method, repository, path, body=None):
    request = urllib.request.Request('https://api.github.com/repos/' + repository + path,
                                    data=json.dumps(body).encode() if body is not None else None,
                                    method=method, headers={'Authorization': 'Bearer ' + os.environ['GH_TOKEN'],
                                                           'Accept': 'application/vnd.github+json',
                                                           'Content-Type': 'application/json'})
    with urllib.request.urlopen(request, timeout=30) as response:
        return json.load(response) if response.status != 204 else None


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--author')
    parser.add_argument('--event', type=Path)
    parser.add_argument('--record', type=Path, help='trusted exact-head CI report, verified by maintainer')
    parser.add_argument('--head')
    parser.add_argument('--pr', type=int)
    parser.add_argument('--check-run', type=int)
    parser.add_argument('--claimed', nargs='+', default=[], help='explicitly claimed RVAs from the PR')
    parser.add_argument('--clear', action='store_true', help='maintainer clears all active strikes')
    parser.add_argument('--apply-label', action='store_true')
    args = parser.parse_args(argv)
    event = json.loads(args.event.read_text()) if args.event else None
    data = load(ROOT)
    author = event['pull_request']['user']['login'] if event else args.author
    if args.record or args.clear:
        name = handle(author)
        if not name or event or (args.record and args.clear):
            parser.error('record/clear requires a public --author and one operation')
        row = data['contributors'].setdefault(name, dict(false_claims=[], cleared_strikes=0))
        if args.clear:
            row['cleared_strikes'] = len(row['false_claims'])
        else:
            report = json.loads(args.record.read_text())
            rvas = false_claims(report, args.claimed)
            if report.get('head_sha') != args.head or not rvas:
                parser.error('no contradicted explicit claim at this exact head')
            row['false_claims'].append(dict(pr=args.pr, head=args.head, rvas=rvas, check_run=args.check_run))
        validate(data)
        (ROOT / LEDGER).write_text(json.dumps(data, indent=2, sort_keys=True) + '\n')
    result = standing(data, author)
    progress = ROOT / 'data/progress.json'
    result['verified_matches'] = next((row['functions'] for row in standings(ROOT, json.loads(progress.read_text()))
                                       if row['contributor'] == '@' + result['handle']), 0) if progress.exists() else 0
    if args.apply_label and result['label']:
        # pull_request_target job reads only the trusted default-branch ledger; it never
        # checks out, compiles, imports or reads PR content or an untrusted artifact.
        repository = event['repository']['full_name']
        labels = api('GET', repository, '/labels?per_page=100')
        if not any(label['name'] == LABEL for label in labels):
            api('POST', repository, '/labels', dict(name=LABEL, color='b60205', description='Contributor has three active strikes'))
        api('POST', repository, f'/issues/{event["number"]}/labels', dict(labels=[LABEL]))
    print(json.dumps(result))
    if os.environ.get('GITHUB_STEP_SUMMARY'):
        with open(os.environ['GITHUB_STEP_SUMMARY'], 'a') as out:
            out.write(f'@{result["handle"]}: {result["strikes"]} active strikes; '
                      f'{"needs maintainer; automatic intake blocked" if result["label"] else "eligible for normal intake"}.\n')
    return 0 if args.record or args.clear else int(not result['auto_merge_eligible'])


if __name__ == '__main__':
    raise SystemExit(main())
