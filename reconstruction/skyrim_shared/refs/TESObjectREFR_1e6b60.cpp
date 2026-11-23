// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1e6b60 TESObjectREFR::Function1e6b60
// Adapted bodies: none
#include "TESObjectREFR_1e6b60.h"

void TESObjectREFR::Function1e6b60(std::uint16_t a_mask, bool a_set)
{
    if (a_set) {
        inGameFormFlags |= a_mask;
    } else {
        inGameFormFlags &= ~a_mask;
    }
    AddChange(1);
}
