// Build: sse-steam-1-7-104; RVA 0x62dca0; 43 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented community and authorized sibling declarations and local binary analysis).
// Drafted by tools/deleting_layout_leaf_v10.py (GPT-6.1 Sol).
// Labels: v2
// QueueDeleteLayout, QueueCommonDelete0, QueueStaticDelete62dcd0, QueueDeleteLayout1, QueueCommonDelete1, QueueDeleteLayout2, QueueCommonDelete2, QueueDeleteLayout3, QueueCommonDelete3, QueueStaticDeletebc3bd0, QueueDeleteLayout4, QueueCommonDelete4, QueueStaticDelete116cb30, QueueDeleteLayout5, QueueCommonDelete5, QueueStaticDelete11f78f0, QueueDeleteLayout6, QueueCommonDelete6, QueueDeleteLayout7, QueueCommonDelete7: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Empty destructor bodies are inferred stand-ins for the compared leaf code only.
// Fields and inheritance come from the included represented layout, never an allocation-size array.
// No original field ownership or omitted methods are claimed; only scalar deleting code is compared.
// Shared structural template specializations do not recover original template arguments.
// The static objects request normal compiler emission; initialization and other methods are unassessed.
// Origin: {"family": "scalar-deleting-leaf", "template_digest": "fb604af7ede9f0fe7d0108dab05c3d9b198f6a70c2e1efc96ea627ecfc00f4a0", "version": "10"}
// Code origin: data declarations adapted from pinned public CommonLibSSE-NG headers. No implementation bodies reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT), include/RE/B/BSPointerHandle.h, BSTMessageQueue.h, BSExtraData.h; I/IUIMessageData.h, S/SyncQueueObj.h and the corresponding named handle-owner headers.
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
#include "QueueDeleteLayout.h"
namespace ResearchLayouts {
inline QueueDeleteLayout::~QueueDeleteLayout() {}
inline QueueCommonDelete0::~QueueCommonDelete0() {}
inline QueueStaticDelete62dcd0::~QueueStaticDelete62dcd0() {}
inline QueueDeleteLayout1::~QueueDeleteLayout1() {}
inline QueueCommonDelete1::~QueueCommonDelete1() {}
inline QueueDeleteLayout2::~QueueDeleteLayout2() {}
inline QueueCommonDelete2::~QueueCommonDelete2() {}
inline QueueDeleteLayout3::~QueueDeleteLayout3() {}
inline QueueCommonDelete3::~QueueCommonDelete3() {}
inline QueueStaticDeletebc3bd0::~QueueStaticDeletebc3bd0() {}
inline QueueDeleteLayout4::~QueueDeleteLayout4() {}
inline QueueCommonDelete4::~QueueCommonDelete4() {}
inline QueueStaticDelete116cb30::~QueueStaticDelete116cb30() {}
inline QueueDeleteLayout5::~QueueDeleteLayout5() {}
inline QueueCommonDelete5::~QueueCommonDelete5() {}
inline QueueStaticDelete11f78f0::~QueueStaticDelete11f78f0() {}
inline QueueDeleteLayout6::~QueueDeleteLayout6() {}
inline QueueCommonDelete6::~QueueCommonDelete6() {}
inline QueueDeleteLayout7::~QueueDeleteLayout7() {}
inline QueueCommonDelete7::~QueueCommonDelete7() {}
}
static_assert(sizeof(ResearchLayouts::QueueCommonDelete0) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::QueueStaticDelete62dcd0) == 96, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::QueueCommonDelete1) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::QueueCommonDelete2) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::QueueCommonDelete3) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::QueueStaticDeletebc3bd0) == 1056, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::QueueCommonDelete4) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::QueueStaticDelete116cb30) == 832, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::QueueCommonDelete5) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::QueueStaticDelete11f78f0) == 2080, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::QueueCommonDelete6) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::QueueCommonDelete7) == 16, "independently observed allocation size");
static ResearchLayouts::QueueCommonDelete0 object0;
static ResearchLayouts::QueueStaticDelete62dcd0 object1;
static ResearchLayouts::QueueCommonDelete1 object2;
static ResearchLayouts::QueueCommonDelete2 object3;
static ResearchLayouts::QueueCommonDelete3 object4;
static ResearchLayouts::QueueStaticDeletebc3bd0 object5;
static ResearchLayouts::QueueCommonDelete4 object6;
static ResearchLayouts::QueueStaticDelete116cb30 object7;
static ResearchLayouts::QueueCommonDelete5 object8;
static ResearchLayouts::QueueStaticDelete11f78f0 object9;
static ResearchLayouts::QueueCommonDelete6 object10;
static ResearchLayouts::QueueCommonDelete7 object11;
