// Labels: v2
// Build: sse-steam-1-7-104
// RVA 0x163940, 25 bytes: HasHotkey.
// RVA 0x1697f0, 32 bytes: QueryDetachTime.
// RVA 0x169d90, 32 bytes: GetPoisonCount.
// RVA 0x164450, 33 bytes: GetLightData.
// RVA 0x164480, 33 bytes: GetLockData.
// RVA 0x1644b0, 33 bytes: GetTeleportData.
// RVA 0x1644e0, 33 bytes: GetMapMarkerData.
// RVA 0x164570, 33 bytes: GetOwner.
// RVA 0x1645a0, 33 bytes: QueryLockList.
// Evidence: findings/ghidra-import.md
// Origin: original reconstruction; declarations adapted from CommonLibSSE-NG include/RE/E/ExtraDataList.h, ExtraDataTypes.h, and individual extra data headers, and include/RE/B/BSExtraData.h.
// Source exposure: mixed (binary-analysis and community headers).
// Drafted by: gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Accessors are compared; GetByType and the data declarations are not compared.
// Community names and signatures are unverified.
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
// ExtraDataList, GetByType, GetOwner, BSExtraData, next, ExtraDataType, ExtraDetachTime, time, ExtraPoison, poison, count, ExtraLight, lightData, ExtraLock, lock, ExtraTeleport, teleportData, ExtraMapMarker, mapData, ExtraOwnership, owner, ExtraLockList, list: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// HasHotkey, QueryDetachTime, GetPoisonCount, GetLightData, GetMapMarkerData, QueryLockList: GUESS(low)
// GetLockData, GetTeleportData: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// REFR_LIGHT, REFR_LOCK, DoorTeleportData, MapMarkerData, TESForm, AlchemyItem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#include "ExtraDataList.h"
bool ExtraDataList::HasHotkey() { return GetByType(ExtraDataType::kHotkey) != nullptr; }
std::uint32_t ExtraDataList::QueryDetachTime() { auto* data = static_cast<ExtraDetachTime*>(GetByType(ExtraDataType::kDetachTime)); return data ? data->time : 0; }
std::uint32_t ExtraDataList::GetPoisonCount() { auto* data = static_cast<ExtraPoison*>(GetByType(ExtraDataType::kPoison)); return data ? data->count : 0; }
REFR_LIGHT* ExtraDataList::GetLightData() { auto* data = static_cast<ExtraLight*>(GetByType(ExtraDataType::kLight)); return data ? data->lightData : nullptr; }
REFR_LOCK* ExtraDataList::GetLockData() { auto* data = static_cast<ExtraLock*>(GetByType(ExtraDataType::kLock)); return data ? data->lock : nullptr; }
DoorTeleportData* ExtraDataList::GetTeleportData() { auto* data = static_cast<ExtraTeleport*>(GetByType(ExtraDataType::kTeleport)); return data ? data->teleportData : nullptr; }
MapMarkerData* ExtraDataList::GetMapMarkerData() { auto* data = static_cast<ExtraMapMarker*>(GetByType(ExtraDataType::kMapMarker)); return data ? data->mapData : nullptr; }
TESForm* ExtraDataList::GetOwner() { auto* data = static_cast<ExtraOwnership*>(GetByType(ExtraDataType::kOwnership)); return data ? data->owner : nullptr; }
TESForm* ExtraDataList::QueryLockList() { auto* data = static_cast<ExtraLockList*>(GetByType(ExtraDataType::kLockList)); return data ? data->list : nullptr; }
