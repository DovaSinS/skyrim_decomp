// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x679d00 Actor::Function679d00
// Adapted bodies: none
#include "Actor_679d00.h"

#include <cmath>

float Actor::Function679d00()
{
    const float value = std::fabs(unkB8.Function8(0x1E)) * 0.01f;
    if (value == 0.0f) {
        return 1.0f;
    }
    return value;
}
