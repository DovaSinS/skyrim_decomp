// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x32c2d0 BGSStandardSoundDef::Unk_02
// Adapted bodies: none
#include "BGSStandardSoundDef_32c2d0.h"

// the sound is usable at this distance when its output model allows it and its conditions hold for the player
bool BGSStandardSoundDef::Unk_02(float distance)
{
    if (!outputModel)
        return false;
    if (outputModel->flags & 1) {
        if (!outputModel->attenuation)
            return false;
        if (distance >= outputModel->attenuation->maxDistance)
            return false;
    }
    if (conditions && !conditions->IsTrue(playerSingleton, playerSingleton))
        return false;
    return true;
}
