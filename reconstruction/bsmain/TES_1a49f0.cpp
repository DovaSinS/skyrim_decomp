// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1a49f0 TES::GetDeadCountOf
// Adapted bodies: none
#include "TES_1a49f0.h"

std::uint16_t TES::GetDeadCountOf(const TESNPC* a_npc) const
{
    for (const DeadCountNode* node = &deadCount; node; node = node->next) {
        const DeadCountEntry* entry = node->item;
        if (!entry) {
            break;
        }
        if (entry->npc == a_npc) {
            return entry->count;
        }
    }
    return 0;
}
