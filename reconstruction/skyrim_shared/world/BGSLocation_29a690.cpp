// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x29a690 BGSLocation::IsRefAtLocation
// Adapted bodies: BGSLocation::IsRefAtLocation has the same shape as the sibling body below; written from the listing, declared out of caution
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/BGSLocation.cpp:210
#include "BGSLocation_29a690.h"

// 0x29a690 BGSLocation::IsRefAtLocation
bool BGSLocation::IsRefAtLocation(const TESObjectREFR* a_ref, bool a_useEditorLocation) const
{
    bool found = false;
    if (a_ref) {
        const BGSLocation* location = a_useEditorLocation ? a_ref->GetEditorLocation1() : a_ref->GetCurrentLocation();
        while (location && !found) {
            if (location == this) {
                found = true;
            } else {
                location = location->parentLoc;
            }
        }
    }
    return found;
}
