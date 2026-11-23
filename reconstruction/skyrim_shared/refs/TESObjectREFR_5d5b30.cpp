// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x5d5b30 TESObjectREFR::VisitWorn5d5b30
// Adapted bodies: none
#include "TESObjectREFR_5d5b30.h"

void TESObjectREFR::VisitWorn5d5b30()
{
    WornVisitorA visitor;
    InventoryChanges* changes = GetInventoryChanges();
    if (changes) {
        changes->VisitWornItems(visitor);
    }
}
