// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TESObjectREFR, TESObjectREFR::Function2f05b0, TESObjectREFR::objectReference: GUESS(low)
// ExtraDataList::GetLeveledNPC, ExtraDataList::Function1696a0: CRASHLOGGER_PDB(59818@2026.10.24); prototypes read from the listing; the class is a stand-in at 0x70

#pragma once

#include <cstdint>
#include <cstddef>

class ExtraDataList
{
public:
    void* GetLeveledNPC();
    void* Function1696a0();
};

class TESObjectREFR
{
public:
    bool Function2f05b0(void* a_other);

    unsigned char pad00[0x40];
    void* objectReference;  // 40
    unsigned char pad48[0x28];
    ExtraDataList extraList;  // 70
};
