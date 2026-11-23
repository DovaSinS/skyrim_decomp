// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6c9ec0 Character::Function6c9ec0
// Adapted bodies: TestBit (header), momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp, CC0-1.0
#include "Character_6c9ec0.h"

void Character::Function6c9ec0(void* a_arg1, void* a_arg2)
{
    std::uint32_t flags = gBGSSaveLoadGame->unk340;
    if (!TestBit(flags, 1) || TestBit(flags, 3)) {
        if (unk160) {
            unk160->Function560bf0(a_arg1, a_arg2);
        }
    }
}

