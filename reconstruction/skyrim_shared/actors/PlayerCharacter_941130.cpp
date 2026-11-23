// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x941130 PlayerCharacter::Function941130
// Adapted bodies: none
#include "PlayerCharacter_941130.h"

void PlayerCharacter::Function941130(InventoryChanges* a_changes)
{
    if (a_changes) {
        PlayerWornItemVisitor visitor(this);
        a_changes->VisitWornItems(visitor);
    }
}
