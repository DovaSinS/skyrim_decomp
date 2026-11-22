// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BSTreadTransfInterpolator: GUESS(low); the class is the placeholder owner
// RegisterStreamables: CRASHLOGGER_PDB(59818@2026.10.24); a virtual (slot 0x1A) in the image, declared non-virtual here because only this body is compared
// NiInterpolator, NiStream, BSFixedString, NiFloatData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); members and slots only as far as the compared function needs
// RegisterStreamables, RegisterFixedString: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NiStream slot 8
// Links, uiNumLinks, spLerpData: SYMBOLS(fo4-pdb); members at 0x18, 0x20 and 0x30
// LinkInfo: GUESS(low); the 0x48-byte link record, only its fixed string at 0x40 is used
// unk00, unk01 to unk07, unk01 to unk19, pad00, pad28, pad30, fixedString: GUESS(low); unrecovered storage and slot placeholders
#pragma once

#include <cstdint>

struct BSFixedString
{
    const char* data;
};

class NiStream
{
public:
    virtual ~NiStream();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual bool RegisterFixedString(const BSFixedString& a_fixedString);
};

class NiFloatData
{
public:
    virtual ~NiFloatData();
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
    virtual bool RegisterStreamables(NiStream& a_stream);
};

class NiInterpolator
{
public:
    bool RegisterStreamables(NiStream& a_stream);

    std::uint8_t pad00[0x18];
};

struct LinkInfo
{
    std::uint8_t pad00[0x40];
    BSFixedString fixedString;
};

class BSTreadTransfInterpolator : public NiInterpolator
{
public:
    bool RegisterStreamables(NiStream& a_stream);  // compared: 0xf8c9d0

    LinkInfo* Links;
    std::uint32_t uiNumLinks;
    std::uint8_t pad28[0x8];
    NiFloatData* spLerpData;
};
