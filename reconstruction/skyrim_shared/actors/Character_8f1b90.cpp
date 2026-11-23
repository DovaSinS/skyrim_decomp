// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x8f1b90 Character::Function8f1b90
// Adapted bodies: none
#include "Character_8f1b90.h"

float Character::Function8f1b90(float a_value, float a_lo, float a_hi, float a_from, float a_to)
{
    float t = (a_value - a_lo) / (a_hi - a_lo);
    if (t < 0.0f) {
        t = 0.0f;
    }
    if (t > 1.0f) {
        t = 1.0f;
    }
    return a_from + t * (a_to - a_from);
}
