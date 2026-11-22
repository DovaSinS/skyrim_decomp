// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x151eba0 BSShaderAccumulator::FinishAccumulatingAppendWaterFogPasses
// Adapted bodies: none
#include "BSShaderAccumulator_151eba0.h"

bool BSShaderAccumulator::FinishAccumulatingAppendWaterFogPasses(void* a_unused, PassListOwner* a_owner)
{
    if (unknown129) {
        PassNode** list = a_owner->GetWaterFogPasses();
        if (list) {
            for (PassNode* node = *list; node; node = node->next) {
                batchRenderer->AppendPass(node, node->passCount);
            }
        }
    }
    return true;
}
