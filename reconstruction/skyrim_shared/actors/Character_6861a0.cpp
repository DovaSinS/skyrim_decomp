// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6861a0 Character::Function6861a0
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
#include "Character_6861a0.h"

#include <math.h>

float Character::Function6861a0()
{
    float result = 1.0f;
    if (unk1F8) {
        float v = unk1F8->value;
        if (fabsf(v) > 1.0e-4f) {
            result = 1.0f / v;
        }
    }
    return result;
}
