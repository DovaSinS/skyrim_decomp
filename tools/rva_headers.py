"""RVAs a unit's header comments claim, one parser for the bot and the CI hash job.

A claim only selects which published target row to test; it never supplies a hash, a size or a
mask, so a wrong or hostile claim can at worst fail its own function.
"""
import re

CLAIM = re.compile(r'\bRVAs?\s+((?:0x[0-9a-fA-F]+)(?:(?:\s*,\s*(?:and\s+)?|\s+(?:and\s+)?)(?:0x[0-9a-fA-F]+))*)')


def claimed_rvas(texts):
    rvas = set()
    for text in texts:
        for match in CLAIM.finditer(text):
            rvas.update(int(v, 16) for v in re.findall(r'0x[0-9a-fA-F]+', match[1]))
    return rvas
