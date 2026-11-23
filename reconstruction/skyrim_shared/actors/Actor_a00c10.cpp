// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xa00c10 Actor::Functiona00c10
// Adapted bodies: none
#include "Actor_a00c10.h"

bool Actor::Functiona00c10(void* a_vm, std::uint32_t a_stackId, Actor* a_actor)
{
    if (*a_actor->Function6a51b0()) {
        return (*a_actor->Function6a51b0())->unk15();
    }
    return false;
}
