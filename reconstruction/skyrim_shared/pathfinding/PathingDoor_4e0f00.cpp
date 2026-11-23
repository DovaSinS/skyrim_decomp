// Source exposure: mixed (FO4 layout names; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x4e0f00 PathingDoor::Function4e0f00
// Adapted bodies: none
#include "PathingDoor_4e0f00.h"

void PathingDoor::Function4e0f00(PathingDoorReader* a_reader)
{
    a_reader->Slot0C(&DoorID);
    locFlagsThisSide |= 2;
    locFlagsOtherSide |= 2;
    hDoor = kNullHandle;
}
