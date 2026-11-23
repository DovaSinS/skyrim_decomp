// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x2f51b0 TESObjectREFR::IsSpecialKind
// Adapted bodies: none
#include "TESObjectREFR_2f51b0.h"

bool TESObjectREFR::IsSpecialKind()
{
    if (!baseObject) {
        return false;
    }
    if (TestSlot2A()) {
        return true;
    }
    switch (baseObject->formType) {
    case 15:
    case 24:
    case 29:
    case 31:
    case 36:
        return true;
    default:
        return false;
    }
}
