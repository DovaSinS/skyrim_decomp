// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1db3d0 BGSPerkRankArray::VisitPerks
// Adapted bodies: none
#include "BGSPerkRankArray_1db3d0.h"

void BGSPerkRankArray::VisitPerks(PerkRankVisitor* a_visitor)
{
    if (perks) {
        int control = 1;
        for (std::uint32_t i = 0; i < perkCount && control == 1; ++i) {
            control = a_visitor->Visit(&perks[i]);
        }
    }
}
