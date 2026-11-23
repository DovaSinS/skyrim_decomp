// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6adf40 Character::Function6adf40
// Adapted bodies: none
#include "Character_6adf40.h"

void Character::Function6adf40()
{
    if (held) {
        Target6adf40* target = held->unk03(&g_type6adf40);
        if (target) {
            target->unk02();
        }
    }
}
