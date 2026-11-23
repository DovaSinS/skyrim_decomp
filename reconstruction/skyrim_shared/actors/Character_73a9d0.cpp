// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x73a9d0 Character::Function73a9d0
// Adapted bodies: none
#include "Character_73a9d0.h"

bool Character::Function73a9d0()
{
    if (data) {
        return (data->flags108 >> 2) & 1;
    }
    return false;
}
