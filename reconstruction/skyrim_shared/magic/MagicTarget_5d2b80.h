// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MagicTarget, MagicTarget::Function5d2b80: GUESS(low)
// MagicTarget::GetActiveEffectList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 07 per NG
// ActiveEffect, ActiveEffect::EvaluateConditions, ActiveEffect::spell, ActiveEffect::effect, ActiveEffect::displacementSpell: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); offsets and slot per NG, partial layout
// ActiveEffectNode: STANDIN GUESS(low); list node of the active effect list as the code walks it
#pragma once

#include <cstdint>
#include <cstddef>

class MagicItem;
class Effect;

class ActiveEffect
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void EvaluateConditions(float a_delta, bool a_forceUpdate);

    std::uint8_t pad08[0x38];
    MagicItem* spell;
    Effect* effect;
    std::uint8_t pad50[0x18];
    MagicItem* displacementSpell;
};

struct ActiveEffectNode
{
    ActiveEffect* item;
    ActiveEffectNode* next;
};

class MagicTarget
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual ActiveEffectNode* GetActiveEffectList();

    void Function5d2b80(MagicItem* a_displacementSpell, MagicItem* a_spell);
};
