// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x3ac550 BGSSceneActionPackage::LoadBuffer
// Adapted bodies: none
#include "BGSSceneActionPackage_3ac550.h"

void BGSSceneActionPackage::LoadBuffer(void* a_arg1, BGSLoadGameBuffer* a_buf)
{
    a_buf->LoadDataEndian(&iCurrentPackIndex, 4, 4);
    if (iCurrentPackIndex >= packages.size) {
        iCurrentPackIndex = packages.size - 1;
    }
    BGSSceneAction::LoadBuffer(a_arg1, a_buf);
}
