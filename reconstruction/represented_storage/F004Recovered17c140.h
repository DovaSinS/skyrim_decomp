// Build: sse-steam-1-7-104; RVA 0x17c140; 52 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (public typed storage and independent target RTTI/call operands).
// Drafted by GPT-6.1 Sol; complete represented storage deleting wrapper.
// Labels: v2
// Code origin: original wrapper emission unit; public data declarations carry their notices below.
// F004Recovered17c140, object: GUESS(low) STANDIN
// ExtraActivateRefChildren: EXE_RTTI
// Full represented storage follows pinned community fields/bases. Virtual method sets and original source identity are unclaimed.
// Destructor remains external. Only the emitted deleting wrapper is compared; allocation size is a consistency check, never layout evidence.
// Independent primary owner vftable slot 0 binds this wrapper, including nonzero destructor slots where present.
// Build: sse-steam-1-7-104
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Drafted by GPT-6.1 Sol; p175 box5 complete storage recovery.
// Labels: v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/E/ExtraActivateRefChildren.h; MIT.
// ExtraActivateRefChildren: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// F004Recovered17c140: GUESS(medium) STANDIN
// Member spelling and base declarations adapt that source; unspecified field meanings remain unknown.
// Code origin: public data declarations adapted to storage-only stand-ins; no method body reused.
// Omitted methods are not reconstructed. Pointee types are declarations only.
// Explicit padding fields are omitted; compiler alignment must satisfy every size and field assertion.
// Size assertions establish represented layout only, never a comparator match.
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
#include "BSExtraDataLayout.h"
#include "LayoutValueTypes.h"

namespace ResearchLayouts {
class REF_ACTIVATE_DATA;
class F004Recovered17c140 : public BSExtraDataLayout {
public:
    virtual ~F004Recovered17c140();
    BSSimpleList<REF_ACTIVATE_DATA*> children;
    float activateChildrenTimer;
};
static_assert(sizeof(F004Recovered17c140) == 40, "community represented size");
static_assert(offsetof(F004Recovered17c140, children) == 16, "children offset");
static_assert(offsetof(F004Recovered17c140, activateChildrenTimer) == 32, "activateChildrenTimer offset");
}
