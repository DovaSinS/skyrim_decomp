// Build: sse-steam-1-7-104; RVA 0x40bc50; 52 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (public typed storage and independent target RTTI/call operands).
// Drafted by GPT-6.1 Sol; complete represented storage deleting wrapper.
// Labels: v2
// Code origin: original wrapper emission unit; public data declarations carry their notices below.
// F004Recovered40bc50, object: GUESS(low) STANDIN
// Atmosphere: EXE_RTTI
// Full represented storage follows pinned community fields/bases. Virtual method sets and original source identity are unclaimed.
// Destructor remains external. Only the emitted deleting wrapper is compared; allocation size is a consistency check, never layout evidence.
// Independent primary owner vftable slot 0 binds this wrapper, including nonzero destructor slots where present.
// Build: sse-steam-1-7-104
// Source exposure: mixed (public complete data declarations and independent target root getter evidence).
// Labels: v2
// Code origin: public data declaration adaptation; root pointer offset8 independently recovered from RTTI-bound slot1 getter, no deletion-size inference.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/A/Atmosphere.h; MIT.
// Atmosphere: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// F004Recovered40bc50: GUESS(medium) STANDIN
// Public SkyObject header's root offset0x10 comment conflicts with its own16-byte size. Binary primary slot1 getter for SkyObject, Atmosphere and Sun independently loads a pointer at this+8. Typed root source is public NiPointer<NiNode>; offset8 is binary evidence, not an assumed padding correction.
// Complete data storage only; later virtual methods, lifetime behavior and original source identity unclaimed. Explicit public padding omitted; all size/field assertions required. Layout agreement alone is not a function match.
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
#pragma once
#include <cstdint>
#include <cstddef>
#include "LayoutValueTypes.h"
#include "SkyObjectRootStorageLayout.h"

namespace ResearchLayouts {
class BSFogProperty;
class BSTriShape;
class NiNode;
class F004Recovered40bc50 : public SkyObjectRootStorageLayout {
public:
    virtual ~F004Recovered40bc50();
    NiPointer<BSTriShape> atmosphere;
    NiPointer<BSFogProperty> fog;
    NiPointer<NiNode> skyQuadNode;
    NiPointer<BSTriShape> skyQuad;
    bool updateFogDistance;
};
static_assert(sizeof(F004Recovered40bc50) == 56, "community represented size");
static_assert(offsetof(F004Recovered40bc50, atmosphere) == 16, "atmosphere offset");
static_assert(offsetof(F004Recovered40bc50, fog) == 24, "fog offset");
static_assert(offsetof(F004Recovered40bc50, skyQuadNode) == 32, "skyQuadNode offset");
static_assert(offsetof(F004Recovered40bc50, skyQuad) == 40, "skyQuad offset");
static_assert(offsetof(F004Recovered40bc50, updateFogDistance) == 48, "updateFogDistance offset");
}
