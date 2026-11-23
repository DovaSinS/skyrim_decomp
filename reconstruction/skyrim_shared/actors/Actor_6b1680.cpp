// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6b1680 Actor::Function6b1680
// Adapted bodies: none
#include "Actor_6b1680.h"

bool Actor::Function6b1680()
{
    if (currentProcess && gActorProcessFlag) {
        return currentProcess->Function700eb0();
    }
    return false;
}
