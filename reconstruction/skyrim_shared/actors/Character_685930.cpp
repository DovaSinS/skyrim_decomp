// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x685930 Character::GetFlightRadius
// Adapted bodies: none
#include "Character_685930.h"

float Character::GetFlightRadius() const
{
    if (race) {
        float radius = race->data.flightRadius;
        return radius * GetScale();
    }
    return 0.0f;
}
