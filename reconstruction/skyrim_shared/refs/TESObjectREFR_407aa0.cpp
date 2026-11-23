// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x407aa0 TESObjectREFR::GetWorldObject
// Adapted bodies: none
#include "TESObjectREFR_407aa0.h"

WorldObject* TESObjectREFR::GetWorldObject(TESObjectREFR* a_ref)
{
    WorldObject* result = nullptr;
    if (a_ref) {
        TESObjectCELL* cell = a_ref->parentCell;
        if (cell) {
            bhkWorld* world = cell->GetbhkWorld();
            if (world) {
                result = static_cast<WorldObject*>(world->part);
            }
        }
    }
    return result;
}
