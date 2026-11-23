// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TESTopic, TESTopic::Function3efe60: GUESS(low)
// TESTopic::unk38, TESTopic_Owner, TESTopic_Owner::flags: GUESS(low); stand-ins for an object reached through a pointer at offset 0x38
#pragma once

#include <cstdint>
#include <cstddef>

class TESTopic_Owner
{
public:
    std::uint8_t pad00[0x20];
    std::uint32_t flags;
};

class TESTopic
{
public:
    bool Function3efe60();

    std::uint8_t pad00[0x38];
    TESTopic_Owner* unk38;
};
