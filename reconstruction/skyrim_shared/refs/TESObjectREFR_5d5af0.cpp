// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x5d5af0 TESObjectREFR::VisitWorn5d5af0
// Adapted bodies: none
#include "TESObjectREFR_5d5af0.h"

void TESObjectREFR::VisitWorn5d5af0()
{
    WornVisitorB visitor;
    InventoryChanges* changes = GetInventoryChanges();
    if (changes) {
        changes->VisitWornItems(visitor);
    }
}
