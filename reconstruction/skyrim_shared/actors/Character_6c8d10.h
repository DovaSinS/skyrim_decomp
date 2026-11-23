// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_004e0000_o2.cpp:49422 (TestBit, a one-line bit test; shape taken from the matching cookbook)
// Character, Character::Function6c8d10, Character::unk211, ProcessData, ProcessData::unk50, Inner, Inner::flags28, Inner::flags2C: GUESS(low)
#pragma once

#include <cstdint>

// TestBitClear: GUESS(low); the complement of TestBit, true when the bit is not set.
inline bool TestBitClear(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((~(a_flags >> a_bit)) & 1) != 0;
}

// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value.
inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

class Inner
{
public:
    char pad000[0x28];
    std::uint32_t flags28;  // 0x28
    std::uint32_t flags2C;  // 0x2C
};

class ProcessData
{
public:
    char pad000[0x50];
    Inner* unk50;  // 0x50
};

class Character
{
public:
    virtual void unk000();
    virtual void unk001();
    virtual void unk002();
    virtual void unk003();
    virtual void unk004();
    virtual void unk005();
    virtual void unk006();
    virtual void unk007();
    virtual void unk008();
    virtual void unk009();
    virtual void unk010();
    virtual void unk011();
    virtual void unk012();
    virtual void unk013();
    virtual void unk014();
    virtual void unk015();
    virtual void unk016();
    virtual void unk017();
    virtual void unk018();
    virtual void unk019();
    virtual void unk020();
    virtual void unk021();
    virtual void unk022();
    virtual void unk023();
    virtual void unk024();
    virtual void unk025();
    virtual void unk026();
    virtual void unk027();
    virtual void unk028();
    virtual void unk029();
    virtual void unk030();
    virtual void unk031();
    virtual void unk032();
    virtual void unk033();
    virtual void unk034();
    virtual void unk035();
    virtual void unk036();
    virtual void unk037();
    virtual void unk038();
    virtual void unk039();
    virtual void unk040();
    virtual void unk041();
    virtual void unk042();
    virtual void unk043();
    virtual void unk044();
    virtual void unk045();
    virtual void unk046();
    virtual void unk047();
    virtual void unk048();
    virtual void unk049();
    virtual void unk050();
    virtual void unk051();
    virtual void unk052();
    virtual void unk053();
    virtual void unk054();
    virtual void unk055();
    virtual void unk056();
    virtual void unk057();
    virtual void unk058();
    virtual void unk059();
    virtual void unk060();
    virtual void unk061();
    virtual void unk062();
    virtual void unk063();
    virtual void unk064();
    virtual void unk065();
    virtual void unk066();
    virtual void unk067();
    virtual void unk068();
    virtual void unk069();
    virtual void unk070();
    virtual void unk071();
    virtual void unk072();
    virtual void unk073();
    virtual void unk074();
    virtual void unk075();
    virtual void unk076();
    virtual void unk077();
    virtual void unk078();
    virtual void unk079();
    virtual void unk080();
    virtual void unk081();
    virtual void unk082();
    virtual void unk083();
    virtual void unk084();
    virtual void unk085();
    virtual void unk086();
    virtual void unk087();
    virtual void unk088();
    virtual void unk089();
    virtual void unk090();
    virtual void unk091();
    virtual void unk092();
    virtual void unk093();
    virtual void unk094();
    virtual void unk095();
    virtual void unk096();
    virtual void unk097();
    virtual void unk098();
    virtual void unk099();
    virtual void unk100();
    virtual void unk101();
    virtual void unk102();
    virtual void unk103();
    virtual void unk104();
    virtual void unk105();
    virtual void unk106();
    virtual void unk107();
    virtual void unk108();
    virtual void unk109();
    virtual void unk110();
    virtual void unk111();
    virtual void unk112();
    virtual void unk113();
    virtual void unk114();
    virtual void unk115();
    virtual void unk116();
    virtual void unk117();
    virtual void unk118();
    virtual void unk119();
    virtual void unk120();
    virtual void unk121();
    virtual void unk122();
    virtual void unk123();
    virtual void unk124();
    virtual void unk125();
    virtual void unk126();
    virtual void unk127();
    virtual void unk128();
    virtual void unk129();
    virtual void unk130();
    virtual void unk131();
    virtual void unk132();
    virtual void unk133();
    virtual void unk134();
    virtual void unk135();
    virtual void unk136();
    virtual void unk137();
    virtual void unk138();
    virtual void unk139();
    virtual void unk140();
    virtual void unk141();
    virtual void unk142();
    virtual void unk143();
    virtual void unk144();
    virtual void unk145();
    virtual void unk146();
    virtual void unk147();
    virtual void unk148();
    virtual void unk149();
    virtual void unk150();
    virtual void unk151();
    virtual void unk152();
    virtual void unk153();
    virtual void unk154();
    virtual void unk155();
    virtual void unk156();
    virtual void unk157();
    virtual void unk158();
    virtual void unk159();
    virtual void unk160();
    virtual void unk161();
    virtual void unk162();
    virtual void unk163();
    virtual void unk164();
    virtual void unk165();
    virtual void unk166();
    virtual void unk167();
    virtual void unk168();
    virtual void unk169();
    virtual void unk170();
    virtual void unk171();
    virtual void unk172();
    virtual void unk173();
    virtual void unk174();
    virtual void unk175();
    virtual void unk176();
    virtual void unk177();
    virtual void unk178();
    virtual void unk179();
    virtual void unk180();
    virtual void unk181();
    virtual void unk182();
    virtual void unk183();
    virtual void unk184();
    virtual void unk185();
    virtual void unk186();
    virtual void unk187();
    virtual void unk188();
    virtual void unk189();
    virtual void unk190();
    virtual void unk191();
    virtual void unk192();
    virtual void unk193();
    virtual void unk194();
    virtual void unk195();
    virtual void unk196();
    virtual void unk197();
    virtual void unk198();
    virtual void unk199();
    virtual void unk200();
    virtual void unk201();
    virtual void unk202();
    virtual void unk203();
    virtual void unk204();
    virtual void unk205();
    virtual void unk206();
    virtual void unk207();
    virtual void unk208();
    virtual void unk209();
    virtual void unk210();
    virtual bool unk211();  // slot 211
    bool Function6c8d10();  // compared: 0x6c8d10

    char pad008[0xF0];
    ProcessData* process;  // 0xF8
};
