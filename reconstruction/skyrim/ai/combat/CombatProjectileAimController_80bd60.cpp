// Source exposure: mixed (CrashLogger and FO4 layout names; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x80bd60 CombatProjectileAimController::Function80bd60
// Adapted bodies: none
#include "CombatProjectileAimController_80bd60.h"

bool CombatProjectileAimController::Function80bd60(void* a_arg)
{
    NiPoint3 offset;
    offset.x = targetLocation.x - fireLocation.x;
    offset.y = targetLocation.y - fireLocation.y;
    offset.z = targetLocation.z - fireLocation.z;
    return Slot05(a_arg, offset);
}
