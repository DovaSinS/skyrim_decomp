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
#pragma once
#include <cstdint>
class REFR_LIGHT; class REFR_LOCK; class DoorTeleportData; class MapMarkerData; class TESForm; class AlchemyItem;
enum class ExtraDataType { kDetachTime = 0x0a, kOwnership = 0x21, kLight = 0x29, kLock = 0x2a, kTeleport = 0x2b, kMapMarker = 0x2c, kPoison = 0x3e, kHotkey = 0x49, kLockList = 0xa3 };
class BSExtraData { public: virtual ~BSExtraData(); BSExtraData* next; };
class ExtraDetachTime : public BSExtraData { public: std::uint32_t time; };
class ExtraPoison : public BSExtraData { public: AlchemyItem* poison; std::uint32_t count; };
class ExtraLight : public BSExtraData { public: REFR_LIGHT* lightData; };
class ExtraLock : public BSExtraData { public: REFR_LOCK* lock; };
class ExtraTeleport : public BSExtraData { public: DoorTeleportData* teleportData; };
class ExtraMapMarker : public BSExtraData { public: MapMarkerData* mapData; };
class ExtraOwnership : public BSExtraData { public: TESForm* owner; };
class ExtraLockList : public BSExtraData { public: TESForm* list; };
class ExtraDataList { public:
 BSExtraData* GetByType(ExtraDataType type);
 bool HasHotkey();
 std::uint32_t QueryDetachTime();
 std::uint32_t GetPoisonCount();
 REFR_LIGHT* GetLightData();
 REFR_LOCK* GetLockData();
 DoorTeleportData* GetTeleportData();
 MapMarkerData* GetMapMarkerData();
 TESForm* GetOwner();
 TESForm* QueryLockList();
 };
