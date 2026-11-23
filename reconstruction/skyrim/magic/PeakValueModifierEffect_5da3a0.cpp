// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x5da3a0 PeakValueModifierEffect::Function5da3a0
// Adapted bodies: none
#include "PeakValueModifierEffect_5da3a0.h"

bool PeakValueModifierEffect::Function5da3a0(ActiveEffect* other) const
{
    if (other) {
        TESForm* otherForm = other->Function5bb090()->Function14b4f0();
        if (otherForm && otherForm == Function5bb090()->Function14b4f0()) {
            if (unk90 == other->unk90) {
                return true;
            }
        }
    }
    return false;
}
