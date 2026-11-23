// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x387df0 TESShout::GetLastUnlockedIndex
// Adapted bodies: none
#include "TESShout_387df0.h"

int TESShout::GetLastUnlockedIndex()
{
    int i = 0;
    const Variation* variation = variations;
    for (; i < 3; ++i, ++variation) {
        const TESWordOfPower* word = variation->word;
        if (word && !(word->flagsHigh & 1)) {
            break;
        }
    }
    return i - 1;
}
