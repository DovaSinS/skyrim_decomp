// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// NiPSysEmitterCtlr: GUESS(low); the class is the placeholder owner
// NiTimeController: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); members only
// NiSingleInterpController: STANDIN EXE_RTTI; only the base method the compared function calls
// NiInterpolator: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); unk slots only place GetActiveTimeRange (32) and GuaranteeTimeRange (33)
// GetActiveTimeRange, GuaranteeTimeRange: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NiInterpolator slots 32 and 33
// flags, loKeyTime, hiKeyTime: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NiTimeController members at 0x10, 0x1C, 0x20
// m_spControllerInterpolator: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); NiSingleInterpController member name, offset 0x48 observed
// unk00, unk12, unk24, unk50, visibilityInterpolator: GUESS(low); unrecovered or invented storage names
// GuaranteeTimeRange: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstdint>

class NiInterpolator
{
public:
    virtual ~NiInterpolator();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk0A();
    virtual void unk0B();
    virtual void unk0C();
    virtual void unk0D();
    virtual void unk0E();
    virtual void unk0F();
    virtual void unk10();
    virtual void unk11();
    virtual void unk12();
    virtual void unk13();
    virtual void unk14();
    virtual void unk15();
    virtual void unk16();
    virtual void unk17();
    virtual void unk18();
    virtual void unk19();
    virtual void unk1A();
    virtual void unk1B();
    virtual void unk1C();
    virtual void unk1D();
    virtual void unk1E();
    virtual void unk1F();
    virtual void unk20();
    virtual void unk21();
    virtual void unk22();
    virtual void unk23();
    virtual void unk24();
    virtual void unk25();
    virtual void unk26();
    virtual void unk27();
    virtual void unk28();
    virtual void unk29();
    virtual void unk2A();
    virtual void unk2B();
    virtual void unk2C();
    virtual void unk2D();
    virtual void unk2E();
    virtual void unk2F();
    virtual void unk30();
    virtual void unk31();
    virtual void GetActiveTimeRange(float& a_beginKeyTime, float& a_endKeyTime) const;
    virtual void GuaranteeTimeRange(float a_startTime, float a_endTime);
};

class NiTimeController
{
public:
    std::uint8_t unk00[0x10];
    std::uint16_t flags;
    std::uint8_t unk12[0x0A];
    float loKeyTime;
    float hiKeyTime;
    std::uint8_t unk24[0x24];
};

class NiSingleInterpController : public NiTimeController
{
public:
    void GuaranteeTimeRange(float a_startTime, float a_endTime);

    NiInterpolator* m_spControllerInterpolator;
};

class NiPSysEmitterCtlr : public NiSingleInterpController
{
public:
    void GuaranteeTimeRange(float a_startTime, float a_endTime);  // compared: 0xf9b680

    std::uint8_t unk50[0x10];
    NiInterpolator* visibilityInterpolator;
};
