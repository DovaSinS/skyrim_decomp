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
#include "MagicItemData.h"
bool MagicItemData::GetFavorite() {
 bool favorite = false;
 if (magicFavorites->IsFavorite(baseForm)) favorite = true;
 return favorite;
}
