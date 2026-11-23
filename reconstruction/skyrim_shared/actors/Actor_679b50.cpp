// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x679b50 Actor::Function679b50
// Adapted bodies: none
#include "Actor_679b50.h"

float Actor::Function679b50()
{
    const float base = unkB8.Function10(0x18);
    if (base != 0.0f) {
        return unkB8.Function8(0x18) / base;
    }
    return 1.0f;
}
