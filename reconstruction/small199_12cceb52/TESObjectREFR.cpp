// TESObjectREFR, build sse-steam-1-7-104.
// Labels: v2
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x68ab50, 39 bytes: TESObjectREFR::sub.
// RVA 0x67f1a0, 41 bytes: TESObjectREFR::sub.
#include "TESObjectREFR.h"
std::uint64_t TESObjectREFR::Function68ab50(std::uint32_t value) { Inventory* data = GetInventory(); return data ? data->CountValue(value) : 0; }
std::uint64_t TESObjectREFR::Function67f1a0(void* value) { ReferenceData* data = GetReferenceData(); return data ? data->FindValue(value) : 0; }
