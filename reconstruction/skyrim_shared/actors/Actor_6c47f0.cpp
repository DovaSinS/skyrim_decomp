// Source exposure: community-headers (names, layout), binary-analysis (offsets and slots from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x6c47f0 Actor::RestoreActorValue
// Adapted bodies: none
#include "Actor_6c47f0.h"

void Actor::RestoreActorValue(std::int32_t a_av, float a_delta)
{
    if (a_delta > 0.0f) {
        if (GetActorValueModifier(2, a_av) < 0.0f) {
            AsActorValueOwner()->RestoreActorValue(2, a_av, a_delta);
            return;
        }
    }
    if (TestBit(g_actorValueList->actorValues[a_av]->flags, 9) && a_delta < 0.0f) {
        AsActorValueOwner()->RestoreActorValue(2, a_av, a_delta);
    }
}
