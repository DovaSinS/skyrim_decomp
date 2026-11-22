// Source exposure: community-headers (names, layout), binary-analysis (offsets from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6f5f90 ActorProcess::GetWaitingforLipFile
// Adapted bodies: none
#include "ActorProcess_6f5f90.h"

bool ActorProcess::GetWaitingforLipFile() const
{
    if (high && high->lipState) {
        std::uint32_t state = high->lipState->flags & 0x70000000;
        if (state == 0x10000000 || state == 0x20000000) {
            return true;
        }
    }
    return false;
}
