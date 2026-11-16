// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (pinned community component declarations; independent target RTTI and secondary-slot analysis).
// Drafted by GPT-6.1 Sol; form-component prefix recovery.
// Labels: v2
// Code origin: adapted community declarations and original narrowed prefix construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, include/RE/{B,T,N} component headers; MIT.
// BaseFormComponent, TESForm, TESObject, TESBoundObject, TESFullName, TESDescription, TESSpellList, BGSSkinForm, BGSBipedObjectForm, BGSKeywordForm, BGSAttackDataForm, TESModel, TESTexture, TESIcon, BGSPickupPutdownSounds, BGSPreloadable, TESImageSpaceModifiableForm, BGSDestructibleObjectForm, BSFixedString, BGSLocalizedStringDL, NiPointer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESRace, BGSNote, BGSHazard, BGSProjectile: EXE_RTTI
// All ResearchLayouts class and struct names ending Layout, the physical storage wrappers and prefix mirror names: GUESS(medium) STANDIN
// Storage-wrapper member spellings are guesses; original component member names and physical storage widths follow the named pinned community headers. Unknown pointee definitions and ownership behavior remain unassessed.
// Enumeration and string/smart-pointer wrappers below explicitly represent storage only; no lifetime or behavioral equivalence is claimed.
// Each owner represents its complete nonvirtual component-base prefix, not the subsequent owner data fields. Whole-object size and original instantiability are unclaimed.
// Component method sets beyond the common destructor/component interface are omitted, rather than invented. Only destructor slot zero is used by the compared code.
// Base order and offsets are independently reconciled with the target RTTI hierarchy and exact secondary destructor slots. No deletion-size argument is used.
// Only listed compiler-emitted secondary deleting-destructor adjustors are compared; constructors, original owner destruction and component operations are outside this claim.
// Size and offset assertions check these represented component prefixes; they are not function passes or claims about omitted owner fields.
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
#include "FormComponentLayout.h"
namespace ResearchLayouts {
class BGSProjectileComponentPrefixLayout :
    public BoundObjectFormHeaderLayout,
    public FullNameComponentLayout,
    public ModelComponentLayout,
    public PreloadableComponentLayout,
    public DestructibleComponentLayout {
public:
    BGSProjectileComponentPrefixLayout();
    ~BGSProjectileComponentPrefixLayout() override;
};
static_assert(sizeof(BGSProjectileComponentPrefixLayout) == 128, "component-base prefix only, owner data tail unclaimed");
struct BGSProjectileComponentPrefixLayoutStorage {
    BoundObjectFormHeaderLayout component0;
    FullNameComponentLayout component1;
    ModelComponentLayout component2;
    PreloadableVptrStorageLayout component3;
    DestructibleComponentLayout component4;
};
static_assert(sizeof(BGSProjectileComponentPrefixLayoutStorage) == sizeof(BGSProjectileComponentPrefixLayout), "physical component-prefix mirror");
static_assert(offsetof(BGSProjectileComponentPrefixLayoutStorage, component0) == 0, "target direct-base offset");
static_assert(offsetof(BGSProjectileComponentPrefixLayoutStorage, component1) == 48, "target direct-base offset");
static_assert(offsetof(BGSProjectileComponentPrefixLayoutStorage, component2) == 64, "target direct-base offset");
static_assert(offsetof(BGSProjectileComponentPrefixLayoutStorage, component3) == 104, "target direct-base offset");
static_assert(offsetof(BGSProjectileComponentPrefixLayoutStorage, component4) == 112, "target direct-base offset");
}
