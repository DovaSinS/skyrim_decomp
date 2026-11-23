// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x2e3fd0 TESObjectREFR::Function2e3fd0
// Adapted bodies: none
#include "TESObjectREFR_2e3fd0.h"

// ResolveBase: GUESS(low); picks the form the check looks at, inlined into the caller.
static void* ResolveBase(TESBoundObject* a_base)
{
    if (a_base) {
        if (a_base->formType == 7) {
            return a_base;
        }
        if (a_base->formType == 0x32) {
            return a_base->unkF8;
        }
    }
    return nullptr;
}

bool TESObjectREFR::Function2e3fd0()
{
    return ResolveBase(objectReference) != nullptr;
}
