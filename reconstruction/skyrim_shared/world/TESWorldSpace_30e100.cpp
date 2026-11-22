// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x30e100 TESWorldSpace::GetHideMapMarkers
// Adapted bodies: none
#include "TESWorldSpace_30e100.h"

bool TESWorldSpace::GetHideMapMarkers() const
{
    return worldMapOffsetData.mapOffsetX == 0.0f && worldMapOffsetData.mapOffsetY == 0.0f &&
           worldMapOffsetData.mapOffsetZ == 0.0f && worldMapOffsetData.mapScale == -1.0f;
}
