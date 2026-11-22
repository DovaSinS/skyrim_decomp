// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x2f0610 TESObjectREFR::SetAltered
// Adapted bodies: TESObjectREFR::SetAltered has the same shape as the sibling body below; written from the listing, declared out of caution
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESObjectREFR.cpp:289
#include "TESObjectREFR_2f0610.h"

// IsBitSet: GUESS(low); a flag-word bit test by bit index, taking the word by value.
inline bool IsBitSet(std::uint32_t a_flags, std::uint32_t a_bit)
{
    return ((a_flags >> a_bit) & 1) != 0;
}

// 0x2f0610 TESObjectREFR::SetAltered
void TESObjectREFR::SetAltered(bool a_set)
{
    if (!IsBitSet(formFlags, 14) && a_set) {
        TESObjectCELL* cell = GetSaveParentCell();
        if (cell) {
            cell->SetAltered(true);
        }
    }
    TESForm::SetAltered(a_set);
}
