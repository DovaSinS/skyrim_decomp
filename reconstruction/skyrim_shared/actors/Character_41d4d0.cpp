// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x41d4d0 Character::Function41d4d0
// Adapted bodies: none
#include "Character_41d4d0.h"

float Character::Function41d4d0(float a_value)
{
    float shifted = a_value - gOffset;
    float scaled = gScale * a_value;
    return shifted > scaled ? shifted : scaled;
}
