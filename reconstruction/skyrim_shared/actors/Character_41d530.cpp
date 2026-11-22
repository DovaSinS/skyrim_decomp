// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x41d530 Character::GetFollowRadiusMatchSpeed
// Adapted bodies: none
#include "Character_41d530.h"

float Character::GetFollowRadiusMatchSpeed(float a_speed)
{
    return kFollowRadiusBase + a_speed;
}
