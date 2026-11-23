// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x41d3f0 Character::Function41d3f0
// Adapted bodies: none
#include "Character_41d3f0.h"

int AIFormulas::GetSoundLevelValue(SOUND_LEVEL a_level)
{
    int value = 0;
    switch (a_level) {
    case kLevel0:
        value = gValue0;
        break;
    case kLevel1:
        value = gValue1;
        break;
    case kLevel2:
        value = gValue2;
        break;
    case kLevel3:
        value = gValue3;
        break;
    }
    return value;
}
