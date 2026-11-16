"""Short recovery advice at command boundaries; never changes a gate or a result."""
import argparse


def next_action(message, command='flow'):
    text = str(message).lower()
    if any(s in text for s in ('lane tooling differs', 'stale lane', 'stale tooling')):
        return ('Update the running tools to origin/main, rebase the input checkout, then retry with '
                '--wait-lane. Queued items are kept; tooling changes use the base tools with --root.')
    if any(s in text for s in ('disk space', 'disk floor', 'low disk', 'no space left')):
        return ('Free disk space, then retry. '
                'Keep machine-specific paths in private configuration, out of tracked output.')
    if any(s in text for s in ('lane already running', 'publisher busy', 'lane lock')):
        return 'This is not a stall: keep waiting with --wait-lane; queued items are kept.'
    if 'enrollment' in text or 'not an inventory entry' in text or 'must be enrolled' in text:
        return 'Include mapped-only inventory enrollment rows in the same lane item (enrollments, p152), then retry.'
    if any(s in text for s in ('stale header', 'origin changed carried', 'stale-sibling', 'translation unit changed')):
        return ('Rebase and reconcile the header, re-confirm affected units using confirmation-pinned maps, '
                'then requeue; keep report/source and symbol_map.path bindings together.')
    if any(s in text for s in ('symbol map', 'symbol-map', 'symbol_map', 'match record', 'report', 'symbols',
                               'record_refresh', 'source digest', 'source.digest', 'source: digest', 'translation unit digest')):
        return ('Use the confirmation-pinned map and history (record symbol_map.path), not a newer global map; '
                'set task.symbols and supply inventory report, source.translation_unit and request record_refresh for companion reports.')
    if 'review' in text or 'approval' in text or 'escalation' in text:
        return 'Use flow.py next-actions to obtain the required fresh review or resolve its blocker, then requeue.'
    if any(s in text for s in ('model', '--agent', 'agent is required', 'worker', 'drafted-by')):
        return 'Name the actual model with --model (or --agent); project claims may use their profile default.'
    if 'compile' in text or 'include' in text:
        return 'Fix the named source/include or compiler error, then retry the same unit; retain prior passes.'
    if 'ci ' in text or 'checks' in text:
        return 'Inspect the exact-SHA CI/check log, fix its failure, then resume the recorded lane receipt.'
    if 'claim' in text or command == 'claims':
        return 'Refresh claims when online, choose unclaimed scope, then retry; retain existing local work.'
    if 'receipt' in text or 'resume' in text:
        return 'Read flow.py lane-status and use the receipt\'s resume_command with the same shared --flow-dir.'
    if command == 'attempt':
        return 'Fix the named source/input issue; send task/config or runner preparation faults to the Engineer, then retry this unit.'
    if command == 'contrib':
        return 'Run contrib.py doctor, correct the named input, then retry the same command.'
    return 'Run flow.py next-actions with the same --flow-dir, correct the named input, then retry.'


def explain(message, command='flow'):
    message = str(message)
    return message if '\nNext: ' in message else message + '\nNext: ' + next_action(message, command)


class ArgumentParser(argparse.ArgumentParser):
    def error(self, message):
        super().error(message + f'\nNext: run {self.prog} --help and correct the named argument.')
