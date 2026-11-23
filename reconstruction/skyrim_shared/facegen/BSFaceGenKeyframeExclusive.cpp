// Source exposure: mixed (local binary analysis and public names).
// Code origin: existing leaf plus original reconstruction of keyframe accessors.
// Adapted bodies: none.
// Recipe: reconstruction/recipes/o2-fpfast.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x432500 BSFaceGenKeyframeExclusive::Unk_0D
// 0x4324b0 BSFaceGenKeyframeExclusive::Function4324b0
// 0x4324c0 BSFaceGenKeyframeExclusive::Function4324c0
// 0x4324d0 BSFaceGenKeyframeExclusive::Function4324d0
// 0x432570 BSFaceGenKeyframeExclusive::Function432570
// 0x4324e0 BSFaceGenKeyframeExclusive::Function4324e0
// 0x432550 BSFaceGenKeyframeExclusive::Function432550
#include "BSFaceGenKeyframeExclusive.h"

std::uint8_t BSFaceGenKeyframeExclusive::Unk_0D() const
{
    return 0x1;
}

float BSFaceGenKeyframeExclusive::Function4324b0() const
{
    return field14;
}

float BSFaceGenKeyframeExclusive::Function4324c0() const
{
    return field14;
}

std::uint8_t BSFaceGenKeyframeExclusive::Function4324d0() const
{
    return field10;
}

void BSFaceGenKeyframeExclusive::Function432570(std::uint8_t a_value)
{
    field10 = a_value;
}

bool BSFaceGenKeyframeExclusive::Function4324e0() const
{
    if (0.0f == field14) {
        return true;
    }
    return false;
}

bool BSFaceGenKeyframeExclusive::Function432550(float a_value)
{
    if (a_value != field14) {
        field14 = a_value;
        return true;
    }
    return false;
}
