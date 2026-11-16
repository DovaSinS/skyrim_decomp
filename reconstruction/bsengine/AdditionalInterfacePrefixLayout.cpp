// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (pinned community storage declarations and independent target RTTI/secondary-slot analysis).
// Drafted by GPT-6.1 Sol; reuse of recovered form/reference/menu/interface prefixes.
// Labels: v2
// Code origin: adapted community storage declarations and original narrowed prefix construction; no external implementation body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{T/TESProduceForm.h,S/SimpleAnimationGraphManagerHolder.h,M/MenuEventHandler.h,I/IMapCameraCallbacks.h,H/hkReferencedObject.h,H/hkpBroadPhaseCastCollector.h,H/hkpEntityListener.h,H/hkpPhantomListener.h,H/hkpWorldPostSimulationListener.h}; MIT.
// TESProduceForm, SimpleAnimationGraphManagerHolder, MenuEventHandler, IMapCameraCallbacks, hkReferencedObject, hkpBroadPhaseCastCollector, hkpEntityListener, hkpPhantomListener, hkpWorldPostSimulationListener: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// All ResearchLayouts names ending Layout, PrefixLayout or StorageLayout, Identity tags and physical mirror member names: GUESS(medium) STANDIN
// New typed data groups follow the named public declarations. Smart-pointer/enumeration storage, pointee definitions and original lifetimes are unassessed. The four public produce-chance array entries are represented by a four-byte named seasonal field group, not arbitrary padding.
// Generic contracts represent actual RTTI-bound fieldless vptr prefixes. Identity tags introduce no storage/runtime value. IMapCameraCallbacks preserves its two public slots before destructor slot2; only its destructor adjustor is compared.
// Each owner models its initial known contiguous subobject prefix through the last selected subobject. Intermediate fieldless ancestry and unassessed methods are omitted. Later components, singleton/event-source bases, owner fields, full original definition, source identity, lifetimes and instantiability/behavior remain unclaimed.
// Public explicit padding fields are omitted; alignment gaps remain unassessed. No original field/base is inferred from deletion size.
// Every represented subobject start and selected virtual destructor slot/primary target is independently corroborated by target RTTI/table analysis. Only listed compiler-generated secondary destructor adjustors are compared.
// Constructors, primary destruction and other operations remain outside the match claim. Typed size/offset assertions are layout checks, not function passes. No raw byte array, helper body or emission attribute is introduced.
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
// RVA 0x14644c; 9 bytes
// RVA 0x146458; 9 bytes
// RVA 0x63ce38; 9 bytes
// RVA 0x63ce44; 9 bytes
// RVA 0x31a0a4; 9 bytes
// RVA 0x31a0b0; 9 bytes
// RVA 0x390e18; 9 bytes
// RVA 0x390e24; 9 bytes
// RVA 0x661a74; 9 bytes
// RVA 0x661a80; 9 bytes
// RVA 0x29cce8; 9 bytes
// RVA 0x29ccf4; 9 bytes
// RVA 0x324554; 9 bytes
// RVA 0x324560; 9 bytes
// RVA 0x62dc84; 9 bytes
// RVA 0x62dc90; 9 bytes
// RVA 0x908a04; 9 bytes
// RVA 0x9089f8; 9 bytes
// RVA 0x14e614; 9 bytes
// RVA 0x14e620; 9 bytes
// RVA 0x93bbb8; 9 bytes
// RVA 0x93bbc4; 9 bytes
// RVA 0x14fb1c; 9 bytes
// RVA 0x14fb28; 9 bytes
// RVA 0x9ad308; 9 bytes
// RVA 0x9ad314; 9 bytes
// RVA 0x9506c8; 9 bytes
// RVA 0x9506d4; 9 bytes
// RVA 0x152430; 9 bytes
// RVA 0x15243c; 9 bytes
// RVA 0x99f870; 9 bytes
// RVA 0x99f87c; 9 bytes
// RVA 0x966bc0; 9 bytes
// RVA 0x966bcc; 9 bytes
// RVA 0x5b7b00; 9 bytes
// RVA 0x5b7b0c; 9 bytes
// RVA 0x9cb0d4; 9 bytes
// RVA 0x9cb0e0; 9 bytes
// RVA 0x155bdc; 9 bytes
// RVA 0x155be8; 9 bytes
// RVA 0x3b3294; 9 bytes
// RVA 0x3b32a0; 9 bytes
// RVA 0x275924; 9 bytes
// RVA 0x275930; 9 bytes
// RVA 0x27593c; 9 bytes
// RVA 0x286f54; 9 bytes
// RVA 0x286f60; 9 bytes
// RVA 0x286f6c; 9 bytes
// RVA 0x2f8c00; 9 bytes
// RVA 0x2f8be8; 9 bytes
// RVA 0x2f8bf4; 9 bytes
// RVA 0x288504; 9 bytes
// RVA 0x288510; 9 bytes
// RVA 0x28851c; 9 bytes
// RVA 0x28e478; 9 bytes
// RVA 0x28e484; 9 bytes
// RVA 0x28e490; 9 bytes
// RVA 0x28f174; 9 bytes
// RVA 0x28f180; 9 bytes
// RVA 0x28f18c; 9 bytes
// RVA 0x10df620; 9 bytes
// RVA 0x10df62c; 9 bytes
// RVA 0x1125e2c; 9 bytes
// RVA 0x1125e38; 9 bytes
// RVA 0x1125e44; 9 bytes
// RVA 0x112742c; 9 bytes
// RVA 0x1127438; 9 bytes
// RVA 0x1127444; 9 bytes
// RVA 0x154c14; 9 bytes
// RVA 0x154c20; 9 bytes
// RVA 0x10deeb0; 9 bytes
// RVA 0x10deebc; 9 bytes
#include "AdditionalInterfacePrefixLayout.h"
namespace ResearchLayouts {
AlchemyItemAdditionalStoragePrefixLayout::AlchemyItemAdditionalStoragePrefixLayout() = default;
AppResourceCaching___anonymous___ManagerAdditionalStoragePrefixLayout::AppResourceCaching___anonymous___ManagerAdditionalStoragePrefixLayout() = default;
BGSCameraShotAdditionalStoragePrefixLayout::BGSCameraShotAdditionalStoragePrefixLayout() = default;
BGSHeadPartAdditionalStoragePrefixLayout::BGSHeadPartAdditionalStoragePrefixLayout() = default;
BGSImpactManagerAdditionalStoragePrefixLayout::BGSImpactManagerAdditionalStoragePrefixLayout() = default;
BGSLocationAdditionalStoragePrefixLayout::BGSLocationAdditionalStoragePrefixLayout() = default;
BGSMessageAdditionalStoragePrefixLayout::BGSMessageAdditionalStoragePrefixLayout() = default;
BGSSaveLoadManagerAdditionalStoragePrefixLayout::BGSSaveLoadManagerAdditionalStoragePrefixLayout() = default;
BookMenuAdditionalStoragePrefixLayout::BookMenuAdditionalStoragePrefixLayout() = default;
EnchantmentItemAdditionalStoragePrefixLayout::EnchantmentItemAdditionalStoragePrefixLayout() = default;
HUDMenuAdditionalStoragePrefixLayout::HUDMenuAdditionalStoragePrefixLayout() = default;
IngredientItemAdditionalStoragePrefixLayout::IngredientItemAdditionalStoragePrefixLayout() = default;
JournalMenuAdditionalStoragePrefixLayout::JournalMenuAdditionalStoragePrefixLayout() = default;
LockpickingMenuAdditionalStoragePrefixLayout::LockpickingMenuAdditionalStoragePrefixLayout() = default;
MagicItemAdditionalStoragePrefixLayout::MagicItemAdditionalStoragePrefixLayout() = default;
MapMenuAdditionalStoragePrefixLayout::MapMenuAdditionalStoragePrefixLayout() = default;
MistMenuAdditionalStoragePrefixLayout::MistMenuAdditionalStoragePrefixLayout() = default;
ModManagerMenuAdditionalStoragePrefixLayout::ModManagerMenuAdditionalStoragePrefixLayout() = default;
SkyrimScript__QuestCallbackMgrAdditionalStoragePrefixLayout::SkyrimScript__QuestCallbackMgrAdditionalStoragePrefixLayout() = default;
SpellItemAdditionalStoragePrefixLayout::SpellItemAdditionalStoragePrefixLayout() = default;
TESEyesAdditionalStoragePrefixLayout::TESEyesAdditionalStoragePrefixLayout() = default;
TESObjectLIGHAdditionalStoragePrefixLayout::TESObjectLIGHAdditionalStoragePrefixLayout() = default;
TESObjectMISCAdditionalStoragePrefixLayout::TESObjectMISCAdditionalStoragePrefixLayout() = default;
TESObjectREFRAdditionalStoragePrefixLayout::TESObjectREFRAdditionalStoragePrefixLayout() = default;
TESObjectTREEAdditionalStoragePrefixLayout::TESObjectTREEAdditionalStoragePrefixLayout() = default;
TESObjectWEAPAdditionalStoragePrefixLayout::TESObjectWEAPAdditionalStoragePrefixLayout() = default;
TESSoulGemAdditionalStoragePrefixLayout::TESSoulGemAdditionalStoragePrefixLayout() = default;
ahkpCharacterRigidBodyAdditionalStoragePrefixLayout::ahkpCharacterRigidBodyAdditionalStoragePrefixLayout() = default;
hkCpuWorldLinearCastCollectorAdditionalStoragePrefixLayout::hkCpuWorldLinearCastCollectorAdditionalStoragePrefixLayout() = default;
hkCpuWorldRayCastCollectorAdditionalStoragePrefixLayout::hkCpuWorldRayCastCollectorAdditionalStoragePrefixLayout() = default;
ScrollItemAdditionalStoragePrefixLayout::ScrollItemAdditionalStoragePrefixLayout() = default;
ahkpCharacterProxyAdditionalStoragePrefixLayout::ahkpCharacterProxyAdditionalStoragePrefixLayout() = default;
}
