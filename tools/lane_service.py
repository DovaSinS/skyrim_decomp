#!/usr/bin/env python3
"""Scheduler-owned publication. Workers enqueue; this job uses fresh origin tools each tick.

All machine paths, environment and logs live in lane/service, never in the public tree.
There is no publisher timeout, model dispatch, verifier invocation or claim synchronization.
"""
import argparse
from contextlib import contextmanager
import fcntl
import json
import os
from pathlib import Path
import signal
import socket
import subprocess
import sys
import time

import flow as f
import flow_lane as lane
import resource_admission
from flow_state import state_lock, require_complete

ROOT = Path(__file__).resolve().parents[1]


def records(fdir, directory):
    return [lane.read(p) for p in sorted((Path(fdir) / 'lane' / directory).glob('*.json'))]


def actionable(fdir, branch):
    """Local reads only. Unknown-host owners and recorded failures are never retried blindly."""
    for directory in ('queue', 'tooling-queue'):
        if any(r.get('state') == 'queued' and r.get('branch') == branch for r in records(fdir, directory)):
            return True
    for directory in ('runs', 'tooling'):
        for r in records(fdir, directory):
            if (r.get('kind') != 'tooling-request' and not r.get('repair_red') and r.get('branch') == branch
                    and r.get('state') in ('running', 'stale')
                    and (r.get('owner') or {}).get('host') == socket.gethostname()
                    and not lane.owner_alive(r.get('owner'))):
                if (r.get('integrated') or {}).get('pushed') or not r.get('error'):
                    return True
    return False


def worker(config):
    with lane.service_authority(Path(config['flow_dir'])):
        return _worker(config)


def _worker(config):
    """Called in a new interpreter from the freshly fetched origin checkout."""
    root, fdir = Path(config['root']), Path(config['flow_dir'])
    branch, python = config['branch'], config['python']
    if lane.running(fdir):
        return dict(state='busy')
    resource_admission.admit(fdir, 'lane service', soft_gb=config['soft_free_gb'])
    recovered = []
    for directory in ('runs', 'tooling'):
        for r in records(fdir, directory):
            if (r.get('kind') == 'tooling-request' or r.get('branch') != branch
                    or r.get('repair_red') or r.get('state') not in ('running', 'stale')
                    or (r.get('owner') or {}).get('host') != socket.gethostname()
                    or lane.owner_alive(r.get('owner'))):
                continue
            if (r.get('integrated') or {}).get('pushed'):
                # Resume exact-SHA CI, never retire/requeue a pushed checkpoint.
                result = (lane.finish_run(root, fdir, r, python, config['ci_wait'], sync_claims=False)
                          if directory == 'runs' else lane.finish_tooling(root, fdir, r, python, config['ci_wait']))
                return dict(state='finished-ci', run=result['id'], integrated=result['integrated'])
            if r.get('error'):
                continue
            if directory == 'tooling':
                # Preserve old immutable candidates and their legacy resume semantics.
                result = lane.publish_tooling(Path(r['root']), fdir, branch, config['ci_wait'], python,
                                             resume=r['id'], soft_free_gb=config['soft_free_gb'])
                return dict(state=result['state'], run=result['id'], integrated=result.get('integrated'))
            result = lane.retire(root, fdir, r['id'], 'lane service: dead local publisher; requeue retained inputs',
                                 requeue_stale=True)
            recovered.append(dict(run=r['id'], items=result['requeued_items']))
    result = lane.run_lane(root, fdir, branch, True, config['ci_wait'], python,
                           soft_free_gb=config['soft_free_gb'], sync_claims=False)
    return dict(state=result['state'], run=result.get('id'), integrated=result.get('integrated'), recovered=recovered)


@contextmanager
def service_lock(private):
    with (private / '.service.lock').open('a') as handle:
        try:
            fcntl.flock(handle, fcntl.LOCK_EX | fcntl.LOCK_NB)
        except BlockingIOError:
            yield False
            return
        try:
            yield True
        finally:
            fcntl.flock(handle, fcntl.LOCK_UN)


def load_config(path):
    config = json.loads(path.read_text())
    for key in ('root', 'flow_dir', 'python'):
        f.refuse(Path(config[key]).is_absolute(), key + ' must be an absolute private path')
    f.refuse(config['branch'] and not config['branch'].startswith('-'), 'invalid branch')
    f.refuse(type(config['ci_wait']) is int and config['ci_wait'] >= 0, 'invalid ci_wait')
    resource_admission.threshold(config['soft_free_gb'], 'SKYRIM_SOFT_FREE_GB', '10')
    return config


