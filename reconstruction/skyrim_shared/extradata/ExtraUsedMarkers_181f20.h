// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// ExtraUsedMarkers::Function181f20, ExtraUsedMarkers::unk10, ExtraUsedMarkers::unk20, ExtraUsedMarkers_Entry: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct ExtraUsedMarkers_Entry
{
    std::uint32_t unk00;
    std::uint32_t unk04;
    std::uint32_t unk08;
};

class ExtraUsedMarkers
{
public:
    bool Function181f20(std::uint32_t a_value);

    std::uint8_t pad00[0x10];
    ExtraUsedMarkers_Entry* unk10;
    std::uint8_t pad18[0x8];
    std::uint32_t unk20;
};
