// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x686220 Character::Function686220
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
#include "Character_686220.h"

#include <math.h>

float Character::Function686220()
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