def run_once(config_path):
    config = load_config(config_path)
    private = config_path.parent
    fdir, root = Path(config['flow_dir']), Path(config['root'])
    with service_lock(private) as acquired:
        if not acquired:
            return dict(state='service-busy')
        # Never fetch or mutate receipts when a worker already owns the lane.
        if lane.running(fdir):
            return dict(state='busy')
        with state_lock(fdir):
            require_complete(fdir)
            pending = actionable(fdir, config['branch'])
        if not pending:
            return dict(state='empty')
        resource_admission.admit(fdir, 'lane service', soft_gb=config['soft_free_gb'])
        stamp = str(time.time_ns())
        log = private / (stamp + '.log')
        result_file = private / (stamp + '.json')
        # Only this dedicated, clean tool checkout may be refreshed, under the service lock.
        runtime = private / 'origin-tools'
        env = dict(os.environ, **config.get('environment', {}))
        with log.open('w') as output:
            def command(args, cwd=root):
                result = subprocess.run(args, cwd=cwd, env=env, stdin=subprocess.DEVNULL,
                                        stdout=output, stderr=subprocess.STDOUT)
                f.refuse(result.returncode == 0, 'service setup failed: ' + str(args[0]) + '; see ' + str(log))
            if not runtime.exists():
                command(['git', 'clone', '--quiet', '--shared', '--no-checkout', str(root), str(runtime)])
                command(['git', 'remote', 'set-url', 'origin', f.git(root, 'remote', 'get-url', 'origin')], runtime)
                sparse_path = Path(f.git(runtime, 'rev-parse', '--path-format=absolute', '--git-path',
                                         'info/sparse-checkout'))
                sparse_path.parent.mkdir(parents=True, exist_ok=True)
                sparse_path.touch(exist_ok=True)
                command(['git', 'checkout', '--quiet', '--detach', 'HEAD'], runtime)
            f.refuse(not f.git(runtime, 'status', '--porcelain', '--untracked-files=all'),
                     'service tool checkout is dirty; preserve it for triage')
            command(['git', 'fetch', '--quiet', 'origin', config['branch']], runtime)
            command(['git', 'checkout', '--quiet', '--detach', 'origin/' + config['branch']], runtime)
            base = f.git(runtime, 'rev-parse', 'HEAD')
            args = [config['python'], str(runtime / 'tools/lane_service.py'), '--config', str(config_path),
                    'worker', '--result', str(result_file)]
            status = dict(state='running', owner=lane.process_owner(), started_at=f.utc(),
                          runtime=base, log=str(log), result=str(result_file))
            lane.write(private / 'last.json', status)
            # No timeout: The configured scheduler owns this process independently of a worker's box.
            result = subprocess.run(args, cwd=root, env=env, stdin=subprocess.DEVNULL,
                                    stdout=output, stderr=subprocess.STDOUT)
        status.update(state='done' if result.returncode == 0 else 'failed', finished_at=f.utc(),
                      returncode=result.returncode,
                      signal=-result.returncode if result.returncode < 0 else None,
                      outcome=lane.read(result_file) if result_file.is_file() else None)
        lane.write(private / 'last.json', status)
        return status



def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--root', type=Path, default=ROOT)
    p.add_argument('--flow-dir', type=Path)
    p.add_argument('--config', type=Path)
    sub = p.add_subparsers(dest='command', required=True)
    sub.add_parser('run-once')
    w = sub.add_parser('worker')
    w.add_argument('--result', type=Path, required=True)
    a = p.parse_args(argv)
    fdir = a.flow_dir or (a.config.parent.parent.parent if a.config else Path(f.af.active_flow_dir(a.root)))
    config = a.config or fdir / 'lane/service/config.json'
    try:
        if a.command == 'worker':
            result = worker(load_config(config))
            lane.write(a.result, result)
        else:
            result = run_once(config)
        print(json.dumps(result, indent=2), flush=True)
        return int(result.get('state') == 'failed')
    except (f.FlowError, ValueError, OSError, KeyError) as error:
        result = dict(state='failed', error=str(error), at=f.utc())
        if a.command == 'worker':
            lane.write(a.result, result)
        elif config.parent.is_dir():
            lane.write(config.parent / 'last.json', result)
        print(json.dumps(result), file=sys.stderr, flush=True)
        return 1


def stopped(signum, frame):
    print(json.dumps(dict(event='service-signal', signal=signum, at=f.utc())), file=sys.stderr, flush=True)
    # Preserve OS signal termination: raising SystemExit would be saved as a check error
    # by the lane's BaseException handler and prevent dead-owner recovery.
    signal.signal(signum, signal.SIG_DFL)
    os.kill(os.getpid(), signum)


if __name__ == '__main__':
    signal.signal(signal.SIGTERM, stopped)
    signal.signal(signal.SIGINT, stopped)
    raise SystemExit(main())
