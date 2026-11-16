// BSShaderAccumulator, build sse-steam-1-7-104.
// Labels: v2
// BSShaderAccumulator, sub, Prepare, Finish: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis only).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x151ee60, 40 bytes: BSShaderAccumulator::sub.

#pragma once

// BSShaderAccumulator, sub, Prepare, Finish: GUESS(low)
class BSShaderAccumulator {
public:
    void sub(unsigned int);
    void Prepare();
    void Finish(unsigned int);
};
