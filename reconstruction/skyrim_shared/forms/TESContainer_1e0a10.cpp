// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1e0a10 TESContainer::HasItem
// Adapted bodies: none
#include "TESContainer_1e0a10.h"

bool TESContainer::HasItem(TESBoundObject* item)
{
    bool found = false;
    for (std::uint32_t i = 0; i < numContainerObjects; ++i) {
        if (containerObjects[i]->obj == item) {
            found = true;
            i = numContainerObjects;  // ends the scan once the item is found
        }
    }
    return found;
}
