// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Script: GUESS(low); the class is the placeholder owner
// Script::ClearOptimizations: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24); a static function without parameters
// g_optimizedCode, g_optimizedData, g_optimizedIndex, g_optimizedOwner: GUESS(low); per-thread values the function resets, names made up
#pragma once

#include <cstdint>

extern __declspec(thread) void* g_optimizedCode;
extern __declspec(thread) void* g_optimizedData;
extern __declspec(thread) std::int32_t g_optimizedIndex;
extern __declspec(thread) void* g_optimizedOwner;

class Script
{
public:
    static void ClearOptimizations();
};
