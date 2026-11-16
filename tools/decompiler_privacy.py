"""Publication checks for private decompiler output; no analysis data lives here."""
from pathlib import PurePosixPath
import re


def private_decompiler_path(name):
    path = PurePosixPath(name.replace('\\', '/').lower())
    return path.name in {'decomp.c', 'decompiled.c'} or any(
        part.endswith(('.gpr', '.rep')) for part in path.parts)


def private_decompiler_text(text):
    return bool(re.search(r'(?im)^\s*// PRIVATE DECOMPILER HINT:', text)
                or re.search(r'(?i)\b[^\s"\'<>]+\.(?:gpr\b|rep[/\\])', text))
