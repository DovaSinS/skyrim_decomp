// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xf11f20 NiFogProperty::NiFogProperty
// Adapted bodies: none
#include "NiFogProperty_f11f20.h"

NiFogProperty::NiFogProperty()
{
    m_uFlags = 0;
    m_fDepth = 1.0f;
    m_kNearColor = NiColor::BLACK;
    m_kFarColor = NiColor::BLACK;
}
