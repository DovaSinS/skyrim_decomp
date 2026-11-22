// Source exposure: binary-analysis (pinned image listing only).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x2e5ba0 Actor::GetShieldObjectSlot
// Adapted bodies: none
#include "Actor_2e5ba0.h"

std::uint32_t Actor::GetShieldObjectSlot()
{
    TESForm* base = baseForm;
    if (base && base->formType == 0x2B) {
        NpcBodyData* data = static_cast<TESNPC*>(base)->npcData;
        if (data) {
            return data->shieldSlot;
        }
    }
    return 0xFFFFFFFF;
}
