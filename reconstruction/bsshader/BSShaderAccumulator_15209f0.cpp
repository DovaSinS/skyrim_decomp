// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x15209f0 BSShaderAccumulator::GetBatchRendererFlags
// Adapted bodies: none
#include "BSShaderAccumulator_15209f0.h"

std::uint16_t BSShaderAccumulator::GetBatchRendererFlags()
{
    return batchRenderer->groups->passCount;
}
