// Build: sse-steam-1-7-104; RVA 0x17c280; 43 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented community and authorized sibling declarations and local binary analysis).
// Drafted by tools/deleting_layout_leaf_v10.py (GPT-6.1 Sol).
// Labels: v2
// HandleExtraDeleteLayout, HandleOwner17c280, HandleOwner17c2b0, HandleOwner17c830, HandleOwner17ca20, HandleOwner17ca50, HandleOwner17cca0, HandleOwner17cd30, HandleOwner17cdc0, HandleOwner17d420, HandleOwner17d450, HandleOwner17d7c0, HandleOwner17dbc0, HandleOwner18f610, HandleSyncRoot, HandleOwner78d9e0, HandleOwner904d50, HandleUIRoot, HandleOwner98d8a0: GUESS(medium) STANDIN; represented layout type names.
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
#include "HandleExtraDeleteLayout.h"
namespace ResearchLayouts {
inline HandleExtraDeleteLayout::~HandleExtraDeleteLayout() {}
inline HandleOwner17c280::~HandleOwner17c280() {}
inline HandleOwner17c2b0::~HandleOwner17c2b0() {}
inline HandleOwner17c830::~HandleOwner17c830() {}
inline HandleOwner17ca20::~HandleOwner17ca20() {}
inline HandleOwner17ca50::~HandleOwner17ca50() {}
inline HandleOwner17cca0::~HandleOwner17cca0() {}
inline HandleOwner17cd30::~HandleOwner17cd30() {}
inline HandleOwner17cdc0::~HandleOwner17cdc0() {}
inline HandleOwner17d420::~HandleOwner17d420() {}
inline HandleOwner17d450::~HandleOwner17d450() {}
inline HandleOwner17d7c0::~HandleOwner17d7c0() {}
inline HandleOwner17dbc0::~HandleOwner17dbc0() {}
inline HandleOwner18f610::~HandleOwner18f610() {}
inline HandleSyncRoot::~HandleSyncRoot() {}
inline HandleOwner78d9e0::~HandleOwner78d9e0() {}
inline HandleOwner904d50::~HandleOwner904d50() {}
inline HandleUIRoot::~HandleUIRoot() {}
inline HandleOwner98d8a0::~HandleOwner98d8a0() {}
}
static_assert(sizeof(ResearchLayouts::HandleOwner17c280) == 24, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::HandleOwner17c2b0) == 24, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::HandleOwner17c830) == 24, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::HandleOwner17ca20) == 24, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::HandleOwner17ca50) == 24, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::HandleOwner17cca0) == 24, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::HandleOwner17cd30) == 24, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::HandleOwner17cdc0) == 24, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::HandleOwner17d420) == 24, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::HandleOwner17d450) == 24, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::HandleOwner17d7c0) == 24, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::HandleOwner17dbc0) == 24, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::HandleOwner18f610) == 40, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::HandleOwner78d9e0) == 32, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::HandleOwner904d50) == 24, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::HandleOwner98d8a0) == 32, "independently observed allocation size");
static ResearchLayouts::HandleOwner17c280 object0;
static ResearchLayouts::HandleOwner17c2b0 object1;
static ResearchLayouts::HandleOwner17c830 object2;
static ResearchLayouts::HandleOwner17ca20 object3;
static ResearchLayouts::HandleOwner17ca50 object4;
static ResearchLayouts::HandleOwner17cca0 object5;
static ResearchLayouts::HandleOwner17cd30 object6;
static ResearchLayouts::HandleOwner17cdc0 object7;
static ResearchLayouts::HandleOwner17d420 object8;
static ResearchLayouts::HandleOwner17d450 object9;
static ResearchLayouts::HandleOwner17d7c0 object10;
static ResearchLayouts::HandleOwner17dbc0 object11;
static ResearchLayouts::HandleOwner18f610 object12;
static ResearchLayouts::HandleOwner78d9e0 object13;
static ResearchLayouts::HandleOwner904d50 object14;
static ResearchLayouts::HandleOwner98d8a0 object15;
