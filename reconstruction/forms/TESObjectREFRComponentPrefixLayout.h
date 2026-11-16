// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (pinned community storage declarations; independent target RTTI and exact secondary-slot analysis).
// Drafted by GPT-6.1 Sol; shared TESObjectREFR component prefix recovery.
// Labels: v2
// Code origin: adapted community storage declarations and original narrowed prefix construction. No external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{T/TESObjectREFR.h,B/BSHandleRefObject.h,N/NiRefObject.h,B/BSTEvent.h,I/IAnimationGraphManagerHolder.h}; MIT.
// TESObjectREFR, BSHandleRefObject, NiRefObject, BSTEventSink, BSAnimationGraphEvent, IAnimationGraphManagerHolder: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// All ResearchLayouts type names ending Layout, StorageLayout or PrefixLayout, and physical mirror member names: GUESS(medium) STANDIN
// TESObjectREFR's represented prefix consists of its public TESForm32, BSHandleRefObject16 and two fieldless eight-byte interface subobjects. Independent target RTTI places these at0,32,48,56 for every selected owner.
// NiRefObject count storage and TESForm component fields are represented by the included pinned community declarations. No owner size is derived from deletion size.
// These declarations represent only the shared initial64-byte component prefix. TESObjectREFR data from64 onward, derived-owner fields, other bases, unassessed method sets, source identity and original instantiability/behavior are unclaimed.
// Fieldless interface methods beyond destructor slot0 are omitted. Intermediate fieldless inheritance is flattened in each owner's prefix view; this is not a complete original owner definition.
// Only listed ordinary compiler-emitted secondary destructor adjustors are compared; constructors, primary destruction and all other methods remain outside the byte-match claim.
// Typed size/offset assertions check represented storage, never a function pass. No raw arrays, explicit padding, helper body or code-emission attribute is introduced.
// MIT License
// 
// Copyright (c) 2018 Ryan-rsm-McKenzie
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
#pragma once
#include <cstddef>
#include "FormComponentLayout.h"
#include "../netimmerse/NiRefObjectStorageLayout.h"
namespace ResearchLayouts {
class HandleReferenceComponentPrefixLayout : public NiRefObjectStorageLayout {
public:
    ~HandleReferenceComponentPrefixLayout() override;
};
class AnimationGraphEventSinkPrefixLayout {
public:
    virtual ~AnimationGraphEventSinkPrefixLayout();
};
class AnimationGraphManagerHolderPrefixLayout {
public:
    virtual ~AnimationGraphManagerHolderPrefixLayout();
};
class TESObjectREFRComponentPrefixLayout : public FormHeaderLayout, public HandleReferenceComponentPrefixLayout, public AnimationGraphEventSinkPrefixLayout, public AnimationGraphManagerHolderPrefixLayout {
public:
    TESObjectREFRComponentPrefixLayout();
    ~TESObjectREFRComponentPrefixLayout() override;
};
struct ObjectReferenceComponentStorageLayout {
    FormHeaderLayout form;
    HandleReferenceComponentPrefixLayout reference;
    const void* const* animationEventSink;
    const void* const* graphHolder;
};
static_assert(sizeof(HandleReferenceComponentPrefixLayout) == 16, "pinned public reference storage");
static_assert(offsetof(HandleReferenceComponentPrefixLayout, _refCount) == 8, "public reference count offset");
static_assert(sizeof(AnimationGraphEventSinkPrefixLayout) == 8, "fieldless event sink prefix");
static_assert(sizeof(AnimationGraphManagerHolderPrefixLayout) == 8, "fieldless graph holder prefix");
static_assert(sizeof(TESObjectREFRComponentPrefixLayout) == 64, "represented component prefix only");
static_assert(sizeof(ObjectReferenceComponentStorageLayout) == 64, "physical prefix mirror");
static_assert(offsetof(ObjectReferenceComponentStorageLayout, reference) == 32, "independent target reference subobject offset");
static_assert(offsetof(ObjectReferenceComponentStorageLayout, animationEventSink) == 48, "independent target event sink offset");
static_assert(offsetof(ObjectReferenceComponentStorageLayout, graphHolder) == 56, "independent target graph holder offset");
// Actor: EXE_RTTI
// Owner descriptor: .?AVActor@@
class ActorReferenceComponentPrefixLayout : public TESObjectREFRComponentPrefixLayout {
public:
    ActorReferenceComponentPrefixLayout();
    ~ActorReferenceComponentPrefixLayout() override;
};
static_assert(sizeof(ActorReferenceComponentPrefixLayout) == 64, "represented inherited component prefix only");
// ArrowProjectile: EXE_RTTI
// Owner descriptor: .?AVArrowProjectile@@
class ArrowProjectileReferenceComponentPrefixLayout : public TESObjectREFRComponentPrefixLayout {
public:
    ArrowProjectileReferenceComponentPrefixLayout();
    ~ArrowProjectileReferenceComponentPrefixLayout() override;
};
static_assert(sizeof(ArrowProjectileReferenceComponentPrefixLayout) == 64, "represented inherited component prefix only");
// BarrierProjectile: EXE_RTTI
// Owner descriptor: .?AVBarrierProjectile@@
class BarrierProjectileReferenceComponentPrefixLayout : public TESObjectREFRComponentPrefixLayout {
public:
    BarrierProjectileReferenceComponentPrefixLayout();
    ~BarrierProjectileReferenceComponentPrefixLayout() override;
};
static_assert(sizeof(BarrierProjectileReferenceComponentPrefixLayout) == 64, "represented inherited component prefix only");
// BeamProjectile: EXE_RTTI
// Owner descriptor: .?AVBeamProjectile@@
class BeamProjectileReferenceComponentPrefixLayout : public TESObjectREFRComponentPrefixLayout {
public:
    BeamProjectileReferenceComponentPrefixLayout();
    ~BeamProjectileReferenceComponentPrefixLayout() override;
};
static_assert(sizeof(BeamProjectileReferenceComponentPrefixLayout) == 64, "represented inherited component prefix only");
// ChainExplosion: EXE_RTTI
// Owner descriptor: .?AVChainExplosion@@
class ChainExplosionReferenceComponentPrefixLayout : public TESObjectREFRComponentPrefixLayout {
public:
    ChainExplosionReferenceComponentPrefixLayout();
    ~ChainExplosionReferenceComponentPrefixLayout() override;
};
static_assert(sizeof(ChainExplosionReferenceComponentPrefixLayout) == 64, "represented inherited component prefix only");
// Character: EXE_RTTI
// Owner descriptor: .?AVCharacter@@
class CharacterReferenceComponentPrefixLayout : public TESObjectREFRComponentPrefixLayout {
public:
    CharacterReferenceComponentPrefixLayout();
    ~CharacterReferenceComponentPrefixLayout() override;
};
static_assert(sizeof(CharacterReferenceComponentPrefixLayout) == 64, "represented inherited component prefix only");
// ConeProjectile: EXE_RTTI
// Owner descriptor: .?AVConeProjectile@@
class ConeProjectileReferenceComponentPrefixLayout : public TESObjectREFRComponentPrefixLayout {
public:
    ConeProjectileReferenceComponentPrefixLayout();
    ~ConeProjectileReferenceComponentPrefixLayout() override;
};
static_assert(sizeof(ConeProjectileReferenceComponentPrefixLayout) == 64, "represented inherited component prefix only");
// Explosion: EXE_RTTI
// Owner descriptor: .?AVExplosion@@
class ExplosionReferenceComponentPrefixLayout : public TESObjectREFRComponentPrefixLayout {
public:
    ExplosionReferenceComponentPrefixLayout();
    ~ExplosionReferenceComponentPrefixLayout() override;
};
static_assert(sizeof(ExplosionReferenceComponentPrefixLayout) == 64, "represented inherited component prefix only");
// FlameProjectile: EXE_RTTI
// Owner descriptor: .?AVFlameProjectile@@
class FlameProjectileReferenceComponentPrefixLayout : public TESObjectREFRComponentPrefixLayout {
public:
    FlameProjectileReferenceComponentPrefixLayout();
    ~FlameProjectileReferenceComponentPrefixLayout() override;
};
static_assert(sizeof(FlameProjectileReferenceComponentPrefixLayout) == 64, "represented inherited component prefix only");
// GrenadeProjectile: EXE_RTTI
// Owner descriptor: .?AVGrenadeProjectile@@
class GrenadeProjectileReferenceComponentPrefixLayout : public TESObjectREFRComponentPrefixLayout {
public:
    GrenadeProjectileReferenceComponentPrefixLayout();
    ~GrenadeProjectileReferenceComponentPrefixLayout() override;
};
static_assert(sizeof(GrenadeProjectileReferenceComponentPrefixLayout) == 64, "represented inherited component prefix only");
// Hazard: EXE_RTTI
// Owner descriptor: .?AVHazard@@
class HazardReferenceComponentPrefixLayout : public TESObjectREFRComponentPrefixLayout {
public:
    HazardReferenceComponentPrefixLayout();
    ~HazardReferenceComponentPrefixLayout() override;
};
static_assert(sizeof(HazardReferenceComponentPrefixLayout) == 64, "represented inherited component prefix only");
// MissileProjectile: EXE_RTTI
// Owner descriptor: .?AVMissileProjectile@@
class MissileProjectileReferenceComponentPrefixLayout : public TESObjectREFRComponentPrefixLayout {
public:
    MissileProjectileReferenceComponentPrefixLayout();
    ~MissileProjectileReferenceComponentPrefixLayout() override;
};
static_assert(sizeof(MissileProjectileReferenceComponentPrefixLayout) == 64, "represented inherited component prefix only");
// PlayerCharacter: EXE_RTTI
// Owner descriptor: .?AVPlayerCharacter@@
class PlayerCharacterReferenceComponentPrefixLayout : public TESObjectREFRComponentPrefixLayout {
public:
    PlayerCharacterReferenceComponentPrefixLayout();
    ~PlayerCharacterReferenceComponentPrefixLayout() override;
};
static_assert(sizeof(PlayerCharacterReferenceComponentPrefixLayout) == 64, "represented inherited component prefix only");
// Projectile: EXE_RTTI
// Owner descriptor: .?AVProjectile@@
class ProjectileReferenceComponentPrefixLayout : public TESObjectREFRComponentPrefixLayout {
public:
    ProjectileReferenceComponentPrefixLayout();
    ~ProjectileReferenceComponentPrefixLayout() override;
};
static_assert(sizeof(ProjectileReferenceComponentPrefixLayout) == 64, "represented inherited component prefix only");
}
