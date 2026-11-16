// Build: sse-steam-1-7-104
// Source exposure: mixed (public complete data declarations and independent target root getter evidence).
// Labels: v2
// Code origin: public data declaration adaptation; root pointer offset8 independently recovered from RTTI-bound slot1 getter, no deletion-size inference.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/S/SkyObject.h; MIT.
// SkyObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SkyObjectRootStorageLayout: GUESS(medium) STANDIN
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
#include "LayoutValueTypes.h"
namespace ResearchLayouts {
class NiNode;
class SkyObjectRootStorageLayout {
public:
    virtual ~SkyObjectRootStorageLayout();
    virtual NiNode* GetRoot();
    NiPointer<NiNode> root;
};
static_assert(sizeof(SkyObjectRootStorageLayout)==16,"public complete SkyObject storage");
static_assert(offsetof(SkyObjectRootStorageLayout,root)==8,"independent RTTI-bound slot1 pointer load");
}
