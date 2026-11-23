// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1a17f0 TES::UpdateTempNodes
// Adapted bodies: none
#include "TES_1a17f0.h"

void TES::UpdateTempNodes()
{
    NiUpdateData data;
    data.time = g_updateTime;
    data.flags = 1;
    tempNodeManager->UpdateObjectUpwards(data);
}
