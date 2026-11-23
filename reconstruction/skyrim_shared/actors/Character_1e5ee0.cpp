// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1e5ee0 Character::Function1e5ee0
// Adapted bodies: none
#include "Character_1e5ee0.h"

void Character::Function1e5ee0(bool a_set)
{
    if (a_set) {
        unk10 |= 0x20000;
    } else {
        unk10 &= ~0x20000u;
    }
}
