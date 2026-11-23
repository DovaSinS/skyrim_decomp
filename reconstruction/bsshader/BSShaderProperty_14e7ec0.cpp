// Source exposure: binary-analysis (pinned image listing only).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x14e7ec0 BSShaderProperty::CanMerge
// Adapted bodies: none
#include "BSShaderProperty_14e7ec0.h"

bool BSShaderProperty::CanMerge(const BSShaderProperty* other) const
{
    if (shaderFlags38 != other->shaderFlags38) {
        return false;
    }
    return material78->IsEqual(other->material78);
}
