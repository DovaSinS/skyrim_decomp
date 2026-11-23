// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x2f5210 TESObjectREFR::IsUsableLight
// Adapted bodies: TestBit (a one-line flag-bit helper, similar to a generic bit test in the F3 sibling)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
#include "TESObjectREFR_2f5210.h"

// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value.
static inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

bool TESObjectREFR::IsUsableLight() const
{
    if ((formFlags & 0x820) != 0) {
        return false;
    }
    if (baseObject->formType == 0x1D && TestBit(formFlags, 23)) {
        return false;
    }
    return true;
}
