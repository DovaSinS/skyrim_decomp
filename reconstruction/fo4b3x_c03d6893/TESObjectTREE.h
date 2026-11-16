// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// TESObjectTREE, BSTreeManager, RemoveTree, treeManager: GUESS(low); global and call sites corroborated by target.
#pragma once
class NiAVObject; class BSTreeManager { public: void RemoveTree(NiAVObject*); }; extern BSTreeManager* treeManager; class TESObjectTREE { public: void OnRemove3D(NiAVObject*); };
