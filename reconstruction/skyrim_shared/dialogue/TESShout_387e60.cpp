// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x387e60 TESShout::GetFirstCompleteIndex
// Adapted bodies: none
#include "TESShout_387e60.h"

int TESShout::GetFirstCompleteIndex()
{
    int count = 0;
    for (std::int64_t i = 0; i < 3; ++i) {
        const Variation* variation = &variations[i];
        if (variation->word && variation->spell) {
            break;
        }
        ++count;
    }
    return count;
}
