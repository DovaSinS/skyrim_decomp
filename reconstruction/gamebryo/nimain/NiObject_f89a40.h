// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); layout only, base ctor is the matched out-of-line one
// NiUVData: CRASHLOGGER_PDB(59818@2026.10.24)
// NiUVData::m_uiNumUOffsetKeys: SYMBOLS(fo4-pdb)
// NiUVData::field14, NiUVData::field18, NiUVData::field20, NiUVData::field28, NiUVData::field30, NiUVData::field38, NiUVData::field40, NiUVData::field48, NiUVData::field50, NiUVData::field58, NiUVData::field5c, NiUVData::field60, NiUVData::field64, NiUVData::field65, NiUVData::field66, NiUVData::field67: GUESS(low)
#pragma once

#include <cstdint>

class NiObject
{
public:
    NiObject();
    virtual ~NiObject();

private:
    std::uint32_t refCount;
    std::uint32_t pad0c;
};

class NiUVData : public NiObject
{
public:
    NiUVData();
    ~NiUVData() override;

    std::uint32_t m_uiNumUOffsetKeys;
    std::uint32_t field14;
    void* field18;
    void* field20;
    void* field28;
    void* field30;
    void* field38;
    void* field40;
    void* field48;
    void* field50;
    float field58;
    float field5c;
    float field60;
    std::uint8_t field64;
    std::uint8_t field65;
    std::uint8_t field66;
    std::uint8_t field67;
};
