// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1e5f10 Character::Function1e5f10
// Adapted bodies: TestBit (header), momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp, CC0-1.0
#include "Character_1e5f10.h"

void Character::Function1e5f10(bool a_set)
{
    if (TestBit(flags10, 6) != a_set) {
        if (a_set) {
            flags10 |= 0x40;
        } else {
            flags10 &= ~0x40u;
        }
        unk50(1);
    }
}
