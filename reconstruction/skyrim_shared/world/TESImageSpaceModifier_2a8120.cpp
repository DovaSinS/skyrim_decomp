// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x2a8120 TESImageSpaceModifier::InitializeData
#include "TESImageSpaceModifier_2a8120.h"

void TESImageSpaceModifier::InitializeData()
{
    ZeroBlock(&data, 0, sizeof(data));
    data.unk04 = 1.0f;
    data.unkCC = 0.5f;
    data.unkD0 = 0.5f;
    data.unkE0 = 0;
    data.unkE1 = 0;
}
