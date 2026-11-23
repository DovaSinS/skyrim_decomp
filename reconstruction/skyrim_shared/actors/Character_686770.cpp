// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x686770 Character::Function686770
// Adapted bodies: TestBit (header), momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp, CC0-1.0
#include "Character_686770.h"

bool Character::Function686770()
{
    ExtraByteRecord* extra = extraList.Function1702b0();
    if (extra) {
        return extra->unk10;
    }
    return TestBit(unk1f8->unk108, 21);
}

