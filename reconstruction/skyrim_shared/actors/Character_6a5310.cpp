// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6a5310 Character::Function6a5310
// Adapted bodies: none
#include "Character_6a5310.h"

void Character::Function6a5310()
{
    RefCounted* old = held;
    if (old) {
        held = nullptr;
        old->DecRef();
    }
}
