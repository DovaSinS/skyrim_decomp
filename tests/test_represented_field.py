"""Synthetic complete-shape and represented-source checks; no game inputs."""
import sys
from pathlib import Path
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1]/'tools'))
import represented_field_generate as generate
import represented_field_template_v1 as template


def rows(*instructions):
    # One synthetic byte marker per decoded row; no target bytes are used.
    return [[i, '00', text, []] for i, text in enumerate(instructions)]


class FieldLeaves(unittest.TestCase):
    def test_complete_shapes(self):
        for text, kind in [('mov rax, qword ptr', 'pointer'), ('lea rax,', 'address')]:
            self.assertEqual(generate.extract(rows(text+' [rcx + 0x10]', 'ret'), 2), (kind, 16))
        self.assertEqual(generate.extract(rows('cmp qword ptr [rcx + 0x50], 0x0', 'setne al', 'ret'), 3), ('present', 80))

    def test_reject_unreviewed_shapes(self):
        for decoded, size in [(rows('lea rax, [rdx + 0x10]', 'ret'),2),
                              (rows('lea rax, [rcx + 0x10]', 'ret', 'nop'),3),
                              (rows('cmp qword ptr [rcx + 0x50], 0x0', 'sete al', 'ret'),3),
                              (rows('lea rax, [rcx + 0x10]', 'ret'),3)]:
            with self.assertRaises(ValueError):
                generate.extract(decoded,size)

    def test_reject_gap(self):
        decoded=rows('lea rax, [rcx + 0x10]', 'ret');decoded[1][0]=2
        with self.assertRaises(ValueError):generate.extract(decoded,2)

    def test_emitter_uses_existing_field(self):
        row=dict(rva=4096,size=9,operation='present',type='ResearchLayouts::NativeFunctionLayout',
                 field='callback',offset=80,header='reconstruction/fields/NativeFunctionLayout.h')
        emitted=template.emit(row)
        self.assertIn('return callback != nullptr;',emitted['source'])
        self.assertIn('public ResearchLayouts::NativeFunctionLayout',emitted['header'])
        self.assertIn('offsetof(ResearchLayouts::NativeFunctionLayout, callback) == 80',emitted['header'])
        self.assertNotIn('padding',emitted['header'])
        row['field']='callback + 1'
        with self.assertRaises(ValueError):template.emit(row)


if __name__ == '__main__':unittest.main()
