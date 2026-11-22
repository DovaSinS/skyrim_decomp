// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x151e3f0 BSShaderAccumulator::FinishAccumulating
// Adapted bodies: none
#include "BSShaderAccumulator_151e3f0.h"

void BSShaderAccumulator::FinishAccumulating(std::uint32_t flags)
{
    FinishAccumulatingPreResolveDepth(flags);
    FinishAccumulatingPostResolveDepth(flags);
}
