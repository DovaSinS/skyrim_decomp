// TESNPC, build sse-steam-1-7-104.
// Labels: v2
// TESNPC, Function3bf5b0, Function3c8bd0, GetState, stateZero, stateNonzero, Cache, cache: GUESS(low)
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis only).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x3bf5b0, 39 bytes: TESNPC::sub.
// RVA 0x3c8bd0, 42 bytes: TESNPC::Function3c8bd0.

#pragma once
// TESNPC, Function3bf5b0, Function3c8bd0, GetState, stateZero, stateNonzero, Cache, cache: GUESS(low)
class Cache { public: virtual ~Cache(); };
extern Cache* cache;
extern const float stateZero;
extern const float stateNonzero;
class TESNPC { public:
    int GetState();
    float Function3bf5b0();
    static void Function3c8bd0();
};
