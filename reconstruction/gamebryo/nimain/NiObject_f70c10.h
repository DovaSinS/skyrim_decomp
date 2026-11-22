// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); constructor, destructor and the 0x10 byte header only
// NiTransformData::NiTransformData: CRASHLOGGER_PDB(59818@2026.10.24); tier C: the unit renames the placeholder class to this class
// NiTransformData: CRASHLOGGER_PDB(59818@2026.10.24); the class name, the members are unnamed
// unknown10 to unknown38: GUESS(low); offsets read from the listing, no community names for the SE layout
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

class NiTransformData : public NiObject
{
public:
    NiTransformData();
    ~NiTransformData() override;

    std::uint32_t unknown10;  // 10
    std::uint16_t unknown14;  // 14
    std::uint8_t unknown16[2];  // 16
    void* unknown18;          // 18
    std::uint32_t unknown20;  // 20
    std::uint16_t unknown24;  // 24
    std::uint8_t unknown26;   // 26
    std::uint8_t unknown27;   // 27
    void* unknown28;          // 28
    void* unknown30;          // 30
    void* unknown38;          // 38
};
