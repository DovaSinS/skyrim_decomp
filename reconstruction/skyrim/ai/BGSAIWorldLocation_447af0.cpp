// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x447af0 BGSAIWorldLocation::IsValid
// Adapted bodies: none
#include "BGSAIWorldLocation_447af0.h"

// 0x447af0 BGSAIWorldLocation::IsValid
bool BGSAIWorldLocation::IsValid()
{
    if (unk09()) {
        return true;
    }
    if (unk08()) {
        return true;
    }
    return false;
}
