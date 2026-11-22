// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x73a2f0 Character::GetFaceAnimationData
// Adapted bodies: none
#include "Character_73a2f0.h"

void* Character::GetFaceAnimationData()
{
    FaceNodeView* node = unk61();
    if (node) {
        return node->animationData;
    }
    return nullptr;
}
