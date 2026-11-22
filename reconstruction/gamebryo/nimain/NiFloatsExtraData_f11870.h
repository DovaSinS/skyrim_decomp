// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// NiFloatsExtraData, GetValue, m_uiSize, m_pfValue: SYMBOLS(fo4-pdb); offsets read from the listing
// unk00: GUESS(low); the NiExtraData base, not modelled
#pragma once

#include <cstdint>
#include <cstddef>

class NiFloatsExtraData
{
public:
    float GetValue(std::uint32_t a_index) const;

    unsigned char unk00[0x18];
    std::uint32_t m_uiSize;
    std::uint32_t pad1C;
    float* m_pfValue;
};
static_assert(offsetof(NiFloatsExtraData, m_pfValue) == 0x20, "m_pfValue offset");
