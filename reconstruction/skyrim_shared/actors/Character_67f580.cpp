// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x67f580 Character::GetCurrentPackageTarget
// Adapted bodies: none
#include "Character_67f580.h"

ObjectRefHandle& Character::GetCurrentPackageTarget(ObjectRefHandle& a_handle)
{
    a_handle = kNullHandle;
    if (currentProcess) {
        a_handle = currentProcess->packageTarget;
    }
    return a_handle;
}
