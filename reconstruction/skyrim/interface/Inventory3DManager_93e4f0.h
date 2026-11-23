// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_008e0000_o2.cpp:22380 (NiPoint3::operator=, member-wise copy)
// Inventory3DManager, Inventory3DManager::SetModelTransform: GUESS(low)
// storedPosition, storedScale: GUESS(low)
// NiPoint3, ModelPosition, ModelScale: SYMBOLS(fo4-pdb); offsets observed in this build
#pragma once

#include <cstdint>
#include <cstddef>

struct NiPoint3
{
    float x, y, z;
    NiPoint3& operator=(const NiPoint3& o)
    {
        x = o.x;
        y = o.y;
        z = o.z;
        return *this;
    }
};

class Inventory3DManager
{
public:
    void SetModelTransform(const NiPoint3* pos, float scale);

    std::uint8_t unk00[0x14];
    NiPoint3 storedPosition;
    NiPoint3 ModelPosition;
    float storedScale;
    float ModelScale;
};
