// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSShaderAccumulator::GetBatchRendererFlags: CRASHLOGGER_PDB(59818@2026.10.24)
// BSShaderAccumulator: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) OBSERVED; layout view only, the 0x130 member is batchRenderer in the community header
// BatchRendererStandIn, RenderPassGroup, groups, passCount, unknown00: GUESS(low); minimal views of what the body reads
#pragma once

#include <cstdint>

struct RenderPassGroup
{
    std::uint8_t unknown00[0x24];  // 00
    std::uint16_t passCount;       // 24
};

struct BatchRendererStandIn
{
    std::uint8_t unknown00[0x98];  // 00
    RenderPassGroup* groups;       // 98
};

class BSShaderAccumulator
{
public:
    std::uint16_t GetBatchRendererFlags();  // compared: 0x15209f0

    std::uint8_t unknown00[0x130];       // 00
    BatchRendererStandIn* batchRenderer;  // 130
};
