// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TES, NiAVObject, NiUpdateData, UpdateTempNodes, g_updateTime: GUESS(low); stand-in view, layout only as far as the compared code reads it.
// tempNodeManager, UpdateObjectUpwards: CRASHLOGGER_PDB(59818@2026.10.24); the node is the PDB's BSTempNodeManager field and the callee is the PDB's NiAVObject::UpdateObjectUpwards.
#pragma once

#include <cstdint>
#include <cstddef>

struct NiUpdateData
{
    float time;
    std::uint32_t flags;
};

class NiAVObject
{
public:
    void UpdateObjectUpwards(NiUpdateData& a_data);
};

extern float g_updateTime;

class TES
{
public:
    std::uint8_t unk00[0x98];
    NiAVObject* tempNodeManager;  // 98
    void UpdateTempNodes();
};
