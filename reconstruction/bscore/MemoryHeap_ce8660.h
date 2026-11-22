// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// MemoryHeap: GUESS(low); the class is the placeholder owner
// CreateMorePages: CRASHLOGGER_PDB(59818@2026.10.24)
// commitGranularity: GUESS(low); offset 0x40 member, no community name
#pragma once

#include <cstdint>
#include <cstddef>

extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void* address, size_t size, unsigned long type, unsigned long protect);
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* address, size_t size, unsigned long type);

class MemoryHeap
{
public:
    std::size_t CreateMorePages(std::size_t base, std::size_t offset, std::size_t size);  // compared: 0xce8660

    unsigned char unk00[0x40];
    std::uint32_t commitGranularity;
};
