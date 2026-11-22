// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x32d090 BGSTextureSet::InitializeData
// Adapted bodies: InitializeData, similar to fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSTextureSet.cpp:30; derived from the listing
#include "BGSTextureSet_32d090.h"

// reset every texture slot, then drop the decal data and flags
void BGSTextureSet::InitializeData()
{
    for (int i = 0; i < 8; ++i)
        textures[i].InitializeDataComponent();
    decalData = nullptr;
    flags = 0;
}
