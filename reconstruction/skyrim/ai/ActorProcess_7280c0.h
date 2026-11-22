// Source exposure: community-headers (names, layout), binary-analysis (offsets from the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// ActorProcess: GUESS(low); the class is the placeholder owner
// HasPerk: CRASHLOGGER_PDB(59818@2026.10.24); the address suffix of the recorded name is dropped
// AIProcess::middleHigh, Actor, ForEachPerk, PerkEntryVisitor, Visit, BGSPerk: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); ForEachPerk is virtual slot 0xFA, Actor, PerkEntryVisitor and BGSPerk are stand-ins
// FindPerkVisitor, PerkRankData, rank, perk, found, unk000 to unk0F9: GUESS(low); the visitor, its result record and slot placeholders
#pragma once

#include <cstdint>
#include <cstddef>

struct BGSPerk;

struct PerkRankData
{
    std::uint8_t pad00[0x8];
    std::uint8_t rank;
};

class BGSPerkEntry;

class PerkEntryVisitor
{
public:
    virtual std::int32_t Visit(BGSPerkEntry* a_perkEntry) = 0;  // 00
};

class FindPerkVisitor : public PerkEntryVisitor
{
public:
    explicit FindPerkVisitor(BGSPerk* a_perk) :
        perk(a_perk), found(nullptr)
    {
    }

    std::int32_t Visit(BGSPerkEntry* a_perkEntry) override;  // defined in its own translation unit

    BGSPerk* perk;
    PerkRankData* found;
};

class Actor
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
    virtual void unk00A();
    virtual void unk00B();
    virtual void unk00C();
    virtual void unk00D();
    virtual void unk00E();
    virtual void unk00F();
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
    virtual void unk01A();
    virtual void unk01B();
    virtual void unk01C();
    virtual void unk01D();
    virtual void unk01E();
    virtual void unk01F();
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
    virtual void unk02A();
    virtual void unk02B();
    virtual void unk02C();
    virtual void unk02D();
    virtual void unk02E();
    virtual void unk02F();
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
    virtual void unk03A();
    virtual void unk03B();
    virtual void unk03C();
    virtual void unk03D();
    virtual void unk03E();
    virtual void unk03F();
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
    virtual void unk04A();
    virtual void unk04B();
    virtual void unk04C();
    virtual void unk04D();
    virtual void unk04E();
    virtual void unk04F();
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
    virtual void unk05A();
    virtual void unk05B();
    virtual void unk05C();
    virtual void unk05D();
    virtual void unk05E();
    virtual void unk05F();
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
    virtual void unk06A();
    virtual void unk06B();
    virtual void unk06C();
    virtual void unk06D();
    virtual void unk06E();
    virtual void unk06F();
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
    virtual void unk07A();
    virtual void unk07B();
    virtual void unk07C();
    virtual void unk07D();
    virtual void unk07E();
    virtual void unk07F();
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
    virtual void unk08A();
    virtual void unk08B();
    virtual void unk08C();
    virtual void unk08D();
    virtual void unk08E();
    virtual void unk08F();
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
    virtual void unk09A();
    virtual void unk09B();
    virtual void unk09C();
    virtual void unk09D();
    virtual void unk09E();
    virtual void unk09F();
    virtual void unk0A0();
    virtual void unk0A1();
    virtual void unk0A2();
    virtual void unk0A3();
    virtual void unk0A4();
    virtual void unk0A5();
    virtual void unk0A6();
    virtual void unk0A7();
    virtual void unk0A8();
    virtual void unk0A9();
    virtual void unk0AA();
    virtual void unk0AB();
    virtual void unk0AC();
    virtual void unk0AD();
    virtual void unk0AE();
    virtual void unk0AF();
    virtual void unk0B0();
    virtual void unk0B1();
    virtual void unk0B2();
    virtual void unk0B3();
    virtual void unk0B4();
    virtual void unk0B5();
    virtual void unk0B6();
    virtual void unk0B7();
    virtual void unk0B8();
    virtual void unk0B9();
    virtual void unk0BA();
    virtual void unk0BB();
    virtual void unk0BC();
    virtual void unk0BD();
    virtual void unk0BE();
    virtual void unk0BF();
    virtual void unk0C0();
    virtual void unk0C1();
    virtual void unk0C2();
    virtual void unk0C3();
    virtual void unk0C4();
    virtual void unk0C5();
    virtual void unk0C6();
    virtual void unk0C7();
    virtual void unk0C8();
    virtual void unk0C9();
    virtual void unk0CA();
    virtual void unk0CB();
    virtual void unk0CC();
    virtual void unk0CD();
    virtual void unk0CE();
    virtual void unk0CF();
    virtual void unk0D0();
    virtual void unk0D1();
    virtual void unk0D2();
    virtual void unk0D3();
    virtual void unk0D4();
    virtual void unk0D5();
    virtual void unk0D6();
    virtual void unk0D7();
    virtual void unk0D8();
    virtual void unk0D9();
    virtual void unk0DA();
    virtual void unk0DB();
    virtual void unk0DC();
    virtual void unk0DD();
    virtual void unk0DE();
    virtual void unk0DF();
    virtual void unk0E0();
    virtual void unk0E1();
    virtual void unk0E2();
    virtual void unk0E3();
    virtual void unk0E4();
    virtual void unk0E5();
    virtual void unk0E6();
    virtual void unk0E7();
    virtual void unk0E8();
    virtual void unk0E9();
    virtual void unk0EA();
    virtual void unk0EB();
    virtual void unk0EC();
    virtual void unk0ED();
    virtual void unk0EE();
    virtual void unk0EF();
    virtual void unk0F0();
    virtual void unk0F1();
    virtual void unk0F2();
    virtual void unk0F3();
    virtual void unk0F4();
    virtual void unk0F5();
    virtual void unk0F6();
    virtual void unk0F7();
    virtual void unk0F8();
    virtual void unk0F9();
    virtual void ForEachPerk(PerkEntryVisitor& a_visitor) const;  // 0xFA
};

class ActorProcess
{
public:
    std::uint8_t HasPerk(Actor* a_actor, BGSPerk* a_perk);  // compared: 0x7280c0

    std::uint8_t pad00[0x8];
    void* middleHigh;
};
