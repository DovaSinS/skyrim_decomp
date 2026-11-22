// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xce86b0 MemoryHeap::CleanExtraPages
// Adapted bodies: none
#include "MemoryHeap_ce86b0.h"

// decommit the page-aligned tail of a run; returns the decommitted size, 0 if nothing was released
std::size_t MemoryHeap::CleanExtraPages(std::size_t end, std::size_t base, std::size_t size)
{
    size &= ~static_cast<std::size_t>(commitGranularity - 1);
    if (size < commitGranularity)
        return 0;
    end -= size;
    if (VirtualFree(reinterpret_cast<void*>(base + end), size, 0x4000) != 1)
        return 0;
    return size;
}
