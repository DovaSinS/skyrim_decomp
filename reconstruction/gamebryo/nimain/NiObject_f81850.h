// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); layout only, base ctor is the matched out-of-line one
// NiMorphData: CRASHLOGGER_PDB(59818@2026.10.24)
// NiMorphData::m_uiNumTargets, NiMorphData::m_uiNumVertsPerTarget, NiMorphData::m_aMorphTargets, NiMorphData::m_bRelativeTargets: SYMBOLS(fo4-pdb)
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

class NiMorphData : public NiObject
{
public:
    NiMorphData();
    ~NiMorphData() override;

    std::uint32_t m_uiNumTargets;
    std::uint32_t m_uiNumVertsPerTarget;
    void* m_aMorphTargets;
    bool m_bRelativeTargets;
};
