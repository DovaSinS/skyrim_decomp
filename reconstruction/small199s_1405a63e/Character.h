// Character threshold comparison, build sse-steam-1-7-104, RVA 0x6a3290, 41 bytes.
// Labels: v2
// Origin: original reconstruction; no sibling or community implementation used.
// Source exposure: binary-analysis.
// Drafted by gpt-6.1-sol.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Only ExceedsScaledMetric is compared. Signatures and semantics remain inferred.
// Character, ExceedsScaledMetric, Calculate, factor: GUESS(low)
#pragma once
constexpr float factor = 0.5f;
class Character { public:
    float Calculate(void* context);
    bool ExceedsScaledMetric(void* context, float threshold);
};
