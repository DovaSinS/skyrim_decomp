// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (pinned community component storage and independent target RTTI/secondary-slot analysis).
// Drafted by GPT-6.1 Terra using typed community declarations and target metadata.
// Labels: v2
// Code origin: adapted community declarations and original narrowed prefix construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{B/BGSMessageIcon.h,B/BGSPickupPutdownSounds.h,T/TESAttackDamageForm.h,B/BGSBlockBashData.h}; MIT.
// TESRaceForm, TESEnchantableForm, TESValueForm, TESWeightForm, TESModelTextureSwap, TESContainer, BGSMenuDisplayObject, BGSEquipType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// All ResearchLayouts names ending Layout, PrefixLayout or StorageLayout, and physical mirror member names: GUESS(medium) STANDIN
// Fields and widths adapt the pinned public declarations. Pointer and enumeration wrappers express storage only, not lifetime/behavior or exact original pointee definitions.
// Public explicit padding fields are omitted; natural alignment gaps are unassessed. The newer TESContainer allowStolenItems field is expressly omitted: no claim that this target contains it or that offset20 is original padding.
// Every owner models only its initial nonvirtual component prefix through the last selected subobject, flattening inherited fieldless ancestry. Subsequent components, nonpolymorphic bases, owner payload, full original definition/method set/instantiability are unclaimed.
// Base order and subobject starts independently agree with target RTTI; each selected slot0 tail target independently agrees with the same owner primary destructor. No deletion-size argument supplies a layout.
// Only listed ordinary compiler-generated secondary destructor adjustors are compared. Constructors, primary destruction and other component operations remain outside the byte-match claim.
// No arrays, invented padding, helper body or emission attribute is introduced. Compile-time size/offset agreement is not a function pass.
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
// Generator: tools/large_form_prefix_generate_v1.py SHA-256 b902e07cc82848db254ec1d1d9b71dde3ba411909b7fc16c917d83aab4e97ce1
// BGSMessageIcon, TESAttackDamageForm, BGSBlockBashData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstddef>
#include "RaceComponentLayout.h"
namespace ResearchLayouts {
// BGSExplosion: EXE_RTTI
// Represented component at 0: TESBoundObject
// Represented component at 48: TESFullName
// Represented component at 64: TESModel
// Represented component at 104: TESEnchantableForm
// Represented component at 128: BGSPreloadable
class BGSExplosionLargeFormPrefixLayout : public BoundObjectFormHeaderLayout, public FullNameComponentLayout, public ModelComponentLayout, public EnchantableComponentLayout, public PreloadableComponentLayout {
public:
    BGSExplosionLargeFormPrefixLayout();
    ~BGSExplosionLargeFormPrefixLayout() override;
    void InitializeDataComponent() override;
    void ClearDataComponent() override;
    void CopyComponent(FormComponentLayout*) override;
    void Unk_04() override;
};
static_assert(sizeof(BGSExplosionLargeFormPrefixLayout) == 136, "represented prefix only");
struct BGSExplosionLargeFormPrefixLayoutStorageLayout {
    BoundObjectFormHeaderLayout component0;
    FullNameComponentLayout component1;
    ModelComponentLayout component2;
    EnchantableComponentLayout component3;
    PreloadableVptrStorageLayout component4;
};
static_assert(offsetof(BGSExplosionLargeFormPrefixLayoutStorageLayout, component0) == 0, "target component offset");
static_assert(offsetof(BGSExplosionLargeFormPrefixLayoutStorageLayout, component1) == 48, "target component offset");
static_assert(offsetof(BGSExplosionLargeFormPrefixLayoutStorageLayout, component2) == 64, "target component offset");
static_assert(offsetof(BGSExplosionLargeFormPrefixLayoutStorageLayout, component3) == 104, "target component offset");
static_assert(offsetof(BGSExplosionLargeFormPrefixLayoutStorageLayout, component4) == 128, "target component offset");
}
