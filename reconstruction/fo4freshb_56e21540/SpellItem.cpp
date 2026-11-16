// SpellItem functions for build sse-steam-1-7-104.
// Labels: v2
// Task: p177fb-56e21540
// Source exposure: mixed (pinned target listing and sibling hints).
// Evidence: findings/ghidra-import.md
// RVA 0x155780, 9 bytes: SpellItem::GetRange
// RVA 0x1558c0, 22 bytes: SpellItem::LoadChunkDataPostProcess
// RVA 0x1553e0, 11 bytes: SpellItem::SetCastingType
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// Origin: adapted sibling source and target listing.
// SpellItem::GetRange: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/SpellItem.cpp:268
// SpellItem::LoadChunkDataPostProcess: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/SpellItem.cpp:128
// SpellItem::SetCastingType: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Magic/SpellItem.cpp:232
// SpellItem, SpellItem::GetRange: GUESS(low)
// SpellItem fields: STANDIN GUESS(low)
#include "SpellItem.h"
float SpellItem::GetRange() const { return range; }

void SpellItem::LoadChunkDataPostProcess(InputFile* file) { if (file->version < 0x22) castingPerk = nullptr; }

void SpellItem::SetCastingType(int value) { castingType = value; MagicItem::SetCastingType(value); }
