// Build: sse-steam-1-7-104
// Source exposure: community-headers (layout reconciled with target allocation sizes separately).
// Drafted by GPT-6.1 Sol; p175 box5 complete storage recovery.
// Labels: v2
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/A/ActiveEffect.h; MIT.
// ActiveEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActiveEffectLayout: GUESS(medium) STANDIN
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
#include "ActiveEffectReferenceEffectControllerLayout.h"
#include "BSSoundHandleLayout.h"
#include "LayoutValueTypes.h"

class BGSSaveFormBuffer;
namespace ResearchLayouts {
class Effect;
class MagicItem;
class MagicTarget;
class NiNode;
class ReferenceEffectLayout;
class TESBoundObject;
class ActiveEffectLayout {
public:
    void SaveGame(BGSSaveFormBuffer*);
    virtual ~ActiveEffectLayout();
    ActiveEffectReferenceEffectControllerLayout hitEffectController;
    BSSoundHandleLayout persistentSound;
    ActorHandle caster;
    NiPointer<NiNode> sourceNode;
    MagicItem* spell;
    Effect* effect;
    MagicTarget* target;
    TESBoundObject* source;
    BSSimpleList<ReferenceEffectLayout*>* hitEffects;
    MagicItem* displacementSpell;
    float elapsedSeconds;
    float duration;
    float magnitude;
    std::uint32_t flags;
    std::uint32_t conditionStatus;
    std::uint16_t usUniqueID;
    MagicSystem::CastingSource castingSource;
};
static_assert(sizeof(ActiveEffectLayout) == 144, "community represented size");
static_assert(offsetof(ActiveEffectLayout, hitEffectController) == 8, "hitEffectController offset");
static_assert(offsetof(ActiveEffectLayout, persistentSound) == 40, "persistentSound offset");
static_assert(offsetof(ActiveEffectLayout, caster) == 52, "caster offset");
static_assert(offsetof(ActiveEffectLayout, sourceNode) == 56, "sourceNode offset");
static_assert(offsetof(ActiveEffectLayout, spell) == 64, "spell offset");
static_assert(offsetof(ActiveEffectLayout, effect) == 72, "effect offset");
static_assert(offsetof(ActiveEffectLayout, target) == 80, "target offset");
static_assert(offsetof(ActiveEffectLayout, source) == 88, "source offset");
static_assert(offsetof(ActiveEffectLayout, hitEffects) == 96, "hitEffects offset");
static_assert(offsetof(ActiveEffectLayout, displacementSpell) == 104, "displacementSpell offset");
static_assert(offsetof(ActiveEffectLayout, elapsedSeconds) == 112, "elapsedSeconds offset");
static_assert(offsetof(ActiveEffectLayout, duration) == 116, "duration offset");
static_assert(offsetof(ActiveEffectLayout, magnitude) == 120, "magnitude offset");
static_assert(offsetof(ActiveEffectLayout, flags) == 124, "flags offset");
static_assert(offsetof(ActiveEffectLayout, conditionStatus) == 128, "conditionStatus offset");
static_assert(offsetof(ActiveEffectLayout, usUniqueID) == 132, "usUniqueID offset");
static_assert(offsetof(ActiveEffectLayout, castingSource) == 136, "castingSource offset");
}
