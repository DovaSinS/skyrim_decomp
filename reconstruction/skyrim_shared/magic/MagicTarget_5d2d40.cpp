// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x5d2d40 MagicTarget::Function5d2d40
// Adapted bodies: none
#include "MagicTarget_5d2d40.h"

ActiveEffect* MagicTarget::Function5d2d40(MagicItem* a_spell, Effect* a_effect)
{
    ActiveEffect* found = nullptr;
    ActiveEffectNode* node = GetActiveEffectList();
    while (!found && node && node->item) {
        ActiveEffect* effect = node->item;
        if (effect->spell == a_spell && effect->effect == a_effect) {
            found = effect;
        }
        node = node->next;
    }
    return found;
}
