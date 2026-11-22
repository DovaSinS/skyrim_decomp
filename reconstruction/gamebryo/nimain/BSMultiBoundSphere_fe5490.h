// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BSMultiBoundSphere, BSMultiBoundShape: CRASHLOGGER_PDB(59818@2026.10.24); BSMultiBoundShape is a stand-in holding only its constructor and size
// center, radius: SYMBOLS(fo4-pdb); offsets read from the listing
// NiPoint3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
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

    unsigned char unk08[0x10];
};

class BSMultiBoundSphere : public BSMultiBoundShape
{
public:
    BSMultiBoundSphere();
    ~BSMultiBoundSphere() override;

    NiPoint3 center;
    float radius;
};
static_assert(sizeof(BSMultiBoundSphere) == 0x28, "BSMultiBoundSphere size");
