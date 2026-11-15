"""Synthetic failures for represented-wrapper target binding; no game inputs."""
import copy
from pathlib import Path
import sys
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
import represented_wrapper_v3 as wrapper


class SyntheticImage:
    base = 0x140000000

    def __init__(self):
        self.values = {(0x2000, 'Q'): self.base + 0x1000,
                       (0x1010, 'i'): 0x3000 - 0x1014,
                       (0x1022, 'i'): 0x4000 - 0x1026,
                       (0x101a, 'I'): 88, (0x1018, 'b'): 13}
        self.identity = dict(type_raw='.?AVSynthetic@@', offset=0)

    def number(self, rva, fmt='I'):
        return self.values[rva, fmt]

    def table(self, rva):
        assert rva == 0x2000
        return self.identity


class RepresentedWrapperTests(unittest.TestCase):
    def setUp(self):
        self.image = SyntheticImage()
        self.member = dict(rva=0x1000, owner_table=0x2000, owner_slot=0,
                           owner_rtti='.?AVSynthetic@@', object_size=88,
                           destructor=0x3000, deallocator=0x4000)
        self.params = {'entry-rva': 0x1000, 'size': 52, 'object-size': 88,
                       'destructor-rva': 0x3000, 'deallocator-rva': 0x4000}

    def test_independent_binding(self):
        wrapper.audit(self.image, self.member, self.params)

    def test_rejects_each_wrong_operand(self):
        for key in self.image.values:
            image = copy.deepcopy(self.image)
            image.values[key] += 1
            with self.subTest(key=key), self.assertRaises(ValueError):
                wrapper.audit(image, self.member, self.params)

    def test_rejects_wrong_owner(self):
        for field, value in (('type_raw', '.?AVOther@@'), ('offset', 8)):
            image = copy.deepcopy(self.image)
            image.identity[field] = value
            with self.subTest(field=field), self.assertRaises(ValueError):
                wrapper.audit(image, self.member, self.params)

    def test_catalog_and_dependencies_are_pinned(self):
        self.assertEqual(wrapper.sha(wrapper.ROOT / wrapper.CATALOG), wrapper.CATALOG_SHA256)
        for path, digest in wrapper.DEPENDENCIES.items():
            self.assertEqual(wrapper.sha(wrapper.ROOT / path), digest)


if __name__ == '__main__':
    unittest.main()
