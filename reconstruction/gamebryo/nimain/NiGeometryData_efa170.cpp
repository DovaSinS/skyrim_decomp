// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xefa170 NiGeometryData::RegisterStreamables
// Adapted bodies: none
#include "NiGeometryData_efa170.h"

bool NiGeometryData::RegisterStreamables(NiStream& a_stream)
{
    if (!NiObject::RegisterStreamables(a_stream)) {
        return false;
    }
    if (additionalGeomData && !additionalGeomData->RegisterStreamables(a_stream)) {
        return false;
    }
    return true;
}
