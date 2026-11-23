// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x2e3ac0 TESObjectREFR::Function2e3ac0
// Adapted bodies: none
#include "TESObjectREFR_2e3ac0.h"

void TESObjectREFR::Function2e3ac0(bool a_set)
{
    std::uint8_t type = objectReference->formType;
    if (type == 0x1D || type == 0x1F) {
        return;
    }
    formFlags = a_set ? (formFlags | (1u << 8)) : (formFlags & ~(1u << 8));
}
