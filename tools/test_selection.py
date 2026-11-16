"""Conservative local test selection. Exact-SHA CI always runs the complete inventory.

Use both revisions' dependency graphs: removing an import must not hide its old tests.
Unresolved dynamic Python loading/commands/file access are opaque dependencies; their test
callers always run for tooling changes. Unmapped changed inputs fall back to the full suite.
This is scheduling, never an acceptance or validation result cache.
"""
import ast
from pathlib import PurePosixPath
import subprocess

DERIVED = frozenset({'reconstruction/INDEX.md', 'LEADERBOARD.md', 'data/contributors.json',
                     'docs/progress.svg', 'docs/progress-map.svg', 'docs/model-trend.svg',
                     'docs/progress-trend.svg'})
CORE = frozenset({'tools/test_suite.py', 'tools/test_selection.py', 'tools/source_digest.py',
                  'tools/revision_cache.py', 'tools/family_review.py', 'tools/symbol_map.py',
                  'tools/lint_reconstruction.py', 'tools/screen.py', 'tools/pecoff.py'})
CORE_PREFIXES = ('tools/flow', 'tools/check', 'tools/accept', 'tools/lane', 'tools/verifier/', 'tools/compare')


def git(root, *args):
    return subprocess.check_output(['git', *args], cwd=root, stderr=subprocess.PIPE)


def changed(root, base, revision='HEAD'):
    # No rename inference: a rename retains both the deleted and added dependency identities.
    return [p.decode() for p in git(root, 'diff', '--no-renames', '--name-only', '-z', base, revision).split(b'\0') if p]


def source_only(root, base, revision='HEAD'):
    if not base:
        return False
    paths = changed(root, base, revision)
    for path in paths:
        if path.endswith('.py'):
            return False
        if path.startswith('reconstruction/recipes/'):
            return False
        if path.startswith(('reconstruction/', 'reports/')) or path in DERIVED | {'data/progress.json'}:
            continue
        if path == 'README.md':
            start, end = '<!-- model-trend-totals -->', '<!-- /model-trend-totals -->'
            def outside(ref):
                text = git(root, 'show', ref + ':README.md').decode()
                if text.count(start) != 1 or text.count(end) != 1:
                    return None
                before, rest = text.split(start)
                if end not in rest:
                    return None
                return before, rest.split(end)[1]
            try:
                before, after = outside(base), outside(revision)
            except subprocess.CalledProcessError:
                return False
            if before is not None and before == after:
                continue
        return False
    return bool(paths)


def sources(root, revision):
    paths = [p.decode() for p in git(root, 'ls-tree', '-r', '--name-only', '-z', revision,
                                    '--', 'tools', 'tests').split(b'\0') if p.endswith(b'.py')]
    result = {}
    # One Git process for all immutable sources, with exact batch framing.
    with subprocess.Popen(['git', 'cat-file', '--batch'], cwd=root, stdin=subprocess.PIPE,
                          stdout=subprocess.PIPE) as proc:
        for path in paths:
            proc.stdin.write((revision + ':' + path + '\n').encode())
            proc.stdin.flush()
            header = proc.stdout.readline().split()
            if len(header) != 3 or header[1] != b'blob':
                raise ValueError('cannot read selection dependency: ' + path)
            payload = proc.stdout.read(int(header[2]))
            if len(payload) != int(header[2]) or proc.stdout.read(1) != b'\n':
                raise ValueError('truncated selection dependency: ' + path)
            result[path] = payload.decode()
        proc.stdin.close()
        if proc.wait():
            raise ValueError('cannot read selection dependencies')
    return result


