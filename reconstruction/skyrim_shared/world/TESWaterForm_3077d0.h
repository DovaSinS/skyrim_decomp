// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESWaterForm, TESWaterForm::Activate, TESWaterForm::contactSpell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); Activate is virtual slot 0x37
// TESObjectREFR::GetMagicCaster (slot 0x5C), MagicCaster::CastSpellImmediate (slot 01): COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectREFR, MagicCaster, MagicItem, SpellItem, TESBoundObject, Actor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the used slots, names as in the community headers
// MagicSystem::CastingSource, kInstant: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the value 3 is the instant source
// unk00 to unk5B, unk01 to unk36, unknown08: GUESS(low); placeholders that put the used virtuals at their slots and fill the layout
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESWaterForm.cpp:237
#pragma once

#include <cstdint>

class Actor;
class MagicItem
{
};

class SpellItem : public MagicItem
{
};

class TESBoundObject;

namespace MagicSystem
{
    enum class CastingSource : std::uint32_t
    {
        kLeftHand = 0,
        kRightHand = 1,
        kOther = 2,
        kInstant = 3
    };
}

class TESObjectREFR;

class MagicCaster
{
public:
    virtual void unk00();  // 00
    virtual void CastSpellImmediate(MagicItem* a_spell, bool a_noHitEffectArt, TESObjectREFR* a_target, float a_effectiveness, bool a_hostileEffectivenessOnly, float a_magnitudeOverride, Actor* a_blameActor);  // 01
};

class TESObjectREFR
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
    virtual MagicCaster* GetMagicCaster(MagicSystem::CastingSource a_source);  // 5C
};

class TESWaterForm
{
public:
    virtual void unk00();  // 00
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
    virtual bool Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount);  // 37

    std::uint8_t unknown08[0x1F0];  // 08
    SpellItem* contactSpell;        // 1F8
};
