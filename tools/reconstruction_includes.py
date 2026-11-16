"""Select an additive include-root recipe for new units without changing accepted recipes."""
import json
from pathlib import Path


def root_recipe(root, recipe):
    """Return a tracked recipe with identical settings plus /I reconstruction, or refuse."""
    root, recipe = Path(root), Path(recipe)
    original = json.loads((root / recipe).read_text())
    flags = original.get('flags', [])
    if any(flags[i:i + 2] == ['/I', 'reconstruction'] for i in range(len(flags))):
        return recipe.as_posix()
    candidate = recipe.with_name(recipe.stem + '-reconstruction.json')
    expected = dict(original, flags=flags + ['/I', 'reconstruction'])
    if not (root / candidate).is_file() or json.loads((root / candidate).read_text()) != expected:
        raise ValueError('cross-area headers need a recipe with /I reconstruction')
    return candidate.as_posix()


def header_path(root, including, name):
    """Resolve local or reconstruction-root headers; old briefs may use parent-relative names."""
    root = Path(root).resolve()
    for path in (Path(including).parent / name, root / 'reconstruction' / name):
        path = path.resolve()
        if path.is_relative_to(root / 'reconstruction') and path.is_file():
            return path
    return None
