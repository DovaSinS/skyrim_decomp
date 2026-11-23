// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x756ab0 PlayerCharacter::Function756ab0
// Adapted bodies: none
#include "PlayerCharacter_756ab0.h"

void PlayerCharacter::Function756ab0(bool a_flag)
{
    if (IsInCombat() && a_flag) {
        UseSkill(0xF, g_skillPoints756ab0, nullptr, 0);
    }
}
