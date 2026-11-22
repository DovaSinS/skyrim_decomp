// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x390190 BGSHeadPart::InitializeData
// Adapted bodies: InitializeData, similar to fo4-private@1b765c70 src/Shared/TESForms/Character/BGSHeadPart.cpp:23; derived from the listing
#include "BGSHeadPart_390190.h"

// reset the part's type, texture set, colour, races and each morph model
void BGSHeadPart::InitializeData()
{
    flags = 0;
    type = 0;
    textureSet = nullptr;
    color = nullptr;
    validRaces = nullptr;
    for (int i = 0; i < 3; ++i)
        morphs[i].InitializeDataComponent();
}
