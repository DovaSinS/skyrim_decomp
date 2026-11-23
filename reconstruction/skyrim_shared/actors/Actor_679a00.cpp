// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x679a00 Actor::Function679a00
// Adapted bodies: none
#include "Actor_679a00.h"

float Actor::Function679a00(int a_akValue)
{
    float permanent = avOwner.GetPermanentActorValue(a_akValue);
    if (permanent != 0.0f) {
        return avOwner.GetActorValue(a_akValue) / permanent;
    }
    return 1.0f;
}
