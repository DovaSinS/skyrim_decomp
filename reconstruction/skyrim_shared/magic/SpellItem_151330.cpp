// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x151330 SpellItem::Function151330
// Adapted bodies: none
#include "SpellItem_151330.h"

bool SpellItem::Function151330() const
{
    for (std::uint32_t i = 0; i < effects.size; ++i) {
        Effect* effect = effects.data[i];
        if (effect && (effect->baseEffect->data.flagsHigh & 1)) {
            return true;
        }
    }
    return false;
}
