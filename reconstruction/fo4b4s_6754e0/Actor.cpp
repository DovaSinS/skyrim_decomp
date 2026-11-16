// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-sol.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x6754e0, 35 bytes: Actor::Disable
// Actor::Disable: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:6345
// names: GUESS(low); helper identities and names are unverified.
#include "Actor.h"
void Actor::Disable() { if (this == player) return; if ((unsigned char)(formFlags >> 11) & 1) return; taskQueue->QueueDisableReference(this); }
