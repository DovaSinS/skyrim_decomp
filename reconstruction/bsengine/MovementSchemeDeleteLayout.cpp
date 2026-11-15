// Build: sse-steam-1-7-104; RVA 0x11fda60; 43 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented community and authorized sibling declarations and local binary analysis).
// Drafted by tools/deleting_layout_leaf_v9.py (GPT-6.1 Sol).
// Labels: v2
// MovementSchemeDeleteLayout, MovementSchemeDeleteLayout1, MovementSchemeDeleteLayout2, MovementSchemeDeleteLayout3: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Empty destructor bodies are inferred stand-ins for the compared leaf code only.
// Fields and inheritance come from the included represented layout, never an allocation-size array.
// No original field ownership or omitted methods are claimed; only scalar deleting code is compared.
// Shared structural template specializations do not recover original template arguments.
// The static objects request normal compiler emission; initialization and other methods are unassessed.
// Origin: {"family": "scalar-deleting-leaf", "template_digest": "aee25b4e4f46996651837b36d8afcaba6e8fe2f37e89b0dc0bf310d23688a55e", "version": "9"}
// Code origin: interface and reference-count declarations adapted from the pinned public headers; derived scalar declarations originally inferred from target member accesses. No implementation bodies reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT), include/RE/B/BSTEvent.h and BSIntrusiveRefCounted.h.
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
#include "MovementSchemeDeleteLayout.h"
namespace ResearchLayouts {
inline MovementSchemeDeleteLayout::~MovementSchemeDeleteLayout() {}
inline MovementSchemeDeleteLayout1::~MovementSchemeDeleteLayout1() {}
inline MovementSchemeDeleteLayout2::~MovementSchemeDeleteLayout2() {}
inline MovementSchemeDeleteLayout3::~MovementSchemeDeleteLayout3() {}
}
static_assert(sizeof(ResearchLayouts::MovementSchemeDeleteLayout) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::MovementSchemeDeleteLayout1) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::MovementSchemeDeleteLayout2) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::MovementSchemeDeleteLayout) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::MovementSchemeDeleteLayout1) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::MovementSchemeDeleteLayout2) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::MovementSchemeDeleteLayout) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::MovementSchemeDeleteLayout1) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::MovementSchemeDeleteLayout2) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::MovementSchemeDeleteLayout3) == 16, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::MovementSchemeDeleteLayout3) == 16, "independently observed allocation size");
static ResearchLayouts::MovementSchemeDeleteLayout object0;
static ResearchLayouts::MovementSchemeDeleteLayout1 object1;
static ResearchLayouts::MovementSchemeDeleteLayout2 object2;
static ResearchLayouts::MovementSchemeDeleteLayout3 object3;
