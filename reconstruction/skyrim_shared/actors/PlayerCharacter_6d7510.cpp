// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6d7510 PlayerCharacter::Function6d7510
// Adapted bodies: none
#include "PlayerCharacter_6d7510.h"

void PlayerCharacter::Function6d7510(void* a_arg)
{
    for (std::uint32_t i = 0; i < 4; ++i) {
        if (unk1A8[i]) {
            unk1A8[i]->Function5c17e0(a_arg);
        }
    }
}
