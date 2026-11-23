// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// NiUnionBV: GUESS(low); the class is the placeholder owner
// NiUnionBV::Func5_140CA6BC0: CRASHLOGGER_PDB(59818@2026.10.24); the compared function's placeholder name
// NiUnionBV::ForEachBoundingVolume, NiBoundingVolume, NiBoundingVolume::Slot05, unk00, volumes, unk18, volumeCount: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class NiBoundingVolume
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void Slot05(NiBoundingVolume* a_other, void* a_extra);
};

class NiUnionBV
{
public:
    void ForEachBoundingVolume(NiUnionBV* a_other, void* a_extra);

    unsigned char unk00[0x10];
    NiBoundingVolume** volumes;
    std::uint16_t unk18;
    std::uint16_t volumeCount;
};
static_assert(offsetof(NiUnionBV, volumeCount) == 0x1A, "count offset");
