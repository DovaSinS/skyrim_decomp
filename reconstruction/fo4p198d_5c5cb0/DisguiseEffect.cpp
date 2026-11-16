// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x5c5cb0, 64 bytes: DisguiseEffect::SaveGame
// DisguiseEffect::SaveGame: SIBLING(fo4-private@1b765c70, author-permission); adapted to the target calls.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/DisguiseEffect.cpp:69
// names: GUESS(low); signatures and helper identities need independent review.
#include "DisguiseEffect.h"
void DisguiseEffect::SaveGame(BGSSaveFormBuffer* buffer) const { ActiveEffect::SaveGame(buffer); buffer->SaveDataEndian(&state, 4, 4, 0); }
