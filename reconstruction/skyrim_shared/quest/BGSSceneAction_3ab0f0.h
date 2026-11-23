// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BGSSceneAction::Function3ab0f0, BGSSceneAction::unk0C, BGSSceneAction::unk0E: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class BGSSceneAction
{
public:
    bool Function3ab0f0(std::uint32_t a_phase);

    std::uint8_t pad00[0xC];
    std::uint16_t unk0C;
    std::uint16_t unk0E;
};