def dependencies(files, inputs):
    references = [(path, PurePosixPath(path).name) for path in inputs]
    aliases = {}
    for path in files:
        parts = PurePosixPath(path).with_suffix('').parts
        for offset in range(len(parts)):
            aliases.setdefault('.'.join(parts[offset:]), set()).add(path)
    graph, opaque = {}, set()
    for path, text in files.items():
        tree = ast.parse(text, filename=path)
        edges, has_dynamic = set(), False
        process_names, process_modules = set(), {'subprocess'}
        for node in ast.walk(tree):
            if isinstance(node, ast.Import):
                process_modules.update(n.asname or n.name for n in node.names if n.name == 'subprocess')
            elif isinstance(node, ast.ImportFrom) and node.module == 'subprocess':
                process_names.update(n.asname or n.name for n in node.names)
        for node in ast.walk(tree):
            if isinstance(node, ast.Import):
                for name in node.names:
                    edges.update(aliases.get(name.name, ()))
                    if name.name.split('.')[0] in {'importlib', 'runpy', 'builtins'}:
                        has_dynamic = True
            elif isinstance(node, ast.ImportFrom):
                name = node.module or ''
                if name.split('.')[0] in {'importlib', 'runpy', 'builtins'}:
                    has_dynamic = True
                if node.level:
                    parts = list(PurePosixPath(path).parent.parts)
                    parts = parts[:len(parts) - node.level + 1]
                    name = '.'.join(parts + ([name] if name else []))
                edges.update(aliases.get(name, ()))
                for item in node.names:
                    edges.update(aliases.get(name + '.' + item.name, ()))
            elif isinstance(node, ast.Constant) and isinstance(node.value, str):
                # Include subprocess script names and non-Python recipe/workflow references.
                for target, filename in references:
                    if target in node.value or (filename in node.value and '/' not in node.value):
                        edges.add(target)
            elif isinstance(node, ast.Call):
                name = node.func.id if isinstance(node.func, ast.Name) else (
                    node.func.attr if isinstance(node.func, ast.Attribute) else '')
                if name in {'__import__', 'eval', 'exec', 'import_module', 'spec_from_file_location',
                            'run_module', 'run_path', 'getattr', 'input'}:
                    has_dynamic = True
                if path.startswith('tests/') and name in {'glob', 'rglob'}:
                    has_dynamic = True
                is_process = (isinstance(node.func, ast.Name) and name in process_names
                              or isinstance(node.func, ast.Attribute)
                              and isinstance(node.func.value, ast.Name)
                              and node.func.value.id in process_modules)
                if is_process:
                    # Literal non-Python commands do not create Python import dependencies.
                    # Variable command vectors and interpreter/script dispatch remain opaque.
                    argv = node.args[0] if node.args else None
                    executable = (argv.elts[0] if isinstance(argv, (ast.List, ast.Tuple)) and argv.elts else None)
                    if not (isinstance(executable, ast.Constant) and executable.value in
                            {'git', 'gh', 'echo', 'true', 'false'}):
                        has_dynamic = True
                if path.startswith('tests/') and name in {'open', 'read_text', 'read_bytes'}:
                    # Dynamic file inspection can test tooling without importing it. Only
                    # fixture-owned self paths and literal references are bounded here.
                    receiver = node.func.value if isinstance(node.func, ast.Attribute) else node
                    fixture = ('TemporaryDirectory' in text
                               and any(isinstance(n, ast.Attribute) and isinstance(n.value, ast.Name)
                                       and n.value.id == 'self' and n.attr in {'root', 'tmp'}
                                       for n in ast.walk(receiver)))
                    literals = [n.value for n in ast.walk(node) if isinstance(n, ast.Constant)
                                and isinstance(n.value, str)]
                    non_python = any(PurePosixPath(value).suffix in
                                     {'.json', '.md', '.h', '.hpp', '.cpp', '.txt', '.yml', '.yaml',
                                      '.csv', '.svg', '.html', '.css', '.log'} for value in literals)
                    if not fixture and not non_python and not any(target in value or filename in value
                                                                 for value in literals for target, filename in references):
                        has_dynamic = True
        graph[path] = edges
        if has_dynamic:
            opaque.add(path)
    return graph, opaque


def select(root, base, revision, modules):
    """Return module names and a diagnostic reason; every uncertain case widens coverage."""
    all_modules = set(modules)
    if not base:
        return all_modules, 'full: no comparison base'
    paths = changed(root, base, revision)
    if source_only(root, base, revision):
        return set(), 'source/metadata only: validator, acceptance, derived views and site; full suite in CI'
    if any(p in CORE or p.startswith(CORE_PREFIXES) for p in paths):
        return all_modules, 'full: shared core changed'
    try:
        graphs, opaque = {}, set()
        for ref in (base, revision):
            files = sources(root, ref)
            graph, unknown = dependencies(files, set(paths) | set(files))
            for path, edges in graph.items():
                graphs.setdefault(path, set()).update(edges)
            opaque.update(unknown)
        reached, selected = set(paths) | opaque, set()
        while True:
            expanded = reached | {path for path, edges in graphs.items() if edges & reached}
            if reached == expanded:
                break
            reached = expanded
        # Require a real test mapping for every changed input, independently of opaque callers.
        for target in paths:
            covered = {target}
            while True:
                expanded = covered | {path for path, edges in graphs.items() if edges & covered}
                if covered == expanded:
                    break
                covered = expanded
            if not any('tests/' + m.replace('.', '/') + '.py' in covered for m in modules):
                return all_modules, 'full: unmapped changed input ' + target
        for module in modules:
            path = 'tests/' + module.replace('.', '/') + '.py'
            if path not in graphs:
                return all_modules, 'full: unresolved test module ' + module
            if path in reached:
                selected.add(module)
        return selected, 'affected: union of base/current imports, file references and opaque callers'
    except (ValueError, SyntaxError, UnicodeError, OSError, subprocess.CalledProcessError):
        return all_modules, 'full: dependency analysis unavailable'
