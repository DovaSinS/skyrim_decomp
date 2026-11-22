// Source exposure: community-headers (names), binary-analysis (offsets and slots from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6ca1c0 Actor::Func117
// Adapted bodies: none
#include "Actor_6ca1c0.h"

std::uint32_t Actor::Func117()
{
    if (!IsDead(false)) {
        if (currentProcess) {
            WeaponLike** weapon = currentProcess->GetCurrentlyEquippedWeapon(false);
            if (weapon && *weapon) {
                return kTypeTable[(*weapon)->weaponType];
            }
        }
        return 1;
    }
    return 0;
}
