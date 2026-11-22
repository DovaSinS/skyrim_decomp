// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1002480 BSMultiBoundAABB::CopyMembers
// Adapted bodies: none
#include "BSMultiBoundAABB_1002480.h"

void BSMultiBoundAABB::CopyMembers(BSMultiBoundAABB* a_dest, NiCloningProcess& a_process)
{
    BSMultiBoundShape::CopyMembers(a_dest, a_process);
    a_dest->PointA.x = PointA.x;
    a_dest->PointA.y = PointA.y;
    a_dest->PointA.z = PointA.z;
    a_dest->PointB.x = PointB.x;
    a_dest->PointB.y = PointB.y;
    a_dest->PointB.z = PointB.z;
    a_dest->Radius = Radius;
}
