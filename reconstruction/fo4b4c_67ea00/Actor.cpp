// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x67ea00, 24 bytes: Actor::RemoveCrimeGoldValue
// Actor::RemoveCrimeGoldValue: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:5231
// names: GUESS(low); call identities and method names remain unverified.
#include "Actor.h"
void Actor::RemoveCrimeGoldValue(TESFaction* faction, bool, int value) { if (faction) faction->ModCrimeGoldValue(static_cast<TESNPC*>(data.objectReference), value); }
