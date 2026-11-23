// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6a4f80 Character::Function6a4f80
// Adapted bodies: none
#include "Character_6a4f80.h"

bool Character::Function6a4f80()
{
    if ((unkC8 & 0x1c0000) == 0xc0000 && holder150) {
        ControllerInterface* controller = holder150->unk18(&interfaceId324f0b0);
        if (controller && !controller->unk30()) {
            return true;
        }
    }
    return false;
}
