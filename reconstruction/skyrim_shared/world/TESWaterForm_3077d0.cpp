// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x3077d0 TESWaterForm::Activate
// Adapted bodies: TESWaterForm::Activate, fo4-private@1b765c70 src/Shared/TESForms/World/TESWaterForm.cpp:237, author-permission
#include "TESWaterForm_3077d0.h"

bool TESWaterForm::Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount)
{
    if (!contactSpell || !a_activatorRef) {
        return false;
    }
    MagicCaster* caster = a_activatorRef->GetMagicCaster(MagicSystem::CastingSource::kInstant);
    if (!caster) {
        return false;
    }
    caster->CastSpellImmediate(contactSpell, false, nullptr, 1.0f, true, 0.0f, nullptr);
    return true;
}
