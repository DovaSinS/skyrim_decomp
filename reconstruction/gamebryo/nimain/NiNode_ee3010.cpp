// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xee3010 NiNode::AttachProperty
// Adapted bodies: none
#include "NiNode_ee3010.h"

void NiNode::AttachProperty(NiAlphaProperty* a_property)
{
    const std::uint16_t count = childCount;
    for (std::uint16_t i = 0; i < count; ++i) {
        NiAVObject* child = children[i];
        if (child) {
            child->AttachProperty(a_property);
        }
    }
}
