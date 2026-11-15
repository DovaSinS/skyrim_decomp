// Build: sse-steam-1-7-104; RVA 0x17cef0; 43 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented community and authorized sibling declarations and local binary analysis).
// Drafted by tools/deleting_layout_leaf_v13.py (GPT-6.1 Sol).
// Labels: v2
// ExtraValueStorageLayout, CommunityExtra17cef0, CommunityExtra17cf50, CommunityExtra17d350, CommunityExtra17d480, CommunityExtra17d520, CommunityExtra17dbf0, CommunityExtra17ddb0: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Empty destructor bodies are inferred stand-ins for the compared leaf code only.
// Fields and inheritance come from the included represented layout, never an allocation-size array.
// No original field ownership or omitted methods are claimed; only scalar deleting code is compared.
// Shared structural template specializations do not recover original template arguments.
// The static objects request normal compiler emission; initialization and other methods are unassessed.
// Origin: {"family": "scalar-deleting-leaf", "template_digest": "4c61638e3d04464950ae0462af54e9ef246087c8574fb2918dd4022863f1129a", "version": "13"}
// Code origin: public data declarations and represented reference-count inheritance; no implementation bodies reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT), include/RE/B/BSIntrusiveRefCounted.h, BSTFreeList.h; S/SettingCollection.h, SimpleAllocMemoryPagePolicy.h; A/AttachLightHitEffectVisitor.h, ActorTargetCheck.h; F/FastTravelConfirmCallback.h; I/IFunction.h, IFuncCallQuery.h, IVirtualMachine.h, IMessageBoxCallback.h, IMemoryPagePolicy.h; D/DelayFunctor.h; B/BSAtomic.h.
// Declaration source: same pinned MIT CommonLibSSE-NG revision; BSExtraData.h, ExtraLeveledItem.h, ExtraOutfitItem.h, ExtraUniqueID.h, ExtraLightData.h, ExtraNavMeshPortal.h, ExtraPackageStartLocation.h, ExtraStartingPosition.h, NiPoint3.h and BSCoreTypes.h.
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
void operator delete(void*, unsigned __int64) noexcept;
#include "ExtraValueStorageLayout.h"
namespace ResearchLayouts {
inline ExtraValueStorageLayout::~ExtraValueStorageLayout() {}
inline CommunityExtra17cef0::~CommunityExtra17cef0() {}
inline CommunityExtra17cf50::~CommunityExtra17cf50() {}
inline CommunityExtra17d350::~CommunityExtra17d350() {}
inline CommunityExtra17d480::~CommunityExtra17d480() {}
inline CommunityExtra17d520::~CommunityExtra17d520() {}
inline CommunityExtra17dbf0::~CommunityExtra17dbf0() {}
inline CommunityExtra17ddb0::~CommunityExtra17ddb0() {}
}
static_assert(sizeof(ResearchLayouts::CommunityExtra17cef0) == 24, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityExtra17cf50) == 40, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityExtra17d350) == 32, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityExtra17d480) == 24, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityExtra17d520) == 40, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityExtra17dbf0) == 48, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityExtra17ddb0) == 24, "independently observed allocation size");
static ResearchLayouts::CommunityExtra17cef0 object0;
static ResearchLayouts::CommunityExtra17cf50 object1;
static ResearchLayouts::CommunityExtra17d350 object2;
static ResearchLayouts::CommunityExtra17d480 object3;
static ResearchLayouts::CommunityExtra17d520 object4;
static ResearchLayouts::CommunityExtra17dbf0 object5;
static ResearchLayouts::CommunityExtra17ddb0 object6;
