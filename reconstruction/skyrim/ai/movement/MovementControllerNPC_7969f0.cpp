// Source exposure: community-headers (names, layout), binary-analysis (offsets and slots from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x7969f0 MovementControllerNPC::Unk_0D
// Adapted bodies: none
#include "MovementControllerNPC_7969f0.h"

void MovementControllerNPC::Unk_0D()
{
    ScopedValue scope(0x50);
    if (unk1C5 != 1) {
        unk1C5 = 1;
        Notified* notified = Unk_03(&kClassType);
        if (notified) {
            notified->Notify();
        }
        MotionDriven* driven = &motionDriven;
        if (driven->Unk_06()) {
            driven->Unk_04();
        }
    }
}
