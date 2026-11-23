// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x755620 PlayerCharacter::Function755620
// Adapted bodies: none
#include "PlayerCharacter_755620.h"

void PlayerCharacter::Function755620(std::uint8_t a_flags)
{
    if (a_flags & 1) {
        unkBEB &= ~4;
    }
    if (a_flags & 2) {
        unkBEB &= ~8;
    }
}
