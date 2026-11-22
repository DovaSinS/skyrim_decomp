// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xce8710 MemoryHeap::DecommitPages
// Adapted bodies: none
#include "MemoryHeap_ce8710.h"

// decommit the whole pages inside a block and flag the block header as decommitted
void MemoryHeap::DecommitPages(std::uint64_t* block)
{
    std::size_t mask = ~static_cast<std::size_t>(commitGranularity - 1);
    std::size_t begin = (reinterpret_cast<std::size_t>(block) + 0x3f + commitGranularity) & mask;
    std::size_t end = (reinterpret_cast<std::size_t>(block) + 0x20 + (*block & 0x1fffffffffffffffull)) & mask;
    if (begin < end) {
        VirtualFree(reinterpret_cast<void*>(begin), end - begin, 0x4000);
        *block |= 0x2000000000000000ull;
    }
}
