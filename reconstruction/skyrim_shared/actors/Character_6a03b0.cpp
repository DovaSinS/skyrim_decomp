// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6a03b0 Character::Function6a03b0
// Adapted bodies: TestBit (written from the project cookbook helper; shape matches the sibling body below)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
#include "Character_6a03b0.h"

// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value.
inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

bool Character::Function6a03b0()
{
    if (unk1F8) {
        return TestBit(unk1F8->flags, 9);
    }
    return false;
}
