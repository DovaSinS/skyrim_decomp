// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x431ad0 BSFaceGenKeyframeMultiple::Func4
// Adapted bodies: none
#include "BSFaceGenKeyframeMultiple_431ad0.h"

void BSFaceGenKeyframeMultiple::Func4(bool a_flag)
{
    if (!isUpdated) {
        if (timer != 0.0f) {
            timer = 0.0f;
        }
        Unk_0F(count, a_flag);
        isUpdated = a_flag;
    }
}
