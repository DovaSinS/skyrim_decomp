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
// TESObjectREFR: STANDIN EXE_RTTI
// Function68ab50, Function67f1a0, GetInventory, GetReferenceData, CountValue, FindValue: GUESS(low)
#pragma once
#include <cstdint>
class Inventory { public: std::uint64_t CountValue(std::uint32_t); };
class ReferenceData { public: std::uint64_t FindValue(void*); };
class TESObjectREFR { public: Inventory* GetInventory(); ReferenceData* GetReferenceData(); std::uint64_t Function68ab50(std::uint32_t); std::uint64_t Function67f1a0(void*); };
