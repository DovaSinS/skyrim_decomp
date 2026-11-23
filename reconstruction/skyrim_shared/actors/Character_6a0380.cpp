// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6a0380 Character::Function6a0380
// Adapted bodies: none
#include "Character_6a0380.h"

void Character::Function6a0380(bool a_set)
{
    if (a_set) {
        unk204 |= 1u << 26;
    } else {
        unk204 &= ~(1u << 26);
    }
}
