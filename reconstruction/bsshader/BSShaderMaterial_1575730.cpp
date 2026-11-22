// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x1575730 BSShaderMaterial::DoIsCopy
// Adapted bodies: none
#include "BSShaderMaterial_1575730.h"

bool BSShaderMaterial::DoIsCopy(BSShaderMaterial* a_other)
{
    if (GetType() != a_other->GetType()) {
        return false;
    }
    if (texCoordOffset[0].x != a_other->texCoordOffset[0].x) {
        return false;
    }
    if (texCoordOffset[0].y != a_other->texCoordOffset[0].y) {
        return false;
    }
    if (texCoordScale[0].x != a_other->texCoordScale[0].x) {
        return false;
    }
    if (texCoordScale[0].y != a_other->texCoordScale[0].y) {
        return false;
    }
    return true;
}
