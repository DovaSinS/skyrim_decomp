// Source exposure: community-headers (names), binary-analysis (offsets and slots from the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// Actor: GUESS(low); the class is the placeholder owner
// Func117: CRASHLOGGER_PDB(59818@2026.10.24)
// ActorProcess, GetCurrentlyEquippedWeapon: CRASHLOGGER_PDB(59818@2026.10.24); ActorProcess is a stand-in, the suffix of the recorded name is dropped
// IsDead, currentProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; IsDead is virtual slot 0x99, NG places currentProcess at 0xF0 while this build reads 0xF8
// WeaponLike, weaponType, kTypeTable, unk000 to unk098: GUESS(low); stand-in members, a lookup table read by weapon type and slot placeholders
// header-gap Actor: stand-in view with only the process pointer and the IsDead slot
#pragma once

#include <cstdint>
#include <cstddef>

struct WeaponLike
{
    std::uint8_t pad00[0x19D];
    std::int8_t weaponType;
};

class ActorProcess
{
public:
    WeaponLike** GetCurrentlyEquippedWeapon(bool a_left);  // compared elsewhere: 0x720660
};

extern const std::uint32_t kTypeTable[];

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
    virtual bool IsDead(bool a_notEssential = true) const;  // 0x99

    std::uint32_t Func117();  // compared: 0x6ca1c0

    std::uint8_t pad08[0xF8 - 0x8];
    ActorProcess* currentProcess;
};
