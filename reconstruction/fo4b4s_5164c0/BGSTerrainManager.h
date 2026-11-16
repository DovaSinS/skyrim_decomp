// Build: sse-steam-1-7-104; RVA 0x5164c0; 56 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling hint.
// Drafted by gpt-6.1-sol
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// BGSTerrainManager::GetLODLandRootForLevel: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/DistantTerrain/BGSTerrainManager.cpp:6
// names: GUESS(low); names and original signatures are tentative.
#pragma once
class NiNode;
class BGSTerrainManager { public: static NiNode* roots[4]; static NiNode* GetLODLandRootForLevel(unsigned level); };
