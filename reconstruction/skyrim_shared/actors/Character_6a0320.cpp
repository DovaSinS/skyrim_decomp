// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6a0320 Character::Function6a0320
// Adapted bodies: none
#include "Character_6a0320.h"

void Character::Function6a0320(bool a_set)
{
    if (a_set) {
        unk204 |= 1u << 24;
    } else {
        unk204 &= ~(1u << 24);
    }
}
