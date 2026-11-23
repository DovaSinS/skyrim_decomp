// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x93e4f0 Inventory3DManager::SetModelTransform
// Adapted bodies: NiPoint3::operator= (header), momusdigital/f3_decomp@f5bac1b5, CC0-1.0
#include "Inventory3DManager_93e4f0.h"

void Inventory3DManager::SetModelTransform(const NiPoint3* pos, float scale)
{
    ModelPosition = *pos;
    ModelScale = scale;
    storedPosition = ModelPosition;
    storedScale = ModelScale;
}
