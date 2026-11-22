// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x431da0 BSFaceGenKeyframeMultiple::Unk_09
// Adapted bodies: none
#include "BSFaceGenKeyframeMultiple_431da0.h"

bool BSFaceGenKeyframeMultiple::Unk_09()
{
    for (std::uint32_t i = 0; i < count; ++i) {
        if (Unk_0E(i) && !(values[i] <= 0.0f)) {
            return false;
        }
    }
    return true;
}
