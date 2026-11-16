// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (pinned community component storage and independent target RTTI/secondary-slot analysis).
// Drafted by GPT-6.1 Sol; shared form component prefix extension.
// Labels: v2
// Code origin: adapted community declarations and original narrowed prefix construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{T/TESRaceForm.h,T/TESEnchantableForm.h,T/TESValueForm.h,T/TESWeightForm.h,T/TESModelTextureSwap.h,T/TESContainer.h,B/BGSMenuDisplayObject.h,B/BGSEquipType.h}; MIT.
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
// RVA 0x446c8c; 9 bytes
// RVA 0x446c98; 9 bytes
// RVA 0x446ca4; 9 bytes
// RVA 0x25ca2c; 9 bytes
// RVA 0x25ca38; 9 bytes
// RVA 0x25ca44; 9 bytes
// RVA 0x38c3d4; 9 bytes
// RVA 0x38c3e0; 9 bytes
// RVA 0x26161c; 9 bytes
// RVA 0x261628; 9 bytes
// RVA 0x261634; 9 bytes
// RVA 0x398028; 9 bytes
// RVA 0x398034; 9 bytes
// RVA 0x398040; 9 bytes
// RVA 0x2675a4; 9 bytes
// RVA 0x2675b0; 9 bytes
// RVA 0x2675bc; 9 bytes
// RVA 0x14c6ac; 9 bytes
// RVA 0x14c6b8; 9 bytes
// RVA 0x14c6c4; 9 bytes
// RVA 0x269400; 9 bytes
// RVA 0x26940c; 9 bytes
// RVA 0x2693f4; 9 bytes
// RVA 0x3b2c00; 9 bytes
// RVA 0x3b2c0c; 9 bytes
// RVA 0x3b2bf4; 9 bytes
// RVA 0x26dc3c; 9 bytes
// RVA 0x26dc48; 9 bytes
// RVA 0x26dc54; 9 bytes
// RVA 0x26fe68; 9 bytes
// RVA 0x26fe74; 9 bytes
// RVA 0x26fe80; 9 bytes
// RVA 0x270ee4; 9 bytes
// RVA 0x270ef0; 9 bytes
// RVA 0x270efc; 9 bytes
// RVA 0x27ac8c; 9 bytes
// RVA 0x27ac98; 9 bytes
// RVA 0x27aca4; 9 bytes
// RVA 0x27ef18; 9 bytes
// RVA 0x27ef30; 9 bytes
// RVA 0x27ef3c; 9 bytes
// RVA 0x27ef48; 9 bytes
// RVA 0x2806e8; 9 bytes
// RVA 0x2806f4; 9 bytes
// RVA 0x280700; 9 bytes
// RVA 0x282324; 9 bytes
// RVA 0x282330; 9 bytes
// RVA 0x28233c; 9 bytes
// RVA 0x285758; 9 bytes
// RVA 0x285764; 9 bytes
// RVA 0x285770; 9 bytes
// RVA 0x388364; 9 bytes
// RVA 0x388370; 9 bytes
// RVA 0x38837c; 9 bytes
// RVA 0x388388; 9 bytes
#include "RaceComponentLayout.h"
namespace ResearchLayouts {
ActorValueInfoExtendedFormPrefixLayout::ActorValueInfoExtendedFormPrefixLayout() = default;
BGSApparatusExtendedFormPrefixLayout::BGSApparatusExtendedFormPrefixLayout() = default;
BGSBodyPartDataExtendedFormPrefixLayout::BGSBodyPartDataExtendedFormPrefixLayout() = default;
BGSExplosionExtendedFormPrefixLayout::BGSExplosionExtendedFormPrefixLayout() = default;
BGSPerkExtendedFormPrefixLayout::BGSPerkExtendedFormPrefixLayout() = default;
BGSTalkingActivatorExtendedFormPrefixLayout::BGSTalkingActivatorExtendedFormPrefixLayout() = default;
EffectSettingExtendedFormPrefixLayout::EffectSettingExtendedFormPrefixLayout() = default;
TESAmmoExtendedFormPrefixLayout::TESAmmoExtendedFormPrefixLayout() = default;
TESClassExtendedFormPrefixLayout::TESClassExtendedFormPrefixLayout() = default;
TESFloraExtendedFormPrefixLayout::TESFloraExtendedFormPrefixLayout() = default;
TESFurnitureExtendedFormPrefixLayout::TESFurnitureExtendedFormPrefixLayout() = default;
TESKeyExtendedFormPrefixLayout::TESKeyExtendedFormPrefixLayout() = default;
TESObjectACTIExtendedFormPrefixLayout::TESObjectACTIExtendedFormPrefixLayout() = default;
TESObjectARMOExtendedFormPrefixLayout::TESObjectARMOExtendedFormPrefixLayout() = default;
TESObjectBOOKExtendedFormPrefixLayout::TESObjectBOOKExtendedFormPrefixLayout() = default;
TESObjectCONTExtendedFormPrefixLayout::TESObjectCONTExtendedFormPrefixLayout() = default;
TESObjectDOORExtendedFormPrefixLayout::TESObjectDOORExtendedFormPrefixLayout() = default;
TESShoutExtendedFormPrefixLayout::TESShoutExtendedFormPrefixLayout() = default;
}
