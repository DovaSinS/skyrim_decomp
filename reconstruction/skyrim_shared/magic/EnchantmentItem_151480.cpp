// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x151480 EnchantmentItem::Function151480
// Adapted bodies: none
#include "EnchantmentItem_151480.h"

// TestBit: GUESS(low); a flag-word bit test by bit index, taking the word by value.
inline bool TestBit(std::uint32_t a_flags, std::uint32_t a_bit)
{
    std::uint32_t shifted = a_flags >> a_bit;
    return (shifted & 1) != 0;
}

bool EnchantmentItem::Function151480(std::uint32_t mask) const
{
    for (std::uint32_t i = 0; i < effects.size; ++i) {
        Effect* effect = effects.data[i];
        if (effect && (effect->baseEffect->data.flags & mask) && !TestBit(effect->baseEffect->data.flags, 24)) {
            return true;
        }
    }
    return false;
}
