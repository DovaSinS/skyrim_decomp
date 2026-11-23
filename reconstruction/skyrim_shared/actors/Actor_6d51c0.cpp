// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6d51c0 Actor::Function6d51c0
// Adapted bodies: none
#include "Actor_6d51c0.h"

void Actor::Function6d51c0(ActiveEffect* a_effect)
{
    if (a_effect && unk58 && a_effect->unk48) {
        if (ReturnLeaf1539e0::Invoke(a_effect->Function5bb090())) {
            unk58->Function7271e0();
        }
    }
}
