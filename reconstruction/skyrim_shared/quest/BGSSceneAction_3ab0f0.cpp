// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x3ab0f0 BGSSceneAction::Function3ab0f0
// Adapted bodies: none
#include "BGSSceneAction_3ab0f0.h"

bool BGSSceneAction::Function3ab0f0(std::uint32_t a_phase)
{
    bool result = false;
    if (a_phase >= unk0C) {
        if (a_phase <= unk0E) {
            result = true;
        }
    }
    return result;
}
