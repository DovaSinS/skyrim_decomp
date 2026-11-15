// Build: sse-steam-1-7-104; RVA 0xf38370; 43 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (represented community and authorized sibling declarations and local binary analysis).
// Drafted by tools/deleting_layout_leaf_v9.py (GPT-6.1 Sol).
// Labels: v2
// BoundingVolumeDeleteLayout, BoxScalarDeleteLayout, CapsuleDeleteLayout, HalfSpaceDeleteLayout, SphereDeleteLayout: GUESS(medium) STANDIN; represented layout type names.
// object: GUESS(low)
// Empty destructor bodies are inferred stand-ins for the compared leaf code only.
// Fields and inheritance come from the included represented layout, never an allocation-size array.
// No original field ownership or omitted methods are claimed; only scalar deleting code is compared.
// Shared structural template specializations do not recover original template arguments.
// The static objects request normal compiler emission; initialization and other methods are unassessed.
// Origin: {"family": "scalar-deleting-leaf", "template_digest": "aee25b4e4f46996651837b36d8afcaba6e8fe2f37e89b0dc0bf310d23688a55e", "version": "9"}
// Code origin: value declarations adapted from CommonLibSSE-NG; bounding-volume, sphere, capsule and half-space declarations adapted from the authorized FNV sibling source. Box scalar declarations are originally inferred from target member accesses. No implementation bodies reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT), include/RE/N/NiPoint3.h, NiBound.h, NiPlane.h.
// Sibling source: momusdigital/fnv_decomp@91e1b6e8d8bb0f9a33e8cf88e77268757449e0a6 include/NiBoundingVolume.h
// Sibling source: momusdigital/fnv_decomp@91e1b6e8d8bb0f9a33e8cf88e77268757449e0a6 include/NiSphereBV.h
// Sibling source: momusdigital/fnv_decomp@91e1b6e8d8bb0f9a33e8cf88e77268757449e0a6 include/NiCapsuleBV.h
// Sibling source: momusdigital/fnv_decomp@91e1b6e8d8bb0f9a33e8cf88e77268757449e0a6 include/NiHalfSpaceBV.h
// The following MIT notice applies only to the adapted CommonLibSSE-NG value declarations, not the sibling declarations.
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
#include "BoundingVolumeDeleteLayout.h"
namespace ResearchLayouts {
inline BoundingVolumeDeleteLayout::~BoundingVolumeDeleteLayout() {}
inline BoxScalarDeleteLayout::~BoxScalarDeleteLayout() {}
inline CapsuleDeleteLayout::~CapsuleDeleteLayout() {}
inline HalfSpaceDeleteLayout::~HalfSpaceDeleteLayout() {}
inline SphereDeleteLayout::~SphereDeleteLayout() {}
}
static_assert(sizeof(ResearchLayouts::BoxScalarDeleteLayout) == 72, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::CapsuleDeleteLayout) == 64, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::HalfSpaceDeleteLayout) == 40, "independently observed allocation size");
static_assert(sizeof(ResearchLayouts::SphereDeleteLayout) == 24, "independently observed allocation size");
static ResearchLayouts::BoxScalarDeleteLayout object0;
static ResearchLayouts::CapsuleDeleteLayout object1;
static ResearchLayouts::HalfSpaceDeleteLayout object2;
static ResearchLayouts::SphereDeleteLayout object3;
