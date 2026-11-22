// Source exposure: community-headers (names, layout), binary-analysis (offsets and slots from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x7963c0 MovementControllerNPC::Func10
// Adapted bodies: none
#include "MovementControllerNPC_7963c0.h"

void MovementControllerNPC::Func10(std::uint8_t a_flag)
{
    Sprinting* sprinting = Unk_03(IMovementSetSprinting::QClassType());
    if (sprinting) {
        sprinting->SetFlag(a_flag);
    }
}
