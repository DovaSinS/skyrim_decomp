// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); constructor, destructor and the 0x10 byte header only
// NiPSysEmitterCtlrData::NiPSysEmitterCtlrData: CRASHLOGGER_PDB(59818@2026.10.24); tier C: the unit renames the placeholder class to this class
// NiPSysEmitterCtlrData: CRASHLOGGER_PDB(59818@2026.10.24); the class name, the members are unnamed
// unknown10 to unknown3C, pad14, pad25, pad2C, pad3D: GUESS(low); offsets read from the listing
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

class NiPSysEmitterCtlrData : public NiObject
{
public:
    NiPSysEmitterCtlrData();
    ~NiPSysEmitterCtlrData() override;

    std::uint32_t unknown10;  // 10
    std::uint32_t pad14;      // 14
    void* unknown18;          // 18
    std::uint32_t unknown20;  // 20
    std::uint8_t unknown24;   // 24
    std::uint8_t pad25[3];    // 25
    std::uint32_t unknown28;  // 28
    std::uint32_t pad2C;      // 2C
    void* unknown30;          // 30
    std::uint32_t unknown38;  // 38
    std::uint8_t unknown3C;   // 3C
    std::uint8_t pad3D[3];    // 3D
};
