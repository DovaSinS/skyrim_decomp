// TESQuest, build sse-steam-1-7-104.
// Labels: v2
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x3cdf10, 41 bytes: TESQuest::sub.
// TESQuest: EXE_RTTI

#include "TESQuest.h"
void TESQuest::sub(TESQuest* quest, std::uint32_t requestValue) { if (quest) { QuestRequest request{quest, requestValue}; quest->GetQueue()->Submit(request); } }
