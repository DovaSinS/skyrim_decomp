// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6c2ce0 Actor::Function6c2ce0
// Adapted bodies: none
#include "Actor_6c2ce0.h"

void Actor::Function6c2ce0(bool a_set)
{
    if (a_set) {
        flagsE8 |= 0x20;
    } else {
        flagsE8 &= ~0x20u;
    }
}
