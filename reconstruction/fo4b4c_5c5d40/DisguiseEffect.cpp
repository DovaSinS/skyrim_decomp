// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x5c5d40, 42 bytes: DisguiseEffect::FinishLoadGame
// DisguiseEffect::FinishLoadGame: SIBLING(fo4-private@1b765c70, author-permission); adapted to target state and calls.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/DisguiseEffect.cpp:83
// names: GUESS(low); qualified name and helper identities are unverified.
#include "DisguiseEffect.h"
void DisguiseEffect::FinishLoadGame(BGSLoadFormBuffer* buffer) { ActiveEffect::FinishLoadGame(buffer); if (state <= 1) InitiateDetectionCheck(); }
