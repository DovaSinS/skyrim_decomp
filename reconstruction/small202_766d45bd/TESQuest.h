// TESQuest, build sse-steam-1-7-104.
// Labels: v2
// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// TESQuest: EXE_RTTI
// Compared functions:
// RVA 0x3daf50, 48 bytes: TESQuest::Function3daf50.
#pragma once
#include <cstdint>
// TESQuest: EXE_RTTI
// Function3daf50, Search, Query, found, id, context: GUESS(low)
struct Query { bool found; std::uint32_t id; void* context; };
class TESQuest {
public:
 bool Function3daf50(std::uint32_t id, void* context);
 void Search(Query** query);
};
