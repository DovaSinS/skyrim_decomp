"""Keep published CI-hash recipe approvals in sync with available recipes."""
import hashlib
import json
from pathlib import Path


def test_all_recipes_are_approved():
    root = Path(__file__).resolve().parents[1]
    manifest = json.loads((root / 'data/target-hashes/sse-steam-1-7-104.json').read_text())
    recipes = list((root / 'reconstruction/recipes').glob('*.json'))
    assert recipes
    for recipe in recipes:
        assert manifest['recipe_sha256'].get(recipe.relative_to(root).as_posix()) == hashlib.sha256(recipe.read_bytes()).hexdigest()
