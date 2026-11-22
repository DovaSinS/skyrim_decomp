// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x8f1b70 Character::Interpolate
// Adapted bodies: none
#include "Character_8f1b70.h"

float Character::Interpolate(float a_t, float a_from, float a_to)
{
    return (a_to - a_from) * a_t + a_from;
}
