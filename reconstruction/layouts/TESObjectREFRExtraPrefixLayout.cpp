// Build: sse-steam-1-7-104
// Source exposure: mixed (pinned target image, community headers).
// Drafted by GPT-6.1 Terra. Labels: v2
// Code origin: target-informed original member-delegation bodies; GetLinkedRef follows the trivial delegation in CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/T/TESObjectREFR.cpp (MIT). No sibling body reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a; MIT.
// Adapted type and member spellings use community declarations; prefix models and unlisted
// wrapper/callee names or types remain inferred. The target establishes the addressed member
// offsets and tail callees, not the source names, complete type sizes or member semantics.
// These are partial layouts, not a claim about complete original class declarations.
// Prefix layout names and inferred members: GUESS(low) STANDIN
// Community type and member names: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
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
// Evidence: findings/target-pin.md.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// ForceEditorLocation: RVA 0x2dfbc0, 9 bytes
// GetCurrentScene: RVA 0x2e6a90, 9 bytes
// SetCurrentScene: RVA 0x2e6aa0, 9 bytes
// GetMagicLightData: RVA 0x2e76f0, 9 bytes
// GetAction: RVA 0x2e7a10, 9 bytes
// HasAction: RVA 0x2e7a20, 9 bytes
// GetActionReference: RVA 0x2e7b50, 9 bytes
// GetOwner: RVA 0x300730, 9 bytes
// GetMapMarkerData: RVA 0x301120, 9 bytes
// GetLock: RVA 0x301410, 9 bytes
// GetMultiBoundRef: RVA 0x301da0, 9 bytes
// GetLocationRefType: RVA 0x301f50, 9 bytes
// GetEmittanceSource: RVA 0x301ff0, 9 bytes
// GetRandomTeleportMarker: RVA 0x302030, 9 bytes
// IsOppositeEnableState: RVA 0x302ff0, 9 bytes
// GetEnableStateChildren: RVA 0x3033d0, 9 bytes
// GetLinkedRef: RVA 0x302050, 9 bytes
#include "TESObjectREFRExtraPrefixLayout.h"
namespace ResearchLayouts {
void TESObjectREFRExtraPrefixLayout::ForceEditorLocation(BGSLocation* location) { extraList.ForceEditorLocation(location); }
BGSScene* TESObjectREFRExtraPrefixLayout::GetCurrentScene() const { return extraList.GetCurrentScene(); }
void TESObjectREFRExtraPrefixLayout::SetCurrentScene(BGSScene* scene) { extraList.SetCurrentScene(scene); }
REFR_LIGHT* TESObjectREFRExtraPrefixLayout::GetMagicLightData() const { return extraList.GetMagicLightData(); }
OBJECT_ACTION TESObjectREFRExtraPrefixLayout::GetAction() const { return extraList.GetAction(); }
bool TESObjectREFRExtraPrefixLayout::HasAction(unsigned int flags) const { return extraList.HasAction(flags); }
TESObjectREFR* TESObjectREFRExtraPrefixLayout::GetActionReference() const { return extraList.GetActionReference(); }
TESForm* TESObjectREFRExtraPrefixLayout::GetOwner() const { return const_cast<ExtraDataList&>(extraList).GetOwner(); }
MapMarkerData* TESObjectREFRExtraPrefixLayout::GetMapMarkerData() const { return extraList.GetMapMarkerData(); }
REFR_LOCK* TESObjectREFRExtraPrefixLayout::GetLock() const { return extraList.GetLock(); }
TESObjectREFR* TESObjectREFRExtraPrefixLayout::GetMultiBoundRef() const { return extraList.GetMultiBoundRef(); }
BGSLocationRefType* TESObjectREFRExtraPrefixLayout::GetLocationRefType() const { return extraList.GetLocationRefType(); }
TESForm* TESObjectREFRExtraPrefixLayout::GetEmittanceSource() const { return extraList.GetEmittanceSource(); }
TESObjectREFR* TESObjectREFRExtraPrefixLayout::GetRandomTeleportMarker() const { return extraList.GetRandomTeleportMarker(); }
bool TESObjectREFRExtraPrefixLayout::IsOppositeEnableState() const { return extraList.IsOppositeEnableState(); }
EnableStateChildren* TESObjectREFRExtraPrefixLayout::GetEnableStateChildren() const { return extraList.GetEnableStateChildren(); }
TESObjectREFR* TESObjectREFRExtraPrefixLayout::GetLinkedRef(BGSKeyword* keyword) { return extraList.GetLinkedRef(keyword); }
}
