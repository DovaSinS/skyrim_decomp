// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x69f9c0, 17 bytes: Actor::ForEachPerkEntry
// Actor::ForEachPerkEntry: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:5919
// names: GUESS(low); call identities and method names remain unverified.
#include "Actor.h"
void Actor::ForEachPerkEntry(unsigned char entry, PerkEntryVisitor& visitor) const { if (currentProcess) currentProcess->ForEachPerkEntry(entry, visitor); }
