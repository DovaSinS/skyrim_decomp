// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Character: STANDIN GUESS(low); a view of the members used, from offsets
// Character::Function6afef0: CRASHLOGGER_PDB(59818@2026.10.24)
// SaveLoadView gBGSSaveLoadGame unk340: GUESS(low); the pointer is the one NG reads for the save-load manager, data at 0x3223e18; the manager view holds one flag word
// gFlag3244aa4 gConstant219e5f0: GUESS(low); an int global at RVA 0x3244aa4 and a float constant global at RVA 0x219e5f0
// unkE8 unk380 unk160 ParamBlock ProcessOwner: GUESS(low); a flag word at 0xe8, virtual slot 112 returning an owner whose slot 44 takes a parameter block and a flag
// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
#pragma once

#include <cstdint>
#include <cstddef>

inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
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
extern std::int32_t gFlag3244aa4;
extern const float gConstant219e5f0;

struct ParamBlock
{
    float unk00;
    std::uint32_t unk04;
};

class ProcessOwner
{
public:
    virtual void vslot0();
    virtual void vslot1();
    virtual void vslot2();
    virtual void vslot3();
    virtual void vslot4();
    virtual void vslot5();
    virtual void vslot6();
    virtual void vslot7();
    virtual void vslot8();
    virtual void vslot9();
    virtual void vslot10();
    virtual void vslot11();
    virtual void vslot12();
    virtual void vslot13();
    virtual void vslot14();
    virtual void vslot15();
    virtual void vslot16();
    virtual void vslot17();
    virtual void vslot18();
    virtual void vslot19();
    virtual void vslot20();
    virtual void vslot21();
    virtual void vslot22();
    virtual void vslot23();
    virtual void vslot24();
    virtual void vslot25();
    virtual void vslot26();
    virtual void vslot27();
    virtual void vslot28();
    virtual void vslot29();
    virtual void vslot30();
    virtual void vslot31();
    virtual void vslot32();
    virtual void vslot33();
    virtual void vslot34();
    virtual void vslot35();
    virtual void vslot36();
    virtual void vslot37();
    virtual void vslot38();
    virtual void vslot39();
    virtual void vslot40();
    virtual void vslot41();
    virtual void vslot42();
    virtual void vslot43();
    virtual void vslot44(ParamBlock* a_block, std::uint32_t a_flag);
};

class Character
{
public:
    virtual void vslot0();
    virtual void vslot1();
    virtual void vslot2();
    virtual void vslot3();
    virtual void vslot4();
    virtual void vslot5();
    virtual void vslot6();
    virtual void vslot7();
    virtual void vslot8();
    virtual void vslot9();
    virtual void vslot10();
    virtual void vslot11();
    virtual void vslot12();
    virtual void vslot13();
    virtual void vslot14();
    virtual void vslot15();
    virtual void vslot16();
    virtual void vslot17();
    virtual void vslot18();
    virtual void vslot19();
    virtual void vslot20();
    virtual void vslot21();
    virtual void vslot22();
    virtual void vslot23();
    virtual void vslot24();
    virtual void vslot25();
    virtual void vslot26();
    virtual void vslot27();
    virtual void vslot28();
    virtual void vslot29();
    virtual void vslot30();
    virtual void vslot31();
    virtual void vslot32();
    virtual void vslot33();
    virtual void vslot34();
    virtual void vslot35();
    virtual void vslot36();
    virtual void vslot37();
    virtual void vslot38();
    virtual void vslot39();
    virtual void vslot40();
    virtual void vslot41();
    virtual void vslot42();
    virtual void vslot43();
    virtual void vslot44();
    virtual void vslot45();
    virtual void vslot46();
    virtual void vslot47();
    virtual void vslot48();
    virtual void vslot49();
    virtual void vslot50();
    virtual void vslot51();
    virtual void vslot52();
    virtual void vslot53();
    virtual void vslot54();
    virtual void vslot55();
    virtual void vslot56();
    virtual void vslot57();
    virtual void vslot58();
    virtual void vslot59();
    virtual void vslot60();
    virtual void vslot61();
    virtual void vslot62();
    virtual void vslot63();
    virtual void vslot64();
    virtual void vslot65();
    virtual void vslot66();
    virtual void vslot67();
    virtual void vslot68();
    virtual void vslot69();
    virtual void vslot70();
    virtual void vslot71();
    virtual void vslot72();
    virtual void vslot73();
    virtual void vslot74();
    virtual void vslot75();
    virtual void vslot76();
    virtual void vslot77();
    virtual void vslot78();
    virtual void vslot79();
    virtual void vslot80();
    virtual void vslot81();
    virtual void vslot82();
    virtual void vslot83();
    virtual void vslot84();
    virtual void vslot85();
    virtual void vslot86();
    virtual void vslot87();
    virtual void vslot88();
    virtual void vslot89();
    virtual void vslot90();
    virtual void vslot91();
    virtual void vslot92();
    virtual void vslot93();
    virtual void vslot94();
    virtual void vslot95();
    virtual void vslot96();
    virtual void vslot97();
    virtual void vslot98();
    virtual void vslot99();
    virtual void vslot100();
    virtual void vslot101();
    virtual void vslot102();
    virtual void vslot103();
    virtual void vslot104();
    virtual void vslot105();
    virtual void vslot106();
    virtual void vslot107();
    virtual void vslot108();
    virtual void vslot109();
    virtual void vslot110();
    virtual void vslot111();
    virtual ProcessOwner* unk380();

    void Function6afef0();  // compared: 0x6afef0

    std::uint8_t pad08[0xe0];
    std::uint32_t unkE8;
};
