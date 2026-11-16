// TESObjectREFR, build sse-steam-1-7-104.
// Labels: v2
// TESObjectREFR: GUESS(low) STANDIN
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis.
// Drafted by gpt-6.1-sol.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x2ff6d0, 42 bytes: TESObjectREFR::sub.
// TESObjectREFR, Function2ff6d0, FindIndex: GUESS(low)
// TESObjectREFR: STANDIN GUESS(low)
#pragma once
#include <cstdint>
class TESObjectREFR {
public:
 std::int32_t FindIndex(std::uint32_t, bool);
 std::uint8_t Function2ff6d0(bool);
};
