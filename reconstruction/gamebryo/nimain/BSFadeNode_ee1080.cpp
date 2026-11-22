// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xee1080 BSFadeNode::HasActiveControllerFlag
// Adapted bodies: none
#include "BSFadeNode_ee1080.h"

bool BSFadeNode::HasActiveControllerFlag() const
{
    bool found = false;
    for (NiTimeController* c = controllers; c; c = c->next) {
        if (found) {
            break;
        }
        found = (c->flagsHigh & 1) != 0;
    }
    return found;
}
