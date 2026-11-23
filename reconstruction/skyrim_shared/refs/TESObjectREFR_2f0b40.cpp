// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x2f0b40 TESObjectREFR::Function2f0b40
// Adapted bodies: none
#include "TESObjectREFR_2f0b40.h"

void* TESObjectREFR::Function2f0b40()
{
    void* leveled = extraList.GetLeveledNPC();
    if (leveled) {
        return leveled;
    }
    return objectReference;
}
