// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// BSShaderAccumulator, FinishAccumulatingPreResolveDepth, FinishAccumulatingPostResolveDepth: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); virtual slots 0x2A and 0x2B
// BSShaderAccumulator::FinishAccumulating: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) OBSERVED; the community one is a no-argument slot 0x26 method, the compared function takes a flags word and is not that slot
// unk00 to unk29: GUESS(low); placeholders that put the two used virtuals at their slots
#pragma once

#include <cstdint>

class BSShaderAccumulator
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
    virtual void FinishAccumulatingPreResolveDepth(std::uint32_t flags);   // 2A
    virtual void FinishAccumulatingPostResolveDepth(std::uint32_t flags);  // 2B

    void FinishAccumulating(std::uint32_t flags);  // compared: 0x151e3f0
};
