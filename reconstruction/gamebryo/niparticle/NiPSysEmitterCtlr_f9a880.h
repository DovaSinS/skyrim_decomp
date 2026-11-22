// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysEmitterCtlr, NiPSysModifierCtlr, NiInterpolator, NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the virtual slot, the 0x60 member and sizes the body needs
// NiObject::RegisterStreamables: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); virtual slot 0x1A
// NiPSysEmitterCtlr::RegisterStreamables: SYMBOLS(fo4-pdb); the FO4 prototype takes the stream by reference, the base implementation is reached by a qualified call
// visibilityInterpolator, Unk_01 to Unk_19, unknown08, unknown10: GUESS(low); placeholders that put RegisterStreamables at its slot and fill the layout
#pragma once

#include <cstdint>

class NiStream;

class NiObject
{
public:
    virtual ~NiObject();  // 00
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual bool RegisterStreamables(NiStream& a_stream);  // 1A

    std::uint8_t unknown08[8];  // 08
};

class NiInterpolator : public NiObject
{
public:
};

class NiPSysModifierCtlr : public NiObject
{
public:
    bool RegisterStreamables(NiStream& a_stream) override;  // 1A

    std::uint8_t unknown10[0x50];  // 10
};

class NiPSysEmitterCtlr : public NiPSysModifierCtlr
{
public:
    bool RegisterStreamables(NiStream& a_stream) override;  // 1A, compared: 0xf9a880

    NiInterpolator* visibilityInterpolator;  // 60
};
