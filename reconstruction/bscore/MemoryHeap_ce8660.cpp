// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xce8660 MemoryHeap::CreateMorePages
// Adapted bodies: none
#include "MemoryHeap_ce8660.h"

// commit a page-aligned run at base + offset; returns its size, 0 on failure
std::size_t MemoryHeap::CreateMorePages(std::size_t base, std::size_t offset, std::size_t size)
{
    std::size_t aligned = (size + commitGranularity - 1) & ~static_cast<std::size_t>(commitGranularity - 1);
    void* result = VirtualAlloc(reinterpret_cast<void*>(base + offset), aligned, 0x1000, 4);
    if (!result)
        aligned = 0;
    return aligned;
}
