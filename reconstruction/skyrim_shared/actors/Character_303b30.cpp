// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x303b30 Character::Function303b30
// Adapted bodies: none
#include "Character_303b30.h"

Form* Character::Function303b30()
{
    Form** slot = list70.Get();
    if (slot && *slot) {
        if ((*slot)->formType == 0x3c)
            return *slot;
    }
    return nullptr;
}
