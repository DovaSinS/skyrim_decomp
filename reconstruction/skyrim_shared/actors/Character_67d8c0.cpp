// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x67d8c0 Character::ShouldSaveAnimationData
// Adapted bodies: none
#include "Character_67d8c0.h"

bool Character::ShouldSaveAnimationData()
{
    if (gBGSSaveLoadGame) {
        if (IsFlagBitSet(gBGSSaveLoadGame->unk340, 2) && unk7B()) {
            return true;
        }
        if (!IsFlagBitSet(gBGSSaveLoadGame->unk340, 2) && unk7A()) {
            return true;
        }
    }
    return false;
}
