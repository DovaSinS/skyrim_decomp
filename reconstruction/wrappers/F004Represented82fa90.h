// Build: sse-steam-1-7-104; RVA 0x82fa90; 52 bytes
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/represented-magic-wrapper-o2.json
// Source exposure: mixed (represented community declaration and independent target bindings).
// Drafted by tools/rootless_represented_wrapper_generate_v3.py (GPT-6.1 Sol).
// Labels: v2
// F004Represented82fa90, object: GUESS(low) STANDIN
// Declaration source: reconstruction/actors/CombatInventoryItemMagicLayout.h (renamed complete represented declaration).
// Fields and bases are unchanged; relative includes use copied declarations with original notices.
// Complete destructor remains external; only the compiler-emitted deleting wrapper is compared.
// Original ownership, specialization and complete destructor implementation are not claimed.
// Origin: {"family": "rootless-represented-renamed-deleting-wrapper", "template_digest": "5e3face50d9dfb3acbe9c9ac9b04a6fa595f98390cbf76de90000c80d7a3bcf0", "version": "3"}
// Build: sse-steam-1-7-104
// Code origin: declarations adapted from the pinned community header identified below.
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Drafted by GPT-6.1 Sol; p106 represented-layout recovery.
// Labels: v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/C/CombatInventoryItemMagic.h; MIT.
// CombatInventoryItemMagic: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Member spelling and base declarations adapt that source; unspecified field meanings remain unknown.
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
// F004Represented82fa90: GUESS(medium) STANDIN; represented layout type names
#pragma once
#include <cstdint>
#include <cstddef>
#include "../f004support/CombatInventoryItemLayout.h"

namespace ResearchLayouts {
class Effect;
class F004Represented82fa90 : public CombatInventoryItemLayout {
public:
    virtual ~F004Represented82fa90();
    float minRange;
    float maxRange;
    float tacticalDuration;
    float power;
    float currentAV;
    Effect* effect;
};
static_assert(sizeof(F004Represented82fa90) == 80, "community represented size");
static_assert(offsetof(F004Represented82fa90, minRange) == 48, "minRange offset");
static_assert(offsetof(F004Represented82fa90, maxRange) == 52, "maxRange offset");
static_assert(offsetof(F004Represented82fa90, tacticalDuration) == 56, "tacticalDuration offset");
static_assert(offsetof(F004Represented82fa90, power) == 60, "power offset");
static_assert(offsetof(F004Represented82fa90, currentAV) == 64, "currentAV offset");
static_assert(offsetof(F004Represented82fa90, effect) == 72, "effect offset");
}
