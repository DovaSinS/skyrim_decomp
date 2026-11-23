// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x2f05b0 TESObjectREFR::Function2f05b0
// Adapted bodies: none
#include "TESObjectREFR_2f05b0.h"

bool TESObjectREFR::Function2f05b0(void* a_other)
{
    void* leveled = extraList.GetLeveledNPC();
    void* other = extraList.Function1696a0();
    if (objectReference == a_other || leveled == a_other || other == a_other) {
        return true;
    }
    return false;
}
