// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// NiSingleInterpController: GUESS(low); the class is the placeholder owner
// NiInterpController, NiInterpolator: STANDIN GUESS(low); the base class and the interpolator type are read from the listing
// ResetTimeExtrema: CRASHLOGGER_PDB(59818@2026.10.24)
// NiInterpController::ResetTimeExtrema: CRASHLOGGER_PDB(59818@2026.10.24)
// NiInterpolator::Slot50, lowTime, highTime: GUESS(low)
// flags: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); name only, the listing reads only the low byte at this offset
// interpolator: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); name only, offset read from the listing
#pragma once

#include <cstdint>
#include <cstddef>

class NiInterpolator
{
public:
    virtual void unk00();
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
    virtual void Slot50(float* a_low, float* a_high);
};

class NiInterpController
{
public:
    void ResetTimeExtrema();

    void* vptr;
};

class NiSingleInterpController : public NiInterpController
{
public:
    void ResetTimeExtrema();

    unsigned char unk08[8];
    std::uint16_t flags;
    unsigned char unk12[0xA];
    float lowTime;
    float highTime;
    unsigned char unk24[0x24];
    NiInterpolator* interpolator;
};
static_assert(offsetof(NiSingleInterpController, flags) == 0x10, "flags offset");
static_assert(offsetof(NiSingleInterpController, lowTime) == 0x1C, "low time offset");
static_assert(offsetof(NiSingleInterpController, interpolator) == 0x48, "interpolator offset");
