// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x288480, 12 bytes: TESObjectTREE::OnRemove3D
// TESObjectTREE::OnRemove3D: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESObjectTREE.cpp:215
#include "TESObjectTREE.h"
void TESObjectTREE::OnRemove3D(NiAVObject* object) { treeManager->RemoveTree(object); }
