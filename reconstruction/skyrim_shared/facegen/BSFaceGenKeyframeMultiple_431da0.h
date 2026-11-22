// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BSFaceGenKeyframeMultiple: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSFaceGenKeyframe: STANDIN EXE_RTTI
// values, count, isUpdated: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// timer: CRASHLOGGER_PDB(59818@2026.10.24); BSFaceGenKeyframe member at 0x0C
// Unk_09, Unk_0E: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); Unk_09 compared here, Unk_0E is the per-index test it calls (slot 0x0E)
// Unk_01 to Unk_08, Unk_0A to Unk_0D: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); void placeholders that keep the vtable index of the call at 0x70
#pragma once

#include <cstdint>

class BSFaceGenKeyframe
{
public:
    virtual ~BSFaceGenKeyframe() = default;
    std::uint32_t type;  // 08
    float timer;         // 0C
};

class BSFaceGenKeyframeMultiple : public BSFaceGenKeyframe
{
public:
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual bool Unk_09();  // compared: 0x431da0
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual bool Unk_0E(std::uint32_t a_index);

    float*        values;     // 10
    std::uint32_t count;      // 18
    bool          isUpdated;  // 1C
};
