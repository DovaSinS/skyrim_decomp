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
#include "TESObjectREFR.h"
std::uint8_t TESObjectREFR::Function2ff6d0(bool a_flag)
{
 std::uint8_t result = 0;
 if (FindIndex(0, a_flag) != -1) result = 1;
 return result;
}
