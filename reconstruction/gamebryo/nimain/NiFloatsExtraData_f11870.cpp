// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xf11870 NiFloatsExtraData::GetValue
// Adapted bodies: none
#include "NiFloatsExtraData_f11870.h"

float NiFloatsExtraData::GetValue(std::uint32_t a_index) const
{
    if (a_index < m_uiSize) {
        return m_pfValue[a_index];
    }
    return 0.0f;
}
