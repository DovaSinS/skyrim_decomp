// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x728410 ActorProcess::Function728410
// Adapted bodies: none
#include "ActorProcess_728410.h"

void ActorProcess::Function728410(std::uint8_t a_entryPoint, PerkEntryVisitor& a_visitor)
{
    if (middleHigh && middleHigh->perkEntries && a_entryPoint < kPerkEntryPointCount) {
        PerkEntryArray& entries = middleHigh->perkEntries[a_entryPoint];
        if (entries.size != 0) {
            BGSPerkEntry** end = entries.data + entries.size;
            for (BGSPerkEntry** it = entries.data; it != end; ++it) {
                if (a_visitor.Visit(*it) != ForEachResult::kContinue) {
                    break;
                }
            }
        }
    }
}
