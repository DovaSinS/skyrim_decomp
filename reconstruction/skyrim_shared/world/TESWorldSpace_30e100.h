// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESWorldSpace, TESWorldSpace::worldMapOffsetData, WORLD_MAP_OFFSET_DATA, WORLD_MAP_OFFSET_DATA::mapScale, ::mapOffsetX, ::mapOffsetY, ::mapOffsetZ: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG puts the data at 0x1A4 as here
// TESWorldSpace::GetHideMapMarkers: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24); a name hint only, the body tests the world map offsets against their unset values
// TESWorldSpace::padding000: GUESS(low); padding for the members this function does not touch
#pragma once

#include <cstdint>

struct WORLD_MAP_OFFSET_DATA
{
    float mapScale;    // 00
    float mapOffsetX;  // 04
    float mapOffsetY;  // 08
    float mapOffsetZ;  // 0C
};

class TESWorldSpace
{
public:
    bool GetHideMapMarkers() const;

    std::uint8_t padding000[0x1A4];                // 000
    WORLD_MAP_OFFSET_DATA worldMapOffsetData;  // 1A4
};
static_assert(sizeof(TESWorldSpace) == 0x1B4, "TESWorldSpace size");
