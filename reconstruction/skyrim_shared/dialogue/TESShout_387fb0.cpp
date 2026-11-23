// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x387fb0 TESShout::GetSpellForWord
// Adapted bodies: none
#include "TESShout_387fb0.h"

SpellItem* TESShout::GetSpellForWord(TESWordOfPower* a_word)
{
    if (!a_word) {
        return nullptr;
    }
    for (std::uint32_t i = 0; i < 3; ++i) {
        if (variations[i].word == a_word) {
            return variations[i].spell;
        }
    }
    return nullptr;
}
