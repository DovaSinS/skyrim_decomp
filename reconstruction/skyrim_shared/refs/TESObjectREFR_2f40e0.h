// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TESObjectREFR, DistanceSquaredTo, NiPoint3Stand: GUESS(low); stand-in view, layout only as far as the compared code reads it.
// TESObjectREFR::DistanceSquaredTo: CRASHLOGGER_PDB(59818@2026.10.24); size only, no name known.
#pragma once

#include <cstdint>
#include <cstddef>

struct NiPoint3Stand
{
    float x;
    float y;
    float z;
};

class TESObjectREFR
{
public:
    std::uint8_t unk00[0x54];
    NiPoint3Stand position;  // 54
    float DistanceSquaredTo(const NiPoint3Stand* a_point) const;
};
