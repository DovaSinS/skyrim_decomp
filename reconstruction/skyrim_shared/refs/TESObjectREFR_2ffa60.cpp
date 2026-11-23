// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x2ffa60 TESObjectREFR::Function2ffa60
// Adapted bodies: TestBit (momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422, CC0-1.0); the by-value bit-index helper shape
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
#include "TESObjectREFR_2ffa60.h"

// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value.
inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

bool TESObjectREFR::Function2ffa60()
{
    TESBoundObject* base = objectReference;
    if (base && base->formType == 0x28) {
        return TestBit(base->furnitureFlags, 26);
    }
    return false;
}
