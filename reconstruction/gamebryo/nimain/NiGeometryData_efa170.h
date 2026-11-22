// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// NiGeometryData, RegisterStreamables: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) SYMBOLS(fo4-pdb)
// NiObject, NiStream, NiAdditionalGeometryData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the slots up to RegisterStreamables
// additionalGeomData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk01 to unk19, refCountPad, geometryPad: GUESS(low); virtual slots and padding the function does not use
#pragma once

#include <cstdint>
#include <cstddef>

class NiStream;

class NiObject
{
public:
    virtual ~NiObject();
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

    unsigned char refCountPad[8];
};

class NiAdditionalGeometryData : public NiObject
{
};

class NiGeometryData : public NiObject
{
public:
    bool RegisterStreamables(NiStream& a_stream) override;

    unsigned char geometryPad[0x48];
    NiAdditionalGeometryData* additionalGeomData;
};
static_assert(offsetof(NiGeometryData, additionalGeomData) == 0x58, "additionalGeomData offset");
