// Source exposure: community-headers (names), binary-analysis (offsets and slots from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6acad0 Actor::OwnerIsNPC
// Adapted bodies: none
#include "Actor_6acad0.h"

bool Actor::OwnerIsNPC() const
{
    if (currentProcess) {
        OwnerCache* cached = currentProcess->cache;
        if (cached && !TestBitClear(cached->flagsB, 25)) {
            return TestBit(cached->flagsA, 1);
        }
    }
    return CalculateCachedOwnerIsNPC();
}
