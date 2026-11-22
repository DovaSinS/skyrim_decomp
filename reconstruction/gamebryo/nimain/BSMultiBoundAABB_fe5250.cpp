// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xfe5250 BSMultiBoundAABB::CopyMembers
// Adapted bodies: none
#include "BSMultiBoundAABB_fe5250.h"

void BSMultiBoundAABB::CopyMembers(BSMultiBoundAABB* a_dest, NiCloningProcess& a_process)
{
    BSMultiBoundShape::CopyMembers(a_dest, a_process);
    a_dest->SetCenter(Center);
    a_dest->Radius = Radius;
}
