// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x32d100 BGSTextureSet::ClearData
// Adapted bodies: none
#include "BGSTextureSet_32d100.h"

// clear every texture slot, free the decal data and reset the flags
void BGSTextureSet::ClearData()
{
    TagScope scope;
    for (int i = 0; i < 8; ++i)
        textures[i].ClearDataComponent();
    if (decalData)
        delete decalData;
    flags = 0;
}
