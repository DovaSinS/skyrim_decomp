// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x6aefa0 Actor::IsMoving
// Adapted bodies: none
#include "Actor_6aefa0.h"

// kMovingSpeedThreshold: GUESS(low); a float constant in the image data, 5.0 locally
static const float kMovingSpeedThreshold = 5.0f;

bool Actor::IsMoving() const
{
    bool moving = false;
    if (movementController) {
        MotionGate* gate = movementController->unk03(kMotionGateKey);
        if (gate) {
            moving = gate->unk01() >= kMovingSpeedThreshold;
        }
    }
    return moving;
}
