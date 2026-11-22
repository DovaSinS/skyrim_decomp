// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BSOcclusionBox: GUESS(low); the placeholder class kept for the unit, the function is BSMultiBoundAABB::BSMultiBoundAABB in the other sources
// BSMultiBoundAABB::BSMultiBoundAABB: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
// BSMultiBoundShape: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); only its constructor and size
// center, extents, pad18, pad28: GUESS(low); loosely follow NG's BSMultiBoundAABB, which this placeholder class stands for
// NiPoint3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// shapePad: GUESS(low); padding of the base stand-in
#pragma once

#include <cstdint>
#include <cstddef>

struct NiPoint3
{
    float x;
    float y;
    float z;
};

class BSMultiBoundShape
{
public:
    BSMultiBoundShape();
    virtual ~BSMultiBoundShape();

    unsigned char shapePad[0x10];
};

class BSOcclusionBox : public BSMultiBoundShape
{
public:
    BSOcclusionBox(const NiPoint3& a_center, const NiPoint3& a_extents);
    ~BSOcclusionBox() override;

    std::uint32_t pad18;
    NiPoint3 center;
    std::uint32_t pad28;
    NiPoint3 extents;
};
static_assert(offsetof(BSOcclusionBox, extents) == 0x2C, "extents offset");
