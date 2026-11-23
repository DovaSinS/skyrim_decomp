// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x6739d0 Character::Function6739d0
// Adapted bodies: none
#include "Character_6739d0.h"

bool Character::Function6739d0()
{
    return std::fabs(actorValueOwner.GetActorValue(ActorValue::kWaterBreathing)) > 0.0001f;
}

