"""Synthetic encoding migration preserves complete digests and old source forms."""
from pathlib import Path
import sys
import unittest

sys.path.insert(0,str(Path(__file__).resolve().parents[1]/'tools'))
import family_review
import represented_field_metadata_v2 as metadata
import represented_field_family_metadata_v2 as template


class Metadata(unittest.TestCase):
    def test_digest_words_roundtrip_and_accepted_ranges(self):
        digest='0123456789abcdef'*4
        original={'entry-rva':4096,'layout-sha256':digest,'operation':'address'}
        encoded=metadata.parameters(original,1)
        self.assertEqual(''.join(f'{encoded[f"layout-sha256-word{i}"]:08x}' for i in range(8)),digest)
        self.assertEqual(original['layout-sha256'],digest)
        self.assertTrue(family_review.in_ranges(encoded,family_review.exact_ranges([encoded])))
        with self.assertRaises(ValueError):family_review.exact_ranges([original])

    def test_pinned_delegation_keeps_cpp_and_origin_lineage(self):
        row=dict(rva=4096,size=5,operation='pointer',type='ResearchLayouts::ConcreteFormFactoryLayout',
                 field='_name',offset=8,header='reconstruction/fields/ConcreteFormFactoryLayout.h')
        for version in (1,2):
            self.assertEqual(template.emit(row,version),template.emitter(version).emit(row))
            self.assertEqual(template.origin(version)['version'],f'{version}-metadata2')


if __name__=='__main__':unittest.main()
