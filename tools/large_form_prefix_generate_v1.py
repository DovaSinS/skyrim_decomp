"""Generate separate typed large-form prefix units from audited parameters.

Only compiler-generated secondary destructor adjustors are compared. Prefixes
are partial declarations, not complete form layouts or behavior claims.
"""
from pathlib import Path
import argparse
import hashlib
import json
import adjustor_thunk_template_v3 as adjustor


def generate(root, plan):
    rows = json.loads(plan.read_text())
    dest = root / 'reconstruction/forms'
    if len({row['owner'] for row in rows}) != len(rows):
        raise ValueError('duplicate owner')
    old = (dest/'RaceComponentLayout.h').read_text()
    notice = old[:old.index('#pragma once')]
    notice = notice.replace('Drafted by GPT-6.1 Sol; shared form component prefix extension.',
                            'Drafted by GPT-6.1 Terra using typed community declarations and target metadata.')
    notice = notice.replace('include/RE/{T/TESRaceForm.h,T/TESEnchantableForm.h,T/TESValueForm.h,T/TESWeightForm.h,T/TESModelTextureSwap.h,T/TESContainer.h,B/BGSMenuDisplayObject.h,B/BGSEquipType.h}',
                            'include/RE/{B/BGSMessageIcon.h,B/BGSPickupPutdownSounds.h,T/TESAttackDamageForm.h,B/BGSBlockBashData.h}')
    notice += '// Generator: tools/large_form_prefix_generate_v1.py SHA-256 ' + hashlib.sha256(Path(__file__).read_bytes()).hexdigest() + '\n'
    notice += '// BGSMessageIcon, TESAttackDamageForm, BGSBlockBashData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)\n'
    components = {
        'MessageIconComponentLayout': '''    IconComponentLayout icon;\n''',
        'AttackDamageComponentLayout': '''    virtual std::uint16_t GetAttackDamage() const;\n    std::uint16_t attackDamage;\n''',
        'BlockBashComponentLayout': '''    ImpactDataPointeeLayout* blockBashImpactDataSet;\n    MaterialPointeeLayout* altBlockMaterialType;\n''',
    }
    sizes = {'MessageIconComponentLayout':24, 'AttackDamageComponentLayout':16, 'BlockBashComponentLayout':24}
    for cls, fields in components.items():
        text = notice + '#pragma once\n#include <cstdint>\n#include "RaceComponentLayout.h"\nnamespace ResearchLayouts {\n'
        text += 'class ImpactDataPointeeLayout;\nclass MaterialPointeeLayout;\n'
        text += f'class {cls} : public FormComponentLayout {{\npublic:\n    ~{cls}() override;\n'
        text += '    void InitializeDataComponent() override;\n    void ClearDataComponent() override;\n    void CopyComponent(FormComponentLayout*) override;\n'
        text += fields + f'}};\nstatic_assert(sizeof({cls}) == {sizes[cls]}, "community component storage");\n}}\n'
        (dest/(cls+'.h')).write_text(text)
    for row in rows:
        owner = adjustor.identifier(row['owner'])
        cls = owner + 'LargeFormPrefixLayout'
        ps = row['prefix']
        if not ps:
            raise ValueError('nonempty prefix required')
        for p in ps:
            adjustor.identifier(p['base']); adjustor.identifier(p['layout'])
        end = ps[-1]['offset'] + ps[-1]['size']
        for m in row['members']:
            adjustor.emit(m['rva'], 12, m['offset'], cls, end)
        head = notice + '#pragma once\n#include <cstddef>\n#include "RaceComponentLayout.h"\n'
        for component in components:
            if any(p['layout'] == component for p in ps):
                head += f'#include "{component}.h"\n'
        head += 'namespace ResearchLayouts {\n' + f'// {owner}: EXE_RTTI\n'
        for p in ps:
            head += f'// Represented component at {p["offset"]}: {p["base"]}\n'
        head += 'class '+cls+' : '+', '.join('public '+p['layout'] for p in ps)+' {\npublic:\n    '+cls+'();\n    ~'+cls+'() override;\n    void InitializeDataComponent() override;\n    void ClearDataComponent() override;\n    void CopyComponent(FormComponentLayout*) override;\n'
        if any(p['layout'] == 'PreloadableComponentLayout' for p in ps):
            head += '    void Unk_04() override;\n'
        head += '};\n' + f'static_assert(sizeof({cls}) == {end}, "represented prefix only");\nstruct {cls}StorageLayout {{\n'
        for i,p in enumerate(ps):
            typ = 'PreloadableVptrStorageLayout' if p['layout']=='PreloadableComponentLayout' else p['layout']
            head += f'    {typ} component{i};\n'
        head += '};\n'
        for i,p in enumerate(ps):
            head += f'static_assert(offsetof({cls}StorageLayout, component{i}) == {p["offset"]}, "target component offset");\n'
        head += '}\n'
        cpp = notice + ''.join(f'// RVA 0x{m["rva"]:x}; 12 bytes\n' for m in row['members'])
        cpp += f'#include "{cls}.h"\nnamespace ResearchLayouts {{\n{cls}::{cls}() = default;\n}}\n'
        (dest/(cls+'.h')).write_text(head)
        (dest/(cls+'.cpp')).write_text(cpp)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--root', type=Path, required=True)
    parser.add_argument('--plan', type=Path, required=True)
    args = parser.parse_args()
    generate(args.root, args.plan)
