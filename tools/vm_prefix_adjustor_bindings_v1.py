"""Extract large SkyrimVM prefix adjustor bindings from a private pinned image.

The represented declaration is SkyrimVMInterfacePrefixLayout. Its 54 fieldless
interfaces were recovered independently; this extractor checks their RTTI order,
secondary destructor slots and primary transfer target. It writes metadata only.
It does not establish a match or an original complete SkyrimVM definition.
"""
import argparse
import hashlib
import json
from pathlib import Path

from deleting_layout_bindings_v1 import Image


def extract(image, owner, functions):
    import capstone

    primary = image.table(owner['vftable'])
    if primary['type_raw'] != '.?AVSkyrimVM@@' or primary['offset'] != 0:
        raise ValueError('primary SkyrimVM RTTI required')
    interfaces = [b for b in primary['bases'][1:] if b['pdisp'] == -1 and (
        b['type_raw'].startswith('.?AV?$BSTEventSink@') or b['type_raw'] in (
            '.?AVIFreezeQuery@BSScript@@', '.?AVIStackCallbackSaveInterface@BSScript@@'))]
    interfaces.sort(key=lambda b: b['mdisp'])
    if len(interfaces) != 54 or [b['mdisp'] for b in interfaces] != list(range(0, 432, 8)):
        raise ValueError('represented interface prefix differs')
    if [b['type_raw'] for b in interfaces[:2]] != [
            '.?AVIFreezeQuery@BSScript@@', '.?AVIStackCallbackSaveInterface@BSScript@@']:
        raise ValueError('primary interface order differs')
    target = image.number(owner['vftable'], 'Q') - image.base
    decoder = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64)
    decoder.detail = True
    rows = []
    for secondary in owner['secondary_vftables']:
        table = secondary['rva']
        entry = image.number(table, 'Q') - image.base
        fn = functions.get(entry)
        if fn is None or fn['size'] != 12:
            continue
        locator = image.table(table)
        offset = locator['offset']
        bases = [b for b in interfaces if b['mdisp'] == offset]
        if locator['type_raw'] != primary['type_raw'] or len(bases) != 1 or offset < 128:
            raise ValueError('secondary table is outside the represented large prefix')
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
            raise ValueError('transfer differs from primary destructor slot')
        rows.append({'entry-rva': entry, 'size': 12, 'offset': offset,
                     'secondary-table': table, 'target-rva': target,
                     'base-type': bases[0]['type_raw']})
    if len(rows) != len({r['entry-rva'] for r in rows}):
        raise ValueError('duplicate secondary entry')
    return sorted(rows, key=lambda r: r['entry-rva'])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--image', type=Path, required=True)
    parser.add_argument('--target', type=Path, required=True)
    parser.add_argument('--classes', type=Path, required=True)
    parser.add_argument('--functions', type=Path, required=True)
    parser.add_argument('--out', type=Path, required=True)
    args = parser.parse_args()
    target = json.loads(args.target.read_text())
    image = Image(args.image)
    if image.sha256 != target['image_sha256']:
        raise ValueError('pinned image hash mismatch')
    owners = [json.loads(line) for line in args.classes.open()]
    owners = [c for c in owners if c['class'] == 'SkyrimVM']
    if len(owners) != 1:
        raise ValueError('unique SkyrimVM owner required')
    functions = {f['rva']: f for f in map(json.loads, args.functions.open())}
    rows = extract(image, owners[0], functions)
    args.out.write_text(json.dumps(dict(
        build_id=target['build_id'], image_sha256=image.sha256,
        extractor_sha256=hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        members=rows), indent=2) + '\n')
    print('Audited large prefix adjustors:', len(rows))


if __name__ == '__main__':
    main()
