// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x5bca00 ActiveEffect::ForEachHitEffect
// Adapted bodies: none
#include "ActiveEffect_5bca00.h"

void ActiveEffect::ForEachHitEffect(ForEachHitEffectVisitor& a_visitor)
{
    BSContainer::ForEachResult result = BSContainer::ForEachResult::kContinue;
    for (SimpleListNode* node = hitEffects; node; node = node->next) {
        if (!node->next && !node->item) {
            break;
        }
        if (result != BSContainer::ForEachResult::kContinue) {
            break;
        }
        result = a_visitor(node->item);
    }
}
