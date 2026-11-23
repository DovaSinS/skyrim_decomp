// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x674030 Character::Function674030
// Adapted bodies: TestBit (header), momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp, CC0-1.0
#include "Character_674030.h"

bool Character::Function674030(Character* a_target)
{
    return (unkC8 & 0x1e00000) == 0x800000 ||
           (!(TestBit(unk204, 18) || unk2f0()) &&
            (!TestBit(unk204, 19) || (a_target && a_target == unk31df300)));
}
