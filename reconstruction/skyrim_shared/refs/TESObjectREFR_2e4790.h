// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// TESObjectREFR: GUESS(low); the class is the placeholder owner; layout is a minimal stand-in
// TESForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the slot the body uses
// GetOnLocalMap: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) CRASHLOGGER_PDB(59818@2026.10.24)
// formFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// baseForm: GUESS(low); NG holds it as data.objectReference
#pragma once

#include <cstdint>
#include <cstddef>

class TESForm
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
    virtual bool GetOnLocalMap() const;
};

class TESObjectREFR
{
public:
    bool GetOnLocalMap() const;

    std::uint8_t pad00[0x10];
    std::uint32_t formFlags;  // 10
    std::uint8_t  pad14[0x2C];
    TESForm*      baseForm;   // 40
};
