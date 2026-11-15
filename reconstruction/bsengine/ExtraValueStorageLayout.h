// Build: sse-steam-1-7-104
// Source exposure: mixed (community declarations, target RTTI bindings).
// Drafted by GPT-6.1 Sol; p104b represented storage follow-up.
// Labels: v2
// ExtraValueStorageLayout: GUESS(medium) STANDIN; represented public storage alias.
// Code origin: public data declarations and represented reference-count inheritance; no implementation bodies reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT), include/RE/B/BSIntrusiveRefCounted.h, BSTFreeList.h; S/SettingCollection.h, SimpleAllocMemoryPagePolicy.h; A/AttachLightHitEffectVisitor.h, ActorTargetCheck.h; F/FastTravelConfirmCallback.h; I/IFunction.h, IFuncCallQuery.h, IVirtualMachine.h, IMessageBoxCallback.h, IMemoryPagePolicy.h; D/DelayFunctor.h; B/BSAtomic.h.
// Interface aliases retain only the observed primary reference-count base; omitted methods and original complete definitions are unassessed.
// No opaque storage or allocation-sized filler is introduced. The value structs and FormID alias come from public named declarations.
// Pointer pointees and ownership are unassessed. Unknown64-bit fields retain public declarations without assigning behavior.
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
// Declaration source: same pinned MIT CommonLibSSE-NG revision; BSExtraData.h, ExtraLeveledItem.h, ExtraOutfitItem.h, ExtraUniqueID.h, ExtraLightData.h, ExtraNavMeshPortal.h, ExtraPackageStartLocation.h, ExtraStartingPosition.h, NiPoint3.h and BSCoreTypes.h.
#pragma once
#include <cstdint>
#include <cstddef>
namespace ResearchLayouts {
// CommunityFormID, CommunityPoint3, CommunityLightValue, CommunityNavValue, CommunityPortalValue, CommunityWorldValue, CommunityPosRotValue: GUESS(medium) STANDIN; public data aliases.
// x, y, z, fov, fade, endDistanceCap, shadowDepthBias, unk10, navMeshID, navMesh, nav, triIndex, locationForm, locPt, zRot, pos, rot: GUESS(medium) STANDIN; adapted public value member names.
using CommunityFormID=std::uint32_t;
struct CommunityPoint3 { float x; float y; float z; };
struct CommunityLightValue { float fov; float fade; float endDistanceCap; float shadowDepthBias; std::uint8_t unk10; };
union CommunityNavValue { CommunityFormID navMeshID; void* navMesh; };
struct CommunityPortalValue { CommunityNavValue nav; std::uint16_t triIndex; };
struct CommunityWorldValue { void* locationForm; CommunityPoint3 locPt; float zRot; };
struct CommunityPosRotValue { CommunityPoint3 pos; CommunityPoint3 rot; };
static_assert(sizeof(CommunityFormID)==4,"public form identity");
static_assert(sizeof(CommunityPoint3)==12,"public three coordinates");
static_assert(sizeof(CommunityLightValue)==20,"public light fields");
static_assert(sizeof(CommunityPortalValue)==16,"public portal union and triangle");
static_assert(sizeof(CommunityWorldValue)==24,"public world position");
static_assert(sizeof(CommunityPosRotValue)==24,"public position and rotation");
// ExtraValueStorageLayout: GUESS(medium) STANDIN; BSExtraData.h next link and virtual interface.
class ExtraValueStorageLayout { public: virtual ~ExtraValueStorageLayout();
// next: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
ExtraValueStorageLayout* next;
};
static_assert(sizeof(ExtraValueStorageLayout)==16, "represented public fields and base");
static_assert(offsetof(ExtraValueStorageLayout,next)==8, "declared member offset");
// CommunityExtra17cef0: GUESS(medium) STANDIN; ExtraLeveledItem.h public fields.
class CommunityExtra17cef0 : public ExtraValueStorageLayout { public: ~CommunityExtra17cef0();
// levItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
CommunityFormID levItem;
};
static_assert(sizeof(CommunityExtra17cef0)==24, "represented public fields and base");
static_assert(offsetof(CommunityExtra17cef0,levItem)==16, "declared member offset");
// CommunityExtra17d480: GUESS(medium) STANDIN; ExtraOutfitItem.h public fields.
class CommunityExtra17d480 : public ExtraValueStorageLayout { public: ~CommunityExtra17d480();
// id: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
CommunityFormID id;
};
static_assert(sizeof(CommunityExtra17d480)==24, "represented public fields and base");
static_assert(offsetof(CommunityExtra17d480,id)==16, "declared member offset");
// CommunityExtra17ddb0: GUESS(medium) STANDIN; ExtraUniqueID.h public fields.
class CommunityExtra17ddb0 : public ExtraValueStorageLayout { public: ~CommunityExtra17ddb0();
// baseID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
CommunityFormID baseID;
// uniqueID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
std::uint16_t uniqueID;
};
static_assert(sizeof(CommunityExtra17ddb0)==24, "represented public fields and base");
static_assert(offsetof(CommunityExtra17ddb0,baseID)==16, "declared member offset");
static_assert(offsetof(CommunityExtra17ddb0,uniqueID)==20, "declared member offset");
// CommunityExtra17cf50: GUESS(medium) STANDIN; ExtraLightData.h public fields.
class CommunityExtra17cf50 : public ExtraValueStorageLayout { public: ~CommunityExtra17cf50();
// data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
CommunityLightValue data;
};
static_assert(sizeof(CommunityExtra17cf50)==40, "represented public fields and base");
static_assert(offsetof(CommunityExtra17cf50,data)==16, "declared member offset");
// CommunityExtra17d350: GUESS(medium) STANDIN; ExtraNavMeshPortal.h public fields.
class CommunityExtra17d350 : public ExtraValueStorageLayout { public: ~CommunityExtra17d350();
// portal: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
CommunityPortalValue portal;
};
static_assert(sizeof(CommunityExtra17d350)==32, "represented public fields and base");
static_assert(offsetof(CommunityExtra17d350,portal)==16, "declared member offset");
// CommunityExtra17d520: GUESS(medium) STANDIN; ExtraPackageStartLocation.h public fields.
class CommunityExtra17d520 : public ExtraValueStorageLayout { public: ~CommunityExtra17d520();
// worldLoc: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
CommunityWorldValue worldLoc;
};
static_assert(sizeof(CommunityExtra17d520)==40, "represented public fields and base");
static_assert(offsetof(CommunityExtra17d520,worldLoc)==16, "declared member offset");
// CommunityExtra17dbf0: GUESS(medium) STANDIN; ExtraStartingPosition.h public fields.
class CommunityExtra17dbf0 : public ExtraValueStorageLayout { public: ~CommunityExtra17dbf0();
// startPosition: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
CommunityPosRotValue startPosition;
// location: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted public field.
void* location;
};
static_assert(sizeof(CommunityExtra17dbf0)==48, "represented public fields and base");
static_assert(offsetof(CommunityExtra17dbf0,startPosition)==16, "declared member offset");
static_assert(offsetof(CommunityExtra17dbf0,location)==40, "declared member offset");
}
