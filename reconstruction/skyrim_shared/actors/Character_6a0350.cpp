// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6a0350 Character::Function6a0350
// Adapted bodies: none
#include "Character_6a0350.h"

void Character::Function6a0350(bool a_set)
{
    if (a_set) {
        unk204 |= 1u << 25;
    } else {
        unk204 &= ~(1u << 25);
    }
}
