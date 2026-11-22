// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x190a00 MapMarkerData::Copy
// Adapted bodies: none
#include "TESFullName_190a00.h"

// copy the location name, visibility flags and marker type from another marker
void MapMarkerData::Copy(MapMarkerData* other)
{
    locationName.CopyComponent(&other->locationName);
    flags = other->flags;
    type = other->type;
}
