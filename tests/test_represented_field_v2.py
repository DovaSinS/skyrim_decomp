"""Const-result migration and synthetic primary-owner refusal checks."""
import sys
from pathlib import Path
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1]/'tools'))
import represented_field_template_v1 as original
import represented_field_template_v2 as extended
from represented_field_generate_v2 import validate_owner


class Image:
    base = 0x100000000
    offset = 0
    name = '.?AVSyntheticOwner@@'
    slot = base + 0x1000

    def table(self, rva):
        assert rva == 0x2000
        return dict(offset=self.offset, type_raw=self.name)

    def number(self, rva, fmt):
        assert (rva, fmt) == (0x2010, 'Q')
        return self.slot


class ExtendedFieldLeaves(unittest.TestCase):
    def test_const_result_preserves_original_emitter(self):
        row=dict(rva=4096,size=5,operation='pointer',type='ResearchLayouts::ConcreteFormFactoryLayout',
                 field='_name',offset=8,header='reconstruction/fields/ConcreteFormFactoryLayout.h')
        self.assertIn('const void* FieldLeaf1000::Read()',extended.emit(row)['source'])
        self.assertTrue(extended.emit(row)['symbol'].endswith('QEAAPEBXXZ'))
        self.assertIn('void* FieldLeaf1000::Read()',original.emit(row)['source'])
        self.assertEqual(original.origin()['version'],'1')
        self.assertEqual(extended.origin()['version'],'2')

    def test_exact_primary_owner_binding(self):
        row=dict(rva=0x1000,owner_table=0x2000,owner_slot=2,**{'owner-rtti':'.?AVSyntheticOwner@@'})
        validate_owner(Image(),row)
        for attr,value in [('offset',8),('name','.?AVOtherOwner@@'),('slot',Image.base+0x1100)]:
            image=Image();setattr(image,attr,value)
            with self.assertRaises(ValueError):validate_owner(image,row)


if __name__ == '__main__':unittest.main()
