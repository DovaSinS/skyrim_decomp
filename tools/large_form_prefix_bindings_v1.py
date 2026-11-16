"""Audit typed form-prefix parameters against a private pinned executable.

The plan supplies represented typed components, not evidence about target offsets.
The extractor independently reconciles the entire represented direct-base prefix,
each secondary locator and slot, instruction extent, adjustment and primary tail.
It outputs metadata only; a comparator and independent host are still required.
"""
import argparse
import hashlib
import json
from pathlib import Path
import capstone
from deleting_layout_bindings_v1 import Image
from adjustor_thunk_template_v3 import emit


def extract(image, owner, functions, plan):
    primary = image.table(owner['vftable'])
    if primary['type_raw'] != '.?AV' + plan['owner'] + '@@' or primary['offset'] != 0:
        raise ValueError('owner primary RTTI mismatch')
    col = image.number(owner['vftable'] - 8, 'Q') - image.base
    hierarchy = image.number(col + 16)
    array = image.number(hierarchy + 12)
    direct, i = [], 1
    while i < len(primary['bases']):
        base = primary['bases'][i]
        direct.append(base)
        descriptor = image.number(array + 4*i)
        i += image.number(descriptor + 4) + 1
    represented = plan['prefix']
    if len(direct) < len(represented):
        raise ValueError('incomplete direct base hierarchy')
    for expected, actual in zip(represented, direct):
        if (actual['type_raw'] != '.?AV' + expected['base'] + '@@'
                or actual['mdisp'] != expected['offset'] or actual['pdisp'] != -1):
            raise ValueError('represented direct-base binding mismatch')
    target = image.number(owner['vftable'], 'Q') - image.base
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    rows = []
    for requested in plan['members']:
        entry = requested['rva']
        fn = functions.get(entry)
        tables = [s['rva'] for s in owner['secondary_vftables']
                  if image.number(s['rva'], 'Q') - image.base == entry]
        if fn is None or fn['size'] != 12 or len(tables) != 1:
            raise ValueError('unique complete secondary destructor required')
        table = tables[0]
        locator = image.table(table)
        offset = locator['offset']
        bases = [b for b in represented[1:] if b['offset'] == offset]
        if (locator['type_raw'] != primary['type_raw'] or len(bases) != 1
                or requested['offset'] != offset or requested['base'] != '.?AV'+bases[0]['base']+'@@'
                or requested['table'] != table or requested['target'] != target or offset < 128):
            raise ValueError('secondary identity, offset, base or tail mismatch')
        instructions = list(decoder.disasm(image.read(entry, 12), image.base + entry))
        if len(instructions) != 2 or sum(i.size for i in instructions) != 12:
            raise ValueError('complete two-instruction extent required')
        adjust, transfer = instructions
        ops = adjust.operands
        if (adjust.mnemonic != 'sub' or len(ops) != 2
                or ops[0].type != capstone.x86.X86_OP_REG
                or ops[0].reg != capstone.x86.X86_REG_RCX or ops[0].size != 8
                or ops[1].type != capstone.x86.X86_OP_IMM or ops[1].imm != offset):
            raise ValueError('adjustment differs from RTTI offset')
        if (transfer.mnemonic != 'jmp' or len(transfer.operands) != 1
                or transfer.operands[0].type != capstone.x86.X86_OP_IMM
                or transfer.operands[0].imm - image.base != target):
            raise ValueError('transfer differs from primary destructor')
        layout = plan['owner'] + 'LargeFormPrefixLayout'
        end = represented[-1]['offset'] + represented[-1]['size']
        symbol = emit(entry, 12, offset, layout, end)
        rows.append(dict(owner=plan['owner'], layout=layout,
                         source='reconstruction/forms/' + layout + '.cpp',
                         entry_rva=entry, size=12, offset=offset,
                         secondary_table=table, primary_target=target,
                         base_type=requested['base'], symbol=symbol['symbol'],
                         callee=symbol['callee']))
    return rows


def family_parameters(row):
    """Use public family field names and lossless integer words for digests."""
    result = {}
    for key, value in row.items():
        key = key.replace('_', '-')
        if key.endswith('-sha256'):
            if not isinstance(value, str) or len(value) != 64:
                raise ValueError('invalid digest parameter')
            for index in range(8):
                result[f'{key}-word{index}'] = int(value[index*8:index*8+8], 16)
        else:
            result[key] = value
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('image', 'target', 'classes', 'functions', 'plan', 'out'):
        parser.add_argument('--' + name, type=Path, required=True)
    args = parser.parse_args()
    target = json.loads(args.target.read_text())
    image = Image(args.image)
    if image.sha256 != target['image_sha256']:
        raise ValueError('pinned image mismatch')
    classes = list(map(json.loads, args.classes.open()))
    functions = {f['rva']: f for f in map(json.loads, args.functions.open())}
    rows = []
    for plan in json.loads(args.plan.read_text()):
        matching = [c for c in classes if c['class'] == plan['owner']]
        if len(matching) != 1:
            raise ValueError('unique class required')
        rows.extend(extract(image, matching[0], functions, plan))
    if len(rows) != len({r['entry_rva'] for r in rows}):
        raise ValueError('duplicate member')
    args.out.write_text(json.dumps(dict(build_id=target['build_id'],
        image_sha256=image.sha256, extractor_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        members=sorted(rows, key=lambda r: r['entry_rva'])), indent=2) + '\n')
    print('Audited large form prefix adjustors:', len(rows))


if __name__ == '__main__':
    main()
