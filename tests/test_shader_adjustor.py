"""Original synthetic instruction rows probe fail-closed enrollment semantics."""
import sys
from pathlib import Path
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1]/'tools'))
import shader_adjustor_generate as generator


class ShaderAdjustorExtraction(unittest.TestCase):
    def rows(self, register='rcx', amount='16', transfer='jmp 0x140002000'):
        # Encodings are placeholders for widths only; these are original synthetic rows.
        return [(0, 'aa bb cc dd', f'sub {register}, {amount}'),
                (4, 'aa bb cc dd ee', transfer)]

    def test_signed_adjustment_and_independent_target(self):
        self.assertEqual(generator.decode(self.rows(),0x1000,9,0x140000000),0x2000)
        self.assertEqual(generator.decode(self.rows(transfer='jmp 0x140003000'),0x1000,9,0x140000000),0x3000)

    def test_reject_other_argument(self):
        with self.assertRaises(ValueError):
            generator.decode(self.rows(register='rdx'),0x1000,9,0x140000000)

    def test_reject_wrong_adjustment(self):
        with self.assertRaises(ValueError):
            generator.decode(self.rows(amount='-16'),0x1000,9,0x140000000)

    def test_reject_uncovered_tail(self):
        with self.assertRaises(ValueError):
            generator.decode(self.rows(),0x1000,10,0x140000000)

    def test_reject_extent_gap(self):
        rows=self.rows();rows[1]=(5,*rows[1][1:])
        with self.assertRaises(ValueError):
            generator.decode(rows,0x1000,9,0x140000000)


if __name__ == '__main__':
    unittest.main()
