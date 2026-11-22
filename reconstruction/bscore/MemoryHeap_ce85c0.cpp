// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xce85c0 MemoryHeap::DoHeapAllocation
// Adapted bodies: none
#include "MemoryHeap_ce85c0.h"

// reserve address space, then commit the first part; release it again if the commit fails
void* MemoryHeap::DoHeapAllocation(std::size_t reserveSize, std::size_t commitSize)
{
    void* base = VirtualAlloc(nullptr, reserveSize, 0x2000, 4);
    if (base != nullptr && commitSize != 0) {
        if (VirtualAlloc(base, commitSize, 0x1000, 4) == nullptr) {
            VirtualFree(base, 0, 0x8000);
            base = nullptr;
        }
    }
    return base;
}
