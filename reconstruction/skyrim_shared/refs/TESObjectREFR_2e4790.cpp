// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x2e4790 TESObjectREFR::GetOnLocalMap
// Adapted bodies: none
#include "TESObjectREFR_2e4790.h"

// TestBitClear: GUESS(low); tests that a flag-word bit is clear, by bit index, taking the word by value.
inline bool TestBitClear(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((~(a_flags >> a_bit)) & 1) != 0;
}

// 0x2e4790 TESObjectREFR::GetOnLocalMap
bool TESObjectREFR::GetOnLocalMap() const
{
    return TestBitClear(formFlags, 9) && baseForm->GetOnLocalMap();
}
