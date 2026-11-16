// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (public component declarations, pinned public temp-effect storage and independent target RTTI/slot analysis).
// Drafted by GPT-6.1 Sol; shared reference-effect primary storage recovery.
// Labels: v2
// Code origin: adapted community storage declarations and original narrowed prefix construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{R/ReferenceEffect.h,B/BSTempEffect.h,M/ModelReferenceEffect.h,S/SummonPlacementEffect.h,B/BGSMovableStatic.h,T/TESObjectSTAT.h}; MIT.
// ReferenceEffect, BSTempEffect, ModelReferenceEffect, SummonPlacementEffect, BGSMovableStatic, TESObjectSTAT: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// All ResearchLayouts names ending Layout or PrefixLayout and storage-only member names: GUESS(medium) STANDIN
// ReferenceEffect72 is represented through public BSTempEffect48 fields over the NiRefObject16 prefix, flattening fieldless NiObject ancestry and controller pointer, two32-bit handles, and two booleans. Handles are storage-only views; no ownership/lifetime behavior is claimed. Public explicit padding is omitted and natural alignment gaps remain unassessed.
// The two effect owners expose only their initial reference/graph-holder/event prefix. BGSMovableStatic exposes only its initial FullName/Destructible/BoundObject/ModelTextureSwap components, flattening fieldless TESObjectSTAT ancestry. Later fields/bases, complete original definitions, unassessed methods, original source identity/instantiability and behavior remain unclaimed.
// Independent target RTTI/COL, virtual destructor slots and primary targets agree with all represented offsets. No deletion-size argument supplies a layout. Only listed compiler-generated secondary destructor adjustors are compared; other construction/destruction/methods are outside the claim.
// Typed size/offset assertions are layout checks, not function passes. No raw byte array, invented padding, helper body or emission attribute is introduced.
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
#include <cstdint>
#include "AdditionalInterfacePrefixLayout.h"
namespace ResearchLayouts {
class TempCellPointeeLayout;
class TemporaryEffectStoragePrefixLayout : public NiRefObjectStorageLayout {
public:
    ~TemporaryEffectStoragePrefixLayout() override;
    float lifetime;
    TempCellPointeeLayout* cell;
    float age;
    bool initialized;
    std::uint32_t effectID;
};
static_assert(sizeof(TemporaryEffectStoragePrefixLayout) == 48, "public temp-effect storage");
static_assert(offsetof(TemporaryEffectStoragePrefixLayout, lifetime) == 16, "public lifetime offset");
static_assert(offsetof(TemporaryEffectStoragePrefixLayout, cell) == 24, "public parent cell pointer offset");
static_assert(offsetof(TemporaryEffectStoragePrefixLayout, age) == 32, "public age offset");
static_assert(offsetof(TemporaryEffectStoragePrefixLayout, initialized) == 36, "public initialized flag offset");
static_assert(offsetof(TemporaryEffectStoragePrefixLayout, effectID) == 40, "public effect identity offset");
class EffectControllerPointeeLayout;
struct ObjectHandleStorageLayout { std::uint32_t value; };
class ReferenceEffectComponentPrefixLayout : public TemporaryEffectStoragePrefixLayout {
public:
    ReferenceEffectComponentPrefixLayout();
    ~ReferenceEffectComponentPrefixLayout() override;
    EffectControllerPointeeLayout* controller;
    ObjectHandleStorageLayout target;
    ObjectHandleStorageLayout aimAtTarget;
    bool finished;
    bool ownController;
};
static_assert(sizeof(ObjectHandleStorageLayout) == 4, "public object handle storage");
static_assert(sizeof(ReferenceEffectComponentPrefixLayout) == 72, "public reference-effect storage");
static_assert(offsetof(ReferenceEffectComponentPrefixLayout, controller) == 48, "public controller pointer offset");
static_assert(offsetof(ReferenceEffectComponentPrefixLayout, target) == 56, "public target handle offset");
static_assert(offsetof(ReferenceEffectComponentPrefixLayout, aimAtTarget) == 60, "public aim handle offset");
static_assert(offsetof(ReferenceEffectComponentPrefixLayout, finished) == 64, "public finished flag offset");
static_assert(offsetof(ReferenceEffectComponentPrefixLayout, ownController) == 65, "public ownership flag offset");
// BGSMovableStatic: EXE_RTTI
// Owner descriptor: .?AVBGSMovableStatic@@
class BGSMovableStaticRecoveredComponentPrefixLayout : public FullNameComponentLayout, public DestructibleComponentLayout, public BoundObjectFormHeaderLayout, public ModelTextureSwapComponentLayout {
public:
    BGSMovableStaticRecoveredComponentPrefixLayout();
    ~BGSMovableStaticRecoveredComponentPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
};
static_assert(sizeof(BGSMovableStaticRecoveredComponentPrefixLayout) == 136, "represented initial component prefix only");
struct BGSMovableStaticRecoveredComponentPrefixLayoutStorageLayout {
    FullNameComponentLayout component0;
    DestructibleComponentLayout component1;
    BoundObjectFormHeaderLayout component2;
    ModelTextureSwapComponentLayout component3;
};
static_assert(sizeof(BGSMovableStaticRecoveredComponentPrefixLayoutStorageLayout) == 136, "physical prefix mirror");
static_assert(offsetof(BGSMovableStaticRecoveredComponentPrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(BGSMovableStaticRecoveredComponentPrefixLayoutStorageLayout, component1) == 16, "independent target subobject offset");
static_assert(offsetof(BGSMovableStaticRecoveredComponentPrefixLayoutStorageLayout, component2) == 32, "independent target subobject offset");
static_assert(offsetof(BGSMovableStaticRecoveredComponentPrefixLayoutStorageLayout, component3) == 80, "independent target subobject offset");
// ModelReferenceEffect: EXE_RTTI
// Owner descriptor: .?AVModelReferenceEffect@@
class ModelReferenceEffectRecoveredComponentPrefixLayout : public ReferenceEffectComponentPrefixLayout, public SimpleGraphHolderPrefixLayout, public AdditionalInterfacePrefixLayout<4001> {
public:
    ModelReferenceEffectRecoveredComponentPrefixLayout();
    ~ModelReferenceEffectRecoveredComponentPrefixLayout() override;
};
static_assert(sizeof(ModelReferenceEffectRecoveredComponentPrefixLayout) == 104, "represented initial component prefix only");
struct ModelReferenceEffectRecoveredComponentPrefixLayoutStorageLayout {
    ReferenceEffectComponentPrefixLayout component0;
    SimpleGraphHolderPrefixLayout component1;
    AdditionalInterfacePrefixLayout<4001> component2;
};
static_assert(sizeof(ModelReferenceEffectRecoveredComponentPrefixLayoutStorageLayout) == 104, "physical prefix mirror");
static_assert(offsetof(ModelReferenceEffectRecoveredComponentPrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(ModelReferenceEffectRecoveredComponentPrefixLayoutStorageLayout, component1) == 72, "independent target subobject offset");
static_assert(offsetof(ModelReferenceEffectRecoveredComponentPrefixLayoutStorageLayout, component2) == 96, "independent target subobject offset");
// SummonPlacementEffect: EXE_RTTI
// Owner descriptor: .?AVSummonPlacementEffect@@
class SummonPlacementEffectRecoveredComponentPrefixLayout : public ReferenceEffectComponentPrefixLayout, public SimpleGraphHolderPrefixLayout, public AdditionalInterfacePrefixLayout<4002> {
public:
    SummonPlacementEffectRecoveredComponentPrefixLayout();
    ~SummonPlacementEffectRecoveredComponentPrefixLayout() override;
};
static_assert(sizeof(SummonPlacementEffectRecoveredComponentPrefixLayout) == 104, "represented initial component prefix only");
struct SummonPlacementEffectRecoveredComponentPrefixLayoutStorageLayout {
    ReferenceEffectComponentPrefixLayout component0;
    SimpleGraphHolderPrefixLayout component1;
    AdditionalInterfacePrefixLayout<4002> component2;
};
static_assert(sizeof(SummonPlacementEffectRecoveredComponentPrefixLayoutStorageLayout) == 104, "physical prefix mirror");
static_assert(offsetof(SummonPlacementEffectRecoveredComponentPrefixLayoutStorageLayout, component0) == 0, "independent target subobject offset");
static_assert(offsetof(SummonPlacementEffectRecoveredComponentPrefixLayoutStorageLayout, component1) == 72, "independent target subobject offset");
static_assert(offsetof(SummonPlacementEffectRecoveredComponentPrefixLayoutStorageLayout, component2) == 96, "independent target subobject offset");
}
