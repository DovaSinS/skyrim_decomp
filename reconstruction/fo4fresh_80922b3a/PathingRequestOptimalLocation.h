// PathingRequestOptimalLocation, build sse-steam-1-7-104.
// Labels: v2
// RVA 0x4f8cc0, 47 bytes: PathingRequestOptimalLocation::GetType
// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestOptimalLocation.cpp:76 (PathingRequestOptimalLocation::GetType)
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// PathingRequestOptimalLocation, GetType, typeId, result, BSCRC32, GenerateCRC: GUESS(low)
#pragma once
class BSCRC32 { public: static void GenerateCRC(unsigned int& value, const char* name, int mode); };
class PathingRequestOptimalLocation { public: static unsigned int typeId; unsigned int GetType() const; };
