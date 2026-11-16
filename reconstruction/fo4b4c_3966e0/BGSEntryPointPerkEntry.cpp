// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x3966e0, 22 bytes: BGSEntryPointPerkEntry::GetID
// BGSEntryPointPerkEntry::GetID: SIBLING(fo4-private@1b765c70, author-permission); adapted to target conditional virtual call.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/BGSPerk.cpp:113
// names: GUESS(low); function and virtual call names are unverified.
#include "BGSEntryPointPerkEntry.h"
unsigned short BGSEntryPointPerkEntry::GetID() const { return functionData ? functionData->GetID() : 0xffff; }
