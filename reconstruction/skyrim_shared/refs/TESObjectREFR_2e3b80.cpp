// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x2e3b80 TESObjectREFR::Function2e3b80
// Adapted bodies: none
#include "TESObjectREFR_2e3b80.h"

void TESObjectREFR::Function2e3b80(bool a_set)
{
    if (objectReference->formType == 0x1F) {
        std::uint32_t flags = a_set ? (formFlags | (1u << 9)) : (formFlags & ~(1u << 9));
        if (extraList.GetLightData() && !a_set) {
            Leaf14ecc70::Invoke();
        }
        formFlags = flags;
    }
}
