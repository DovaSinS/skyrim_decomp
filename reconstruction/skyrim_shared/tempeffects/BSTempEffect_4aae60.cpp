// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x4aae60 BSTempEffectGeometryDecal::BSTempEffectGeometryDecal
// Adapted bodies: none
#include "BSTempEffect_4aae60.h"

BSTempEffectGeometryDecal::BSTempEffectGeometryDecal() : BSTempEffect(nullptr, 0.0f)
{
    decal = nullptr;
    attachedGeometry = nullptr;
    attachedGeometryParent = nullptr;
    decalNode = nullptr;
    queuedDecal = nullptr;
    texSet = nullptr;
    texSet2 = nullptr;
    origin.x = 0.0f;
    origin.y = 0.0f;
    origin.z = 0.0f;
    direction.x = 0.0f;
    direction.y = 0.0f;
    direction.z = 0.0f;
    unkA8 = 0;
    flags = 0;
    unkB0 = false;
}
