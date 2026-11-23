// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x301890 TESObjectREFR::Check301890
// Adapted bodies: none
#include "TESObjectREFR_301890.h"

bool TESObjectREFR::Check301890(TestRefHelper* a_helper)
{
    NiAVObject* node = Get3D2();
    if (node->unkF0 == 0) {
        return false;
    }
    return a_helper->inner->Evaluate(node->unkE4) == 2;
}
