// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); layout only, base ctor is the matched out-of-line one
// NiBSplineData: CRASHLOGGER_PDB(59818@2026.10.24)
// NiBSplineData::m_pafControlPoints, NiBSplineData::m_pasCompactControlPoints, NiBSplineData::m_uiControlPointCount, NiBSplineData::m_uiCompactControlPointCount: SYMBOLS(fo4-pdb)
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

class NiBSplineData : public NiObject
{
public:
    NiBSplineData();
    ~NiBSplineData() override;

    float* m_pafControlPoints;
    std::int16_t* m_pasCompactControlPoints;
    std::uint32_t m_uiControlPointCount;
    std::uint32_t m_uiCompactControlPointCount;
};
