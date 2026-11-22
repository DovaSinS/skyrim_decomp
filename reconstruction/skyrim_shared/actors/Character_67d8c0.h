// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character: GUESS(low); the class is the placeholder owner
// ShouldSaveAnimationData: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb); the PDB class is Actor, this unit keeps the placeholder class
// SaveLoadView, gBGSSaveLoadGame, unk340, unk7A, unk7B: GUESS(low); the pointer is the one NG reads for the save-load manager, data at 0x3223e18; the manager view holds one flag word
#pragma once

#include <cstdint>
#include <cstddef>

// IsFlagBitSet: GUESS(low); a flag-word bit test by bit index, taking the word by value.
inline bool IsFlagBitSet(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

class SaveLoadView
{
public:
    std::uint8_t unk00[0x340];
    std::uint32_t unk340;
};

extern SaveLoadView* gBGSSaveLoadGame;

class Character
{
public:
    // vtable slots below 0x7A are unused placeholders
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
    virtual void unk38();
    virtual void unk39();
    virtual void unk3A();
    virtual void unk3B();
    virtual void unk3C();
    virtual void unk3D();
    virtual void unk3E();
    virtual void unk3F();
    virtual void unk40();
    virtual void unk41();
    virtual void unk42();
    virtual void unk43();
    virtual void unk44();
    virtual void unk45();
    virtual void unk46();
    virtual void unk47();
    virtual void unk48();
    virtual void unk49();
    virtual void unk4A();
    virtual void unk4B();
    virtual void unk4C();
    virtual void unk4D();
    virtual void unk4E();
    virtual void unk4F();
    virtual void unk50();
    virtual void unk51();
    virtual void unk52();
    virtual void unk53();
    virtual void unk54();
    virtual void unk55();
    virtual void unk56();
    virtual void unk57();
    virtual void unk58();
    virtual void unk59();
    virtual void unk5A();
    virtual void unk5B();
    virtual void unk5C();
    virtual void unk5D();
    virtual void unk5E();
    virtual void unk5F();
    virtual void unk60();
    virtual void unk61();
    virtual void unk62();
    virtual void unk63();
    virtual void unk64();
    virtual void unk65();
    virtual void unk66();
    virtual void unk67();
    virtual void unk68();
    virtual void unk69();
    virtual void unk6A();
    virtual void unk6B();
    virtual void unk6C();
    virtual void unk6D();
    virtual void unk6E();
    virtual void unk6F();
    virtual void unk70();
    virtual void unk71();
    virtual void unk72();
    virtual void unk73();
    virtual void unk74();
    virtual void unk75();
    virtual void unk76();
    virtual void unk77();
    virtual void unk78();
    virtual void unk79();
    virtual bool unk7A();
    virtual bool unk7B();

    bool ShouldSaveAnimationData();  // compared: 0x67d8c0
};
