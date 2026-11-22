// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BGSProcedureFind: GUESS(low); the class is the placeholder owner; layout is a minimal stand-in
// InitActorAnimPose: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
// BGSProcessContext: SYMBOLS(fo4-pdb); a stand-in holding only the two pointers the body reads
// actorData, processData, unk20Flag, unk14Flag: GUESS(low)
// unk09, unk0C: GUESS(low); virtual slots 9 and 12 of the procedure
#pragma once

#include <cstdint>
#include <cstddef>

struct BGSProcessActorData
{
    std::uint8_t pad00[0x20];
    std::uint8_t unk20Flag;  // 20
};

struct BGSProcessData
{
    std::uint8_t pad00[0x14];
    std::uint8_t unk14Flag;  // 14
};

struct BGSProcessContext
{
    BGSProcessActorData* actorData;    // 00
    BGSProcessData*      processData;  // 08
};

class BGSProcedureFind
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
    virtual void unk0C(BGSProcessContext& a_context);

    void InitActorAnimPose(BGSProcessContext& a_context);
};
