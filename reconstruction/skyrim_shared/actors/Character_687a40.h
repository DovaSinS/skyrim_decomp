// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Character: STANDIN GUESS(low); a view of the members used, from offsets
// Character::Function687a40: CRASHLOGGER_PDB(59818@2026.10.24)
// Character::unk4c8: GUESS(low); virtual slot 153, a bool query taking a bool
// ActorProcess: STANDIN CRASHLOGGER_PDB(59818@2026.10.24); only the type name
// ActorProcess::Function6f6470: CRASHLOGGER_PDB(59818@2026.10.24); returns an int, compared with 9
// Character::currentProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); at 0xf8
// TargetRace: GUESS(low); stand-in record read through the pointer member at 0x1f8
// unkC8 unk108 unk1f8: GUESS(low); a state word at 0xc8, a flag word at 0x108 of the record and a pointer member at 0x1f8
// GetBit: GUESS(low); the same by-value bit read returning the bit as a byte
// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422
#pragma once

#include <cstdint>
#include <cstddef>

inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

inline std::uint8_t GetBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return static_cast<std::uint8_t>((a_flags >> a_bit) & 1);
}

struct TargetRace
{
    std::uint8_t pad00[0x108];
    std::uint32_t unk108;
};

class ActorProcess
{
public:
    int Function6f6470();
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
    virtual void vslot112();
    virtual void vslot113();
    virtual void vslot114();
    virtual void vslot115();
    virtual void vslot116();
    virtual void vslot117();
    virtual void vslot118();
    virtual void vslot119();
    virtual void vslot120();
    virtual void vslot121();
    virtual void vslot122();
    virtual void vslot123();
    virtual void vslot124();
    virtual void vslot125();
    virtual void vslot126();
    virtual void vslot127();
    virtual void vslot128();
    virtual void vslot129();
    virtual void vslot130();
    virtual void vslot131();
    virtual void vslot132();
    virtual void vslot133();
    virtual void vslot134();
    virtual void vslot135();
    virtual void vslot136();
    virtual void vslot137();
    virtual void vslot138();
    virtual void vslot139();
    virtual void vslot140();
    virtual void vslot141();
    virtual void vslot142();
    virtual void vslot143();
    virtual void vslot144();
    virtual void vslot145();
    virtual void vslot146();
    virtual void vslot147();
    virtual void vslot148();
    virtual void vslot149();
    virtual void vslot150();
    virtual void vslot151();
    virtual void vslot152();
    virtual bool unk4c8(bool a_arg);

    bool Function687a40();  // compared: 0x687a40

    std::uint8_t pad08[0xc0];
    std::uint32_t unkC8;
    std::uint8_t padCC[0xf8 - 0xcc];
    ActorProcess* currentProcess;
    std::uint8_t pad100[0x1f8 - 0x100];
    TargetRace* unk1f8;
};
