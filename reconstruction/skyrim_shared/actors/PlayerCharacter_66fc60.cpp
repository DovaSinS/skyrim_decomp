// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x66fc60 PlayerCharacter::Function66fc60
// Adapted bodies: none
#include "PlayerCharacter_66fc60.h"

FormLike* PlayerCharacter::Function66fc60(const std::uint32_t* a_hand)
{
    if (unkF8) {
        FormLike* form = nullptr;
        switch (*a_hand) {
        case 0:
            form = unkF8->GetEquippedLeftHand();
            break;
        case 1:
            form = unkF8->Function6eb4b0();
            break;
        default:
            return nullptr;
        }
        if (form && form->formType == 0x29) {
            return form;
        }
    }
    return nullptr;
}
