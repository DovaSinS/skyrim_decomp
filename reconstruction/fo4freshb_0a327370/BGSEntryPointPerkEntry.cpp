// BGSEntryPointPerkEntry functions for build sse-steam-1-7-104.
// Labels: v2
// Task: p177fb-0a327370
// Source exposure: mixed (pinned target listing and sibling hints).
// Evidence: findings/ghidra-import.md
// RVA 0x3966c0, 21 bytes: BGSEntryPointPerkEntry::SetParent
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// Origin: adapted sibling source and target listing.
// BGSEntryPointPerkEntry::SetParent: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/BGSPerk.cpp:105
// BGSEntryPointPerkEntry, BGSEntryPointPerkEntry::SetParent: GUESS(low)
// BGSEntryPointPerkEntry fields: STANDIN GUESS(low)
#include "BGSEntryPointPerkEntry.h"
void BGSEntryPointPerkEntry::SetParent(Perk* value) { parent = value; if (functionData) functionData->SetPerk(value); }
