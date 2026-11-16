// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x6d8550, 17 bytes: Actor::GetMagicTarget
// Actor::GetMagicTarget: SIBLING(fo4-private@1b765c70, author-permission); adapted to target base adjustment.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor_Magic.cpp:386
// names: GUESS(low); method identity is unverified.
#include "Actor.h"
MagicTarget* Actor::GetMagicTarget() { return static_cast<MagicTarget*>(this); }
