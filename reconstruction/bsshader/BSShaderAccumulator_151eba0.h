// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BSShaderAccumulator: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) OBSERVED; layout view only, batchRenderer is its 0x130 member
// BSShaderAccumulator::FinishAccumulatingAppendWaterFogPasses: CRASHLOGGER_PDB(59818@2026.10.24)
// BSBatchRenderer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the virtual slot used here
// PassListOwner, PassNode, GetWaterFogPasses, AppendPass, unknown00, unknown129, passCount, next: GUESS(low); views of what the body touches
// unk00 to unk37: GUESS(low); placeholders that put the used virtuals at their slots
#pragma once

#include <cstdint>

struct PassNode
{
    std::uint8_t unknown00[0x18];  // 00
    std::uint32_t passCount;       // 18
    std::uint8_t unknown1C[0xC];   // 1C
    PassNode* next;                // 28
};

class BSBatchRenderer
{
public:
    virtual void unk00();  // 00
    virtual void AppendPass(PassNode* a_node, std::uint32_t a_count);  // 01
};

class PassListOwner
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
    virtual void unk32();
    virtual void unk33();
    virtual void unk34();
    virtual void unk35();
    virtual void unk36();
    virtual void unk37();
    virtual PassNode** GetWaterFogPasses();  // 38
};

class BSShaderAccumulator
{
public:
    bool FinishAccumulatingAppendWaterFogPasses(void* a_unused, PassListOwner* a_owner);  // compared: 0x151eba0

    std::uint8_t unknown00[0x129];        // 00
    bool unknown129;                      // 129
    std::uint8_t unknown12A[6];           // 12A
    BSBatchRenderer* batchRenderer;       // 130
};
