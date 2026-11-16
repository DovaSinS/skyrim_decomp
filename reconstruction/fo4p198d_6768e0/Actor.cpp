// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x6768e0, 67 bytes: Actor::GetEditorLocation
// Actor::GetEditorLocation: SIBLING(fo4-private@1b765c70, author-permission); adapted to the target.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Actor.cpp:507
// names: GUESS(low); signatures and helper identities need independent review.
#include "Actor.h"
bool Actor::GetEditorLocation(NiPoint3& location, NiPoint3& angle, TESForm*& form, TESForm*) { if (!editorLocForm) return false; location.x = editorLocCoord.x; location.y = editorLocCoord.y; location.z = editorLocCoord.z; angle.x = 0.0f; angle.y = 0.0f; angle.z = editorLocRot; form = editorLocForm; return true; }
