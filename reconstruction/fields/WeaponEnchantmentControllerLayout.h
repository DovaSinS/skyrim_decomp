// Build: sse-steam-1-7-104
// Source exposure: mixed (pinned community declarations and local target access/RTTI analysis).
// Drafted by GPT-6.1 Sol; p144 layout preparation, owner awarebayes, 2026-11-15.
// Evidence: findings/represented-layout-preparation.md
// Labels: v2
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944; include/RE/W/WeaponEnchantmentController.h; include/RE/R/ReferenceEffectController.h; GPL-3.0.
// Code origin: adapted data declarations only; no external implementation bodies.
// WeaponEnchantmentControllerLayout: GUESS(medium) STANDIN; represented declaration aliases, not original type identities.
// Field spellings below retain the cited community declarations unless explicitly guessed.
// Omitted methods and pointee semantics are unassessed. Compiler alignment supplies padding.
// Each assertion proves its stated layout property; Mac comparisons cover only the indexed functions.
// attachRoot models the public NiPointer as its single pointer member; ownership and methods are omitted.
// Code origin: represented declaration from reconstruction/bsengine/WeaponEnchantmentControllerLayout.h; only include spelling changed.
#pragma once
#include <cstddef>
#include <cstdint>
#include "ReferenceEffectControllerLayout.h"
namespace ResearchLayouts {
class ActorMagicCaster;
class Actor;
class TESEffectShader;
class BGSArtObject;
class NiAVObject;
class TESObjectWEAP;
// caster, target, shader, art, attachRoot, lastWeapon, firstPerson: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
class WeaponEnchantmentControllerLayout : public ReferenceEffectControllerLayout {
public:
    ~WeaponEnchantmentControllerLayout() override;
    ActorMagicCaster* caster;
    Actor* target;
    TESEffectShader* shader;
    BGSArtObject* art;
    NiAVObject* attachRoot;
    TESObjectWEAP* lastWeapon;
    bool firstPerson;
};
static_assert(sizeof(WeaponEnchantmentControllerLayout) == 64, "public controller fields");
static_assert(offsetof(WeaponEnchantmentControllerLayout, caster) == 8, "public field offset");
static_assert(offsetof(WeaponEnchantmentControllerLayout, target) == 16, "public field offset");
static_assert(offsetof(WeaponEnchantmentControllerLayout, shader) == 24, "public field offset");
static_assert(offsetof(WeaponEnchantmentControllerLayout, art) == 32, "public field offset");
static_assert(offsetof(WeaponEnchantmentControllerLayout, attachRoot) == 40, "public field offset");
static_assert(offsetof(WeaponEnchantmentControllerLayout, lastWeapon) == 48, "public field offset");
static_assert(offsetof(WeaponEnchantmentControllerLayout, firstPerson) == 56, "public field offset");
}
