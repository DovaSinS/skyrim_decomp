"""Private publisher liveness and measured progress; never a verification result or timeout."""
from contextlib import contextmanager
from functools import wraps
import json
import os
from pathlib import Path
import subprocess
import threading
import time

from flow_state import state_lock, atomic_write

_ACTIVE = set()
_OBSERVERS = {}


def cpu_seconds(value):
    days, _, clock = value.rpartition('-')
    # ps uses [[days-]hours:]minutes:seconds, sometimes fractional seconds.
    parts = [float(x) for x in clock.split(':')]
    return (float(days) * 86400 if days else 0) + sum(x * 60**i for i, x in enumerate(reversed(parts)))


class Heartbeat:
    def __init__(self, fdir, discover=True):
        import flow_lane as lane
        self.fdir, self.owner = Path(fdir), lane.process_owner()
        self.previous, self.progress_at, self.progress_cpu = None, None, 0
        self.paths = None if discover else set()

    def sample(self):
        import flow
        output = subprocess.run(['ps', '-axo', 'pid=,ppid=,time='], capture_output=True, text=True)
        if output.returncode:
            raise OSError('cannot sample publisher process progress')
        rows = [(int(p), int(parent), cpu_seconds(cpu)) for p, parent, cpu in
                (line.split() for line in output.stdout.splitlines() if len(line.split()) == 3)]
        owned = {self.owner['pid']}
        while True:
            expanded = owned | {pid for pid, parent, _ in rows if parent in owned}
            if expanded == owned:
                break
            owned = expanded
        step = getattr(flow, 'LANE_STEP', {})
        log = Path(step['log_path']) if step.get('log_path') else None
        return dict(phase=step.get('phase', 'publishing'), step=step.get('sequence', 0),
                    cpu_seconds=round(max(0, sum(cpu for pid, _, cpu in rows if pid in owned) - time.thread_time()), 3),
                    process_count=len(owned), log_bytes=log.stat().st_size if log and log.is_file() else 0)

    def tick(self):
        if not self.owner.get('birth') or self.paths == set():
            return None
        import flow
        sample, now = self.sample(), flow.utc()
        signature = tuple((key, value) for key, value in sample.items() if key != 'cpu_seconds')
        if signature != self.previous or sample['cpu_seconds'] >= self.progress_cpu + 0.1:
            self.previous, self.progress_at, self.progress_cpu = signature, now, sample['cpu_seconds']
        heartbeat = dict(sample, alive_at=now, progress_at=self.progress_at)
        paths = self.paths if self.paths is not None else {p for directory in ('runs', 'tooling')
                  for p in (self.fdir / 'lane' / directory).glob('*.json')}
        for path in paths:
            with state_lock(self.fdir):
                if self.paths is not None and path not in self.paths:
                    continue
                current = json.loads(path.read_text())  # Preserve immutable sidecar references.
                if (current.get('owner') != self.owner or current.get('state') != 'running'
                        or current.get('kind') == 'tooling-request'):
                    continue
                current['heartbeat'] = heartbeat
                atomic_write(path, (json.dumps(current, indent=2, sort_keys=True) + '\n').encode())
        return heartbeat


def phase(name, log_path=None):
    import flow
    previous = getattr(flow, 'LANE_STEP', {})
    flow.LANE_STEP = dict(phase=name, sequence=previous.get('sequence', 0) + 1,
                         log_path=str(log_path) if log_path else None)


@contextmanager
def observe(fdir, interval=10):
    key = os.getpid(), str(Path(fdir).resolve())
    if key in _ACTIVE:
        yield
        return
    _ACTIVE.add(key)
    phase('starting publisher')
    heartbeat, stop = Heartbeat(fdir, discover=False), threading.Event()
    _OBSERVERS[key] = heartbeat
    def pulse():
        while not stop.wait(interval):
            try:
                heartbeat.tick()
            except (OSError, ValueError, KeyError):
                # Missing telemetry never invents progress, changes a gate or stops publication.
                pass
    thread = threading.Thread(target=pulse, name='lane-heartbeat', daemon=True)
    thread.start()
    try:
        yield
    finally:
        stop.set()
        thread.join(timeout=1)
        _ACTIVE.discard(key)
        _OBSERVERS.pop(key, None)


def publisher(function):
    @wraps(function)
    def wrapped(root, fdir, *args, **kwargs):
        with observe(fdir):
            return function(root, fdir, *args, **kwargs)
    return wrapped


def watch(fdir, path, owner):
    observer = _OBSERVERS.get((os.getpid(), str(Path(fdir).resolve())))
    if observer is not None and owner == observer.owner:
        observer.paths = {Path(path)}


def preserve(path, value):
    """Normal receipt saves must not overwrite a newer pulse from the observer."""
    if path.is_file():
        old = json.loads(path.read_text())
        if (old.get('owner') == value.get('owner') or old.get('owner') == value.get('finished_owner')) and old.get('heartbeat'):
            value = dict(value, heartbeat=old['heartbeat'])
    return value
