"""Extract private per-member bindings for the existing ImageSpaceEffect family.

Inputs are local pinned image, candidate owner/RVA/table selections and public source.
Output is typed metadata under .local only; image bytes and decoded listings are never
serialized. This audit does not compile, compare, review or accept a function.
"""
import argparse
import hashlib
import json
from pathlib import Path
import sys
import capstone
from capstone.x86_const import X86_OP_IMM, X86_OP_REG, X86_REG_RCX
import imagespace_effect_adjustor_stamp_v1 as stamp
from deleting_layout_bindings_v1 import Image

ROOT = Path(__file__).resolve().parents[1]

def extract(root, image, rows):
    target = json.loads((root/'builds/target.json').read_text())
    if target['build_id'] != stamp.BUILD or image.sha256 != target['image_sha256']:
        raise ValueError('target/build hash differs')
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_64); md.detail = True
    recipe_sha256 = hashlib.sha256((root/stamp.RECIPE).read_bytes()).hexdigest()
    result = []
    for row in rows:
        owner = row['owner']; rva = row['rva']; primary = row['primary_table']; secondary = row['secondary_table']
        p = image.table(primary); s = image.table(secondary); expected = '.?AV'+owner+'@@'
        if p['type_raw'] != expected or s['type_raw'] != expected or p['offset'] != 0 or s['offset'] != 144 or p['bases'] != s['bases']:
            raise ValueError(f'{rva:#x}: owner/COL mismatch')
        base = [b for b in p['bases'] if b['type_raw'] == '.?AVImageSpaceEffect@@' and b['mdisp'] == 144 and b['pdisp'] == -1]
        parent = [b for b in p['bases'] if b['type_raw'] == '.?AVBSImagespaceShader@@' and b['mdisp'] == 0 and b['pdisp'] == -1]
        if len(base) != 1 or len(parent) != 1 or image.number(secondary, 'Q') - image.base != rva:
            raise ValueError(f'{rva:#x}: secondary base/slot mismatch')
        ins = list(md.disasm(image.read(rva,12), image.base+rva))
        if len(ins) != 2 or sum(i.size for i in ins) != 12:
            raise ValueError(f'{rva:#x}: instruction extent mismatch')
        a,j = ins
        if (a.mnemonic != 'sub' or len(a.operands) != 2 or a.operands[0].type != X86_OP_REG or a.operands[0].reg != X86_REG_RCX or a.operands[1].type != X86_OP_IMM or a.operands[1].imm != 144 or j.mnemonic != 'jmp' or len(j.operands) != 1 or j.operands[0].type != X86_OP_IMM):
            raise ValueError(f'{rva:#x}: unsupported adjustor shape')
        callee = j.operands[0].imm-image.base
        if image.number(primary,'Q')-image.base != callee:
            raise ValueError(f'{rva:#x}: primary slot/target mismatch')
        binding=stamp.bind_source(root,owner)
        result.append(dict(build_id=stamp.BUILD,recipe=stamp.RECIPE,recipe_sha256=recipe_sha256,rva=rva,size=12,owner=owner,base='ImageSpaceEffect',base_offset=144,
                           primary_table=primary,secondary_table=secondary,primary_callee=callee,
                           slot=0, **binding))
    if len({r['rva'] for r in result}) != len(result) or len({r['owner'] for r in result}) != len(result):
        raise ValueError('duplicate rva or owner')
    return result

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
    p=argparse.ArgumentParser();p.add_argument('--root',type=Path,default=ROOT);p.add_argument('--image',type=Path,required=True);p.add_argument('--selection',type=Path,required=True);p.add_argument('--out',type=Path,required=True);a=p.parse_args()
    root=a.root.resolve();out=a.out.resolve()
    if not out.is_relative_to(root/'.local'):
        raise ValueError('output must remain under root/.local')
    rows=json.loads(a.selection.read_text())['members'];audit=extract(root,Image(a.image),rows)
    out.parent.mkdir(parents=True,exist_ok=True);out.write_text(json.dumps(dict(build_id=stamp.BUILD,origin=stamp.origin(),members=audit),indent=2)+'\n');print(f'{len(audit)} independent bindings passed')
if __name__ == '__main__':main()
