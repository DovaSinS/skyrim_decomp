// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x152a210 BSEffectShaderProperty::ForEachTexture
// Adapted bodies: none
#include "BSEffectShaderProperty_152a210.h"

std::int32_t BSEffectShaderProperty::ForEachTexture(BSShaderProperty::ForEachVisitor& a_visitor)
{
    NiSourceTexture* texture = material->sourceTexture;
    std::int32_t result = static_cast<std::int32_t>(a_visitor.Accept(texture));
    if (result == 1) {
        a_visitor.Accept(material->greyscaleTexture);
    }
    return result;
}
