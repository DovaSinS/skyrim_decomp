// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x67e9b0, 24 bytes: Actor::SetCrimeGoldValue
// Actor::SetCrimeGoldValue: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:5216
// names: GUESS(low); call identities and method names remain unverified.
#include "Actor.h"
void Actor::SetCrimeGoldValue(TESFaction* faction, bool, unsigned value) { if (faction) faction->SetCrimeGoldValue(static_cast<TESNPC*>(data.objectReference), value); }
