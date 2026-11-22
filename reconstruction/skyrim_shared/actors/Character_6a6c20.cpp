// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6a6c20 Character::GetLookAtTarget
// Adapted bodies: none
#include "Character_6a6c20.h"

bool Character::GetLookAtTarget(NiPoint3& a_target) const
{
    bool found = false;
    if (movementController) {
        MotionGate* gate = movementController->unk03(kLookAtGateKey);
        if (gate) {
            LookAtRecord* record = gate->unk01();
            if (record->state - 2 <= 1) {
                a_target.x = record->point.x;
                a_target.y = record->point.y;
                a_target.z = record->point.z;
                found = true;
            }
        }
    }
    return found;
}
