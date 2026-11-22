// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6aeff0 Character::GetTurning
// Adapted bodies: none
#include "Character_6aeff0.h"

#include <cmath>

// kTurningThreshold: GUESS(low); a float constant in the image data, one degree in radians locally
static const float kTurningThreshold = 0.017453292f;

bool Character::GetTurning() const
{
    bool turning = false;
    if (movementController) {
        MotionGate* gate = movementController->unk03(kMotionGateKey);
        if (gate) {
            turning = std::fabs(gate->unk03()->angularSpeed) >= kTurningThreshold;
        }
    }
    return turning;
}
