// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x2e3b30 TESObjectREFR::Function2e3b30
// Adapted bodies: none
#include "TESObjectREFR_2e3b30.h"

void TESObjectREFR::Function2e3b30(bool a_set)
{
    TESObjectREFR* actor = formType == 0x3E ? this : nullptr;
    if (actor) {
        return;
    }
    formFlags = a_set ? (formFlags | (1u << 20)) : (formFlags & ~(1u << 20));
}
