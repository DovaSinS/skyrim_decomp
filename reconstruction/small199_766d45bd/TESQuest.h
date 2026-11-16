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

#pragma once
#include <cstdint>
class TESQuest;
// QuestRequest, quest, requestValue, QuestQueue, Submit, GetQueue: GUESS(low) STANDIN
struct QuestRequest { TESQuest* quest; std::uint32_t requestValue; };
class QuestQueue { public: void Submit(QuestRequest& request); };
// sub: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class TESQuest { public: static void sub(TESQuest* quest, std::uint32_t requestValue); QuestQueue* GetQueue(); };
