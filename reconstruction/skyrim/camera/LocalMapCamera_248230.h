// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// LocalMapCamera, maxExtent, minExtent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SetExtents: SYMBOLS(fo4-pdb)
// NiPoint3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPoint3::operator=: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_008e0000_o2.cpp:22380
// unk00: GUESS(low); the TESCamera base, not modelled
#pragma once

#include <cstdint>
#include <cstddef>

struct NiPoint3
{
    float x;
    float y;
    float z;

    NiPoint3& operator=(const NiPoint3& a_rhs)
    {
        x = a_rhs.x;
        y = a_rhs.y;
        z = a_rhs.z;
        return *this;
    }
};

// kLocalMapExtentZBias: GUESS(low); a constant read from the image data section
extern const float kLocalMapExtentZBias;

class LocalMapCamera
{
public:
    void SetExtents(const NiPoint3& a_max, const NiPoint3& a_min);

    unsigned char unk00[0x38];
    NiPoint3 maxExtent;
    NiPoint3 minExtent;
};
static_assert(offsetof(LocalMapCamera, minExtent) == 0x44, "minExtent offset");
