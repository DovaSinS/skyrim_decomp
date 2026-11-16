// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x5dcb40, 35 bytes: ActiveEffectReferenceEffectController::SaveGame
// ActiveEffectReferenceEffectController::SaveGame: SIBLING(fo4-private@1b765c70, author-permission); adapted to target save call.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ReferenceEffectControllers.cpp:302
// names: GUESS(low); save helper signature is inferred.
#include "ActiveEffectReferenceEffectController.h"
void ActiveEffectReferenceEffectController::SaveGame(BGSSaveGameBuffer* buffer) const { unsigned int handle = target; buffer->SaveFormID(&handle, false); }
