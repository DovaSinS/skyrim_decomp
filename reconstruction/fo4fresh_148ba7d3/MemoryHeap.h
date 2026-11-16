// MemoryHeap declarations for build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: target listing and anonymous sibling hints.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// MemoryHeap, BaseAllocate, BaseFree, Allocate, Deallocate, Size, TotalSize: GUESS(low)
#pragma once
#include <cstddef>
#include <cstdint>
class MemoryHeap {
public:
    void* BaseAllocate(std::uint64_t, std::uint64_t, bool);
    void BaseFree(void*);
    void* Allocate(std::uint64_t, unsigned int);
    void Deallocate(void*, unsigned int);
    std::uint64_t Size(const void*) const;
    std::uint64_t TotalSize(const void*) const;
};
