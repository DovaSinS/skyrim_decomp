"""Diagnostic progress only. Comparator results and hard attempt budgets remain authoritative."""
import json
from pathlib import Path


def measure(report, alignment=None):
    if alignment and isinstance(alignment.get('matching_bytes'), int):
        return dict(metric='aligned_matching_bytes', value=alignment['matching_bytes'],
                    total=alignment['target_bytes'], regions=alignment['matching_regions'])
    coverage = report.get('coverage') or {}
    total = coverage.get('code_bytes_total')
    if isinstance(total, int):
        return dict(metric='compared_code_bytes', value=(coverage.get('code_bytes_exact') or 0)
                    + (coverage.get('code_bytes_by_reference') or 0), total=total)
    return None


def read_json(path):
    try:
        value = json.loads(Path(path).read_text())
        return value if isinstance(value, dict) else {}
    except (OSError, ValueError):
        return {}


def update(current, history, counted=True):
    """Compare with the previous measured attempt; reset patience only on a new best.

    History is already scoped to a task and tier. Missing diagnostics never become fake zeroes.
    Changing diagnostic methods starts a new baseline; oscillating below a best is no improvement.
    """
    out = {}
    for rva, metric in current.items():
        if metric is None:
            out[rva] = None
            continue
        prior = next((row['progress'][rva] for row in reversed(history)
                      if (row.get('progress') or {}).get(rva)
                      and row['progress'][rva]['metric'] == metric['metric']), None)
        value = metric['value']
        best = max(value, prior['best']) if prior else value
        improved = prior is not None and value > prior['best']
        out[rva] = dict(metric, previous=prior['value'] if prior else None,
                        delta=value - prior['value'] if prior else None, best=best,
                        no_improvement=(0 if prior is None or improved else
                                        prior['no_improvement'] + int(counted)))
    return out


def describe(rva, metric, patience):
    if metric is None:
        return f'progress {rva}: unavailable; fix diagnostics before judging improvement (hard cap still applies).'
    delta = f'{metric["delta"]:+d} vs previous' if metric['delta'] is not None else 'first measurement'
    regions = f'; {metric["regions"]} matching regions' if 'regions' in metric else ''
    return (f'progress {rva}: {metric["metric"]} {metric["value"]}/{metric["total"]} ({delta}); '
            f'best {metric["best"]}; no improvement {metric["no_improvement"]}/{patience}{regions}.')


def guidance(patience):
    return (f'Keep going while matching bytes rise, even if the first mismatch stays put; stop after '
            f'{patience} counted attempts with no improvement over the best, or at the hard attempt cap. '
            'Progress is diagnostic, never match evidence.')
