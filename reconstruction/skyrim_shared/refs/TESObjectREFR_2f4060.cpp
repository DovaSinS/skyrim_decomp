// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x2f4060 TESObjectREFR::CheckFlagByKind
// Adapted bodies: TestBit (a one-line flag-bit helper, similar to a generic bit test in the F3 sibling)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
#include "TESObjectREFR_2f4060.h"

// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value.
static inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

bool TESObjectREFR::CheckFlagByKind() const
{
    bool result = false;
    const TESObjectREFR* actor = formType == 0x3E ? this : nullptr;
    if (actor && formID != 7) {
        result = TestBit(formFlags, 9);
    } else if (TestBit(formFlags, 23)) {
        result = true;
    }
    return result;
}
