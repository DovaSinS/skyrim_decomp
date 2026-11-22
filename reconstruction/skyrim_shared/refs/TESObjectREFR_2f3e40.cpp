// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x2f3e40 TESObjectREFR::GetSaveParentCell
// Adapted bodies: none
#include "TESObjectREFR_2f3e40.h"

// 0x2f3e40 TESObjectREFR::GetSaveParentCell
TESObjectCELL* TESObjectREFR::GetSaveParentCell()
{
    TESObjectCELL* cell = parentCell;
    if (formFlags & 0x4400) {
        if (!cell || !(cell->cellFlags & 1)) {
            return extraList.GetPersistentCell();
        }
    }
    return cell;
}
