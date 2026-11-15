// Build: sse-steam-1-7-104; RVA 0x1475c0; 43 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented community and authorized sibling declarations and local binary analysis).
// Drafted by tools/deleting_layout_leaf_v13.py (GPT-6.1 Sol).
// Labels: v2
// CommunityLeafStorageLayout, CommunityRef2857c0, CommunityRef2feba0, CommunityRef4726a0, CommunityRef4e2000, CommunityRef4e2ce0, CommunityRef4e3a50, CommunityHitVisitor, CommunityHitOwner, CommunityActorFilter, CommunityActorTarget, CommunityFree6bc1a0, CommunityMessageCallback, CommunityFastTravel, CommunityRefOwner9a7f60, CommunityRef9b2a20, CommunityFree9f0290, CommunityRefOwnera2acb0, CommunityReff22f30, CommunityRef1497090, CommunityPagePolicy, CommunitySimplePage, CommunityRef14aa3a0, CommunityFree14c8860, CommunityRef14c8960: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Empty destructor bodies are inferred stand-ins for the compared leaf code only.
// Fields and inheritance come from the included represented layout, never an allocation-size array.
// No original field ownership or omitted methods are claimed; only scalar deleting code is compared.
// Shared structural template specializations do not recover original template arguments.
// The static objects request normal compiler emission; initialization and other methods are unassessed.
// Origin: {"family": "scalar-deleting-leaf", "template_digest": "4c61638e3d04464950ae0462af54e9ef246087c8574fb2918dd4022863f1129a", "version": "13"}
// Code origin: public data declarations and represented reference-count inheritance; no implementation bodies reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT), include/RE/B/BSIntrusiveRefCounted.h, BSTFreeList.h; S/SettingCollection.h, SimpleAllocMemoryPagePolicy.h; A/AttachLightHitEffectVisitor.h, ActorTargetCheck.h; F/FastTravelConfirmCallback.h; I/IFunction.h, IFuncCallQuery.h, IVirtualMachine.h, IMessageBoxCallback.h, IMemoryPagePolicy.h; D/DelayFunctor.h; B/BSAtomic.h.
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
#include "CommunityLeafStorageLayout.h"
namespace ResearchLayouts {
inline CommunityLeafStorageLayout::~CommunityLeafStorageLayout() {}
inline CommunityRef2857c0::~CommunityRef2857c0() {}
inline CommunityRef2feba0::~CommunityRef2feba0() {}
inline CommunityRef4726a0::~CommunityRef4726a0() {}
inline CommunityRef4e2000::~CommunityRef4e2000() {}
inline CommunityRef4e2ce0::~CommunityRef4e2ce0() {}
inline CommunityRef4e3a50::~CommunityRef4e3a50() {}
inline CommunityHitVisitor::~CommunityHitVisitor() {}
inline CommunityHitOwner::~CommunityHitOwner() {}
inline CommunityActorFilter::~CommunityActorFilter() {}
inline CommunityActorTarget::~CommunityActorTarget() {}
inline CommunityFree6bc1a0::~CommunityFree6bc1a0() {}
inline CommunityMessageCallback::~CommunityMessageCallback() {}
inline CommunityFastTravel::~CommunityFastTravel() {}
inline CommunityRefOwner9a7f60::~CommunityRefOwner9a7f60() {}
inline CommunityRef9b2a20::~CommunityRef9b2a20() {}
inline CommunityFree9f0290::~CommunityFree9f0290() {}
inline CommunityRefOwnera2acb0::~CommunityRefOwnera2acb0() {}
inline CommunityReff22f30::~CommunityReff22f30() {}
inline CommunityRef1497090::~CommunityRef1497090() {}
inline CommunityPagePolicy::~CommunityPagePolicy() {}
inline CommunitySimplePage::~CommunitySimplePage() {}
inline CommunityRef14aa3a0::~CommunityRef14aa3a0() {}
inline CommunityFree14c8860::~CommunityFree14c8860() {}
inline CommunityRef14c8960::~CommunityRef14c8960() {}
}
static_assert(sizeof(ResearchLayouts::CommunityLeafStorageLayout) == 280, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityRef2857c0) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityRef2feba0) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityRef4726a0) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityRef4e2000) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityRef4e2ce0) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityRef4e3a50) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityHitOwner) == 32, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityActorTarget) == 32, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityFree6bc1a0) == 24, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityFastTravel) == 32, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityRefOwner9a7f60) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityRef9b2a20) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityFree9f0290) == 24, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityRefOwnera2acb0) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityReff22f30) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityRef1497090) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunitySimplePage) == 40, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityRef14aa3a0) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityFree14c8860) == 24, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CommunityRef14c8960) == 16, "independently observed allocation size");
static ResearchLayouts::CommunityLeafStorageLayout object0;
static ResearchLayouts::CommunityRef2857c0 object1;
static ResearchLayouts::CommunityRef2feba0 object2;
static ResearchLayouts::CommunityRef4726a0 object3;
static ResearchLayouts::CommunityRef4e2000 object4;
static ResearchLayouts::CommunityRef4e2ce0 object5;
static ResearchLayouts::CommunityRef4e3a50 object6;
static ResearchLayouts::CommunityHitOwner object7;
static ResearchLayouts::CommunityActorTarget object8;
static ResearchLayouts::CommunityFree6bc1a0 object9;
static ResearchLayouts::CommunityFastTravel object10;
static ResearchLayouts::CommunityRefOwner9a7f60 object11;
static ResearchLayouts::CommunityRef9b2a20 object12;
static ResearchLayouts::CommunityFree9f0290 object13;
static ResearchLayouts::CommunityRefOwnera2acb0 object14;
static ResearchLayouts::CommunityReff22f30 object15;
static ResearchLayouts::CommunityRef1497090 object16;
static ResearchLayouts::CommunitySimplePage object17;
static ResearchLayouts::CommunityRef14aa3a0 object18;
static ResearchLayouts::CommunityFree14c8860 object19;
static ResearchLayouts::CommunityRef14c8960 object20;
