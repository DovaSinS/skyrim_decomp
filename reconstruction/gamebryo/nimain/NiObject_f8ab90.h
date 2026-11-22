// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); constructor, destructor and the 0x10 byte header only
// BSAnimNotes::BSAnimNotes: CRASHLOGGER_PDB(59818@2026.10.24); tier C: the unit renames the placeholder class to this class
// BSAnimNotes: CRASHLOGGER_PDB(59818@2026.10.24); the class name, the members are unnamed
// unknown10 to unknown1A: GUESS(low); offsets read from the listing
#pragma once

#include <cstdint>

class NiObject
{
public:
    NiObject();
    virtual ~NiObject();

    std::uint32_t refCount;  // 08
    std::uint32_t pad0C;     // 0C
};

class BSAnimNotes : public NiObject
{
public:
    BSAnimNotes();
    ~BSAnimNotes() override;

    void* unknown10;          // 10
    std::uint16_t unknown18;  // 18
    std::uint8_t unknown1A[6];  // 1A
};
