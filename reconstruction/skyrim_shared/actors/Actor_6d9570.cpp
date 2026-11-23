// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6d9570 Actor::GetSoulLevel
// Adapted bodies: none
#include "Actor_6d9570.h"

std::uint32_t Actor::GetSoulLevel()
{
    if (currentProcess && !currentProcess->Function728580()) {
        std::uint8_t flag = Function6acad0();
        return TESSoulGem::GetSoulLevel(GetLevel(), flag);
    }
    return 0;
}
