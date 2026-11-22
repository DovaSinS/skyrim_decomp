// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x22b5a0 InventoryChanges::GetWornMask
// Adapted bodies: none
#include "InventoryChanges_22b5a0.h"

std::uint32_t InventoryChanges::GetWornMask()
{
    InventoryUtils::GetWornMaskVisitor visitor;
    VisitWornItems(visitor);
    return visitor.mask;
}
