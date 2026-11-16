// Build: sse-steam-1-7-104
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Drafted by GPT-6.1 Sol; p175 box5 complete storage recovery.
// Labels: v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/A/ActiveEffectReferenceEffectController.h; MIT.
// ActiveEffectReferenceEffectController: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActiveEffectReferenceEffectControllerLayout: GUESS(medium) STANDIN
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
#include "LayoutValueTypes.h"
#include "ReferenceEffectControllerLayout.h"

namespace ResearchLayouts {
class ActiveEffectLayout;
class ActiveEffectReferenceEffectControllerLayout : public ReferenceEffectControllerLayout {
public:
    virtual ~ActiveEffectReferenceEffectControllerLayout();
    ActiveEffectLayout* effect;
    ObjectRefHandle target;
    NiPoint3 windPoint;
};
static_assert(sizeof(ActiveEffectReferenceEffectControllerLayout) == 32, "community represented size");
static_assert(offsetof(ActiveEffectReferenceEffectControllerLayout, effect) == 8, "effect offset");
static_assert(offsetof(ActiveEffectReferenceEffectControllerLayout, target) == 16, "target offset");
static_assert(offsetof(ActiveEffectReferenceEffectControllerLayout, windPoint) == 20, "windPoint offset");
}
