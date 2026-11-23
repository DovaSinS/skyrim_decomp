// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x5d2710 MagicTarget::Function5d2710
// Adapted bodies: none
#include "MagicTarget_5d2710.h"

void MagicTarget::Function5d2710()
{
    ActiveEffectNode* node = GetActiveEffectList();
    while (node) {
        ActiveEffect* effect = node->item;
        node = node->next;
        if (effect) {
            effect->EvaluateConditions(0.0f, true);
        }
    }
}
