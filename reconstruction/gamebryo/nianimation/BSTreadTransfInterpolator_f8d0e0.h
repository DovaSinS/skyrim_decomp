// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSTreadTransfInterpolator: GUESS(low); the class is the placeholder owner
// GetChannelPosed: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb); a virtual in the image, declared non-virtual here because only this body is compared
// spLerpData: SYMBOLS(fo4-pdb); member at 0x30
// pad08, unk01 to unk39, Unk3A: GUESS(low); unrecovered storage, slot placeholders and the unnamed virtual called at slot 0x3A
#pragma once

#include <cstdint>

class NiFloatData;

class BSTreadTransfInterpolator
{
public:
    virtual ~BSTreadTransfInterpolator();
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
    virtual void unk38();
    virtual void unk39();
    virtual void Unk3A() const;

    bool GetChannelPosed(std::uint16_t a_channel) const;  // compared: 0xf8d0e0

    std::uint8_t pad08[0x28];
    NiFloatData* spLerpData;
};
