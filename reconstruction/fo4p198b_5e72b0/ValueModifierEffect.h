// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: authorized sibling and community declarations
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x5e72b0, 46 bytes: ValueModifierEffect::Start
// ValueModifierEffect::Start: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ValueModifierEffect.cpp:138
// ActiveEffect, ValueModifierEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/A/ActiveEffect.h and include/RE/V/ValueModifierEffect.h
// names: GUESS(low); signatures remain provisional
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
class Actor; class MagicTarget; class TESObjectREFR; class NiPoint3; class BGSSaveFormBuffer; class BGSLoadFormBuffer; class BSFixedString; class NiNode;
class ActiveEffect {
public:
    virtual void AdjustForPerks(Actor*, MagicTarget*);
    virtual void OnAdd(MagicTarget*);
    virtual void OnRemove();
    virtual TESObjectREFR* GetVisualsTarget();
    virtual void Update(float);
    virtual void EvaluateConditions(float, bool);
    virtual bool IsCausingHealthDamage();
    virtual void SetLocation(const NiPoint3&);
    virtual void SaveGame(BGSSaveFormBuffer*);
    virtual void LoadGame(BGSLoadFormBuffer*);
    virtual void FinishLoadGame(BGSLoadFormBuffer*);
    virtual void Revert(BGSLoadFormBuffer*);
    virtual std::int32_t Compare(ActiveEffect*);
    virtual void HandleEvent(const BSFixedString&);
    virtual void SwitchAttachedRoot(NiNode*,NiNode*);
    virtual void HandleQueuedStart();
    virtual bool ShouldDispelOnDeath() const;
    virtual bool GetAllowMultipleCastingSourceStacking();
    virtual void ClearTargetImpl();
    virtual ~ActiveEffect();
    virtual void Start();
    virtual void Finish();
    virtual bool CanFinish();
    virtual bool CheckCustomSkillUseConditions() const;
    virtual float GetCustomSkillUseMagnitudeMultiplier(float) const;
};
class ValueModifierEffect : public ActiveEffect {
public:
    void Start() override;
    virtual void SetActorValue(std::uint32_t);
    virtual bool ShouldModifyOnStart();
    virtual void ModifyOnStart();
};
