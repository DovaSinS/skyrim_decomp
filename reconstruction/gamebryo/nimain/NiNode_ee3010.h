// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiNode, NiAVObject, NiAlphaProperty, AttachProperty, children: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; names and slot only, offsets read from the listing
// unk08, unk120, childCount: GUESS(low)
// slot27 stands in for the NiAVObject virtual that applies one argument to a child (community slot 0x27, AttachProperty)
#pragma once

#include <cstdint>
#include <cstddef>

class NiAlphaProperty;

class NiAVObject
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
    virtual void AttachProperty(NiAlphaProperty* a_property);  // 27
};

class NiNode : public NiAVObject
{
public:
    void AttachProperty(NiAlphaProperty* a_property) override;

    unsigned char unk08[0x110];
    NiAVObject** children;
    std::uint16_t unk120;
    std::uint16_t childCount;
};
static_assert(offsetof(NiNode, children) == 0x118, "children offset");
static_assert(offsetof(NiNode, childCount) == 0x122, "child count offset");
