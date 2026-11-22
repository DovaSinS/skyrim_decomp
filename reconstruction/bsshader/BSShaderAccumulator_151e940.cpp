// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x151e940 BSShaderAccumulator::FinishAccumulatingAppendLitPassesUngrouped
// Adapted bodies: none
#include "BSShaderAccumulator_151e940.h"

bool BSShaderAccumulator::FinishAccumulatingAppendLitPassesUngrouped(void* a_arg, PassListOwner* a_owner)
{
    PassNode** list = a_owner->GetPassList(a_arg, renderMode, this);
    a_owner->unknown80 = gPassListFlags;
    if (list) {
        for (PassNode* node = *list; node; node = node->next) {
            if (node->passCount) {
                batchRenderer->AppendPass(node, node->passCount);
            }
        }
    }
    return true;
}
