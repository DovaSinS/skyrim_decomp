#!/usr/bin/env python3
"""Fetch pinned Microsoft payloads; fully verify a scratch toolchain or restored CI cache.

No VS installer, registry setup, game data or candidate diagnostics. The checked-in tree manifest
is trusted; a manifest inside a cache is never read. SDK MSI administrative extraction writes only
to scratch (msiextract locally, msiexec /a on Windows). Every payload is catalog-hash checked.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor
import hashlib
import json
import os
from pathlib import Path, PurePosixPath
import shutil
import stat
import subprocess
import sys
import tempfile
import time
import urllib.parse
import urllib.request
import zipfile

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / 'tools/verifier'))
from recipe_pins import read_pins

INDEX = 'tools/toolchain/v141-manifest.json'
PLAN = 'tools/toolchain/v141-packages.json'
VC = 'VC/Tools/MSVC/14.16.27023'
SDK = 'Windows Kits/10'
SUBTREES = [VC + '/' + p for p in ('bin/Hostx64/x64', 'include', 'lib/x64')]
SUBTREES += [SDK + '/Include/10.0.19041.0/' + p for p in ('ucrt', 'shared', 'um', 'winrt')]
SUBTREES += [SDK + '/Lib/10.0.19041.0/' + p for p in ('ucrt/x64', 'um/x64')]


def sha(path):
    h = hashlib.sha256()
    with open(path, 'rb') as stream:
        for chunk in iter(lambda: stream.read(1 << 20), b''):
            h.update(chunk)
    return h.hexdigest()


def safe_path(name):
    path = PurePosixPath(name.replace('\\', '/'))
    if path.is_absolute() or '..' in path.parts or ':' in name or not path.parts:
        raise ValueError('unsafe toolchain path')
    return path


def download(url, dest, expected):
    parsed = urllib.parse.urlparse(url)
    if parsed.scheme != 'https' or parsed.hostname not in ('download.visualstudio.microsoft.com', 'download.microsoft.com'):
        raise ValueError('non-Microsoft payload URL')
    if not dest.exists() or sha(dest) != expected.lower():
        dest.parent.mkdir(parents=True, exist_ok=True)
        with urllib.request.urlopen(url, timeout=120) as source, open(dest, 'wb') as target:
            shutil.copyfileobj(source, target)
    if sha(dest) != expected.lower():
        dest.unlink()
        raise ValueError('payload SHA-256 differs')


def pins(repo):
    return {name: value for value, name in
            (line.split() for line in (repo / 'tools/verifier/pinned.sha256').read_text().splitlines() if line.strip())}


def verify_pins(repo, tree):
    bindir = tree / VC / 'bin/Hostx64/x64'
    return all((bindir / name).is_file() and sha(bindir / name) == value for name, value in pins(repo).items())


def files(tree):
    result = {}
    if tree.is_symlink() or getattr(tree, 'is_junction', lambda: False)():
        raise ValueError('linked toolchain root')
    for path in tree.rglob('*'):
        if path.is_symlink() or getattr(path, 'is_junction', lambda: False)():
            raise ValueError('linked toolchain file')
        if not path.is_file() and not path.is_dir():
            raise ValueError('special toolchain entry')
        if path.is_file():
            name = path.relative_to(tree).as_posix().lower()
            if name in result:
                raise ValueError('case-colliding toolchain files')
            result[name] = dict(size=path.stat().st_size, sha256=sha(path))
    return result


def expected_files(repo):
    index = json.loads((repo / INDEX).read_text())
    if index['package_plan_sha256'] != sha(repo / PLAN):
        raise ValueError('stale toolchain package plan')
    result = {}
    for shard in index['shards']:
        path = repo / safe_path(shard['path'])
        if sha(path) != shard['sha256']:
            raise ValueError('toolchain manifest shard differs')
        for row in json.loads(path.read_text())['files']:
            name = safe_path(row['path']).as_posix()
            if name in result or name != name.lower():
                raise ValueError('invalid toolchain manifest path')
            result[name] = {k: row[k] for k in ('size', 'sha256')}
    if len(result) != index['file_count']:
        raise ValueError('toolchain manifest count differs')
    return result


def verify(repo, tree):
    try:
        return tree.is_dir() and files(tree) == expected_files(repo) and verify_pins(repo, tree)
    except (OSError, ValueError, KeyError):
        return False


def fetch(repo, tree, scratch):
    recipe = read_pins(repo)
    catalog = scratch / 'VisualStudio.vsman'
    download(recipe['VSMAN_URL'], catalog, recipe['VSMAN_SHA256'])
    manifest = json.loads(catalog.read_text(encoding='utf-8-sig'))
    plan = json.loads((repo / PLAN).read_text())
    if plan['catalog_sha256'] != recipe['VSMAN_SHA256']:
        raise ValueError('catalog pin differs')
    official = {(p['url'], p['sha256'].lower(), p['size'])
                for package in manifest['packages'] for p in package.get('payloads', [])}
    payloads = plan['payloads']
    for p in payloads:
        safe_path(p['name'])
        if (p['url'], p['sha256'].lower(), p['size']) not in official:
            raise ValueError('payload absent from pinned catalog')
    cache = scratch / 'payloads'
    def get(p):
        download(p['url'], cache / p['name'], p['sha256'])
    with ThreadPoolExecutor(max_workers=8) as pool:
        list(pool.map(get, payloads))
    unpack = scratch / 'unpack'
    unpack.mkdir(parents=True, exist_ok=True)
    for payload in payloads:
        source = cache / payload['name']
        if payload['kind'] == 'vsix':
            with zipfile.ZipFile(source) as archive:
                for entry in archive.infolist():
                    name = urllib.parse.unquote(entry.filename)
                    if not name.startswith('Contents/') or entry.is_dir():
                        continue
                    if stat.S_IFMT(entry.external_attr >> 16) == stat.S_IFLNK:
                        raise ValueError('linked archive entry')
                    path = unpack / safe_path(name[len('Contents/'):])
                    path.parent.mkdir(parents=True, exist_ok=True)
                    with archive.open(entry) as inp, open(path, 'wb') as out:
                        shutil.copyfileobj(inp, out)
        elif payload['kind'] == 'msi':
            cmd = (['msiexec', '/a', str(source), '/qn', 'TARGETDIR=' + str(unpack.resolve())]
                   if sys.platform == 'win32' else ['msiextract', '-C', str(unpack), str(source)])
            subprocess.run(cmd, check=True, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL, timeout=180)
    # Unix msiextract adds Program Files; Windows administrative extraction does not.
    sdk_source = unpack / 'Program Files' / 'Windows Kits'
    if sdk_source.is_dir() and not (unpack / 'Windows Kits').exists():
        shutil.move(str(sdk_source), str(unpack / 'Windows Kits'))
    for relative in SUBTREES:
        source, dest = unpack / relative, tree / relative
        if not source.is_dir():
            raise ValueError('required toolchain subtree absent')
        shutil.copytree(source, dest, dirs_exist_ok=True)
    # Explicit local CRT dependencies, rather than whichever redistributable is on PATH.
    for directory in (unpack / 'VC/Redist/MSVC').glob('*/x64/Microsoft.VC141.CRT'):
        for dll in directory.glob('*.dll'):
            shutil.copyfile(dll, tree / VC / 'bin/Hostx64/x64' / dll.name)
    if not verify_pins(repo, tree):
        raise ValueError('one of four compiler pins differs')


def write_manifest(repo, tree):
    if not verify_pins(repo, tree):
        raise ValueError('cannot inventory wrong compiler')
    rows = [dict(path=name, **value) for name, value in sorted(files(tree).items())]
    shards = []
    for i in range(0, len(rows), 2000):
        path = repo / f'tools/toolchain/v141-files-{i // 2000:03d}.json'
        path.write_text(json.dumps(dict(files=rows[i:i + 2000]), indent=2) + '\n')
        shards.append(dict(path=path.relative_to(repo).as_posix(), sha256=sha(path)))
    (repo / INDEX).write_text(json.dumps(dict(schema=1, file_count=len(rows),
        package_plan_sha256=sha(repo / PLAN), compiler_pins=pins(repo), shards=shards), indent=2) + '\n')


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('command', choices=('key', 'setup', 'inventory', 'fetch'))
    parser.add_argument('--root', type=Path, required=True)
    parser.add_argument('--scratch', type=Path)
    parser.add_argument('--started', type=float, default=None)
    a = parser.parse_args(argv)
    started = a.started if a.started is not None else time.time()
    if a.command == 'key':
        report = dict(cache_key='msvc-v141-' + sha(ROOT / INDEX), started=started)
    elif a.command == 'inventory':
        write_manifest(ROOT, a.root); report = dict(manifest_sha256=sha(ROOT / INDEX))
    else:
        fetched = a.command == 'fetch' or not verify(ROOT, a.root)
        if fetched:
            if a.root.is_symlink():
                a.root.unlink()
            elif getattr(a.root, 'is_junction', lambda: False)():
                a.root.rmdir()
            elif a.root.exists():
                shutil.rmtree(a.root)
            scratch = a.scratch or a.root.with_name(a.root.name + '-download')
            scratch.mkdir(parents=True, exist_ok=True)
            fetch(ROOT, a.root, scratch)
            if a.command != 'fetch' and not verify(ROOT, a.root):
                expected, actual = expected_files(ROOT), files(a.root)
                print(json.dumps(dict(verification='mismatch',
                    missing=sorted(expected.keys() - actual.keys())[:8],
                    changed=[name for name in expected.keys() & actual.keys()
                             if expected[name] != actual[name]][:8],
                    extra_count=len(actual.keys() - expected.keys()))))
                raise ValueError('fresh tree differs from trusted full manifest')
        report = dict(fetched=str(fetched).lower(), setup_seconds=round(time.time() - started, 2),
                      bin=str(a.root / VC / 'bin/Hostx64/x64'),
                      manifest_sha256=sha(ROOT / INDEX) if a.command != 'fetch' else None)
    print(json.dumps(report))
    if os.environ.get('GITHUB_OUTPUT'):
        with open(os.environ['GITHUB_OUTPUT'], 'a') as out:
            out.write(''.join(f'{key}={value}\n' for key, value in report.items()))
    return 0


if __name__ == '__main__':
    sys.exit(main())
