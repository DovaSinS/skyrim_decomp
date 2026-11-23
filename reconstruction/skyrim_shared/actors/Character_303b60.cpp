// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x303b60 Character::Function303b60
// Adapted bodies: none
#include "Character_303b60.h"

NiPoint3* Character::Function303b60()
{
    StartingExtra* extra = extraList.Function164c50();
    if (extra) {
        return &extra->point;
    }
    return &unk54;
}

