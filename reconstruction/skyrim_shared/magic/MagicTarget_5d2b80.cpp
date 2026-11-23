// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x5d2b80 MagicTarget::Function5d2b80
// Adapted bodies: none
#include "MagicTarget_5d2b80.h"

void MagicTarget::Function5d2b80(MagicItem* a_displacementSpell, MagicItem* a_spell)
{
    ActiveEffectNode* node = GetActiveEffectList();
    while (node && (node->next || node->item)) {
        ActiveEffect* effect = node->item;
        node = node->next;
        if (effect && effect->spell == a_spell) {
            effect->displacementSpell = a_displacementSpell;
            effect->EvaluateConditions(0.0f, true);
        }
    }
}
