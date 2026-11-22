// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1df590 TESBoundObject::GetFormAsBipedModel
// Adapted bodies: none
#include "TESBoundObject_1df590.h"

// only armour forms carry a biped model component
TESBipedModelForm* TESBoundObject::GetFormAsBipedModel(TESForm* form)
{
    const std::uint8_t kArmor = 0x1A;
    if (form && form->formType == kArmor)
        return &static_cast<TESObjectARMO*>(form)->bipedComponent;
    return nullptr;
}
