// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6d6ad0 Character::SetDualCasting
// Adapted bodies: none
#include "Character_6d6ad0.h"

void Character::SetDualCasting(bool a_dualCasting)
{
    if (currentProcess) {
        SpellView* spell = selectedSpells[0];
        if (spell && !spell->unk5F()) {
            currentProcess->Function6f6400(a_dualCasting);
        }
    }
}
