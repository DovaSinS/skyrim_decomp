// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1518b80 BSLightingShaderProperty::RegisterStreamables
// Adapted bodies: none
#include "BSLightingShaderProperty_1518b80.h"

bool BSLightingShaderProperty::RegisterStreamables(NiStream& a_stream)
{
    if (!BSShaderProperty::RegisterStreamables(a_stream)) {
        return false;
    }
    if (material) {
        material->textureSet->RegisterStreamables(a_stream);
    }
    return true;
}
