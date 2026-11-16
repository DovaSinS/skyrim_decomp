// MagicItemData, build sse-steam-1-7-104.
// Labels: v2
// Origin: adapted declarations from powerof3/CommonLibSSE, GPL-3.0, 654e55f7979c1733033d5dbef176e43827bac944.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// MagicItemData: EXE_RTTI
// Declarations adapted from powerof3/CommonLibSSE under GPL-3.0.
// Compared functions:
// RVA 0x951e40, 46 bytes: MagicItemData::GetFavorite.
#pragma once
#include <cstdint>
// MagicItemData, GetFavorite, BSString, effectDesc, baseForm, MagicFavorites: COMMUNITY(powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944, GPL-3.0)
// IsFavorite, magicFavorites, data, size, capacity: GUESS(low)
class TESForm;
class MagicFavorites { public: std::uint8_t IsFavorite(TESForm* form); };
extern MagicFavorites* magicFavorites;
class BSString { public: char* data; std::uint16_t size, capacity; };
class MagicItemData {
public:
 virtual ~MagicItemData();
 bool GetFavorite();
 BSString effectDesc;
 TESForm* baseForm;
};
