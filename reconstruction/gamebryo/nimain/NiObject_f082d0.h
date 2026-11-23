// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); layout only, base ctor is the matched out-of-line one
// NiSkinPartition: CRASHLOGGER_PDB(59818@2026.10.24)
// NiSkinPartition::m_uiPartitions, NiSkinPartition::m_pkPartitions: SYMBOLS(fo4-pdb)
// NiSkinPartition::unk14: GUESS(low)
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

class NiSkinPartition : public NiObject
{
public:
    NiSkinPartition();
    ~NiSkinPartition() override;

    std::uint32_t m_uiPartitions;
    std::uint32_t unk14;
    void* m_pkPartitions;
};
