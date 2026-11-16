// PathingRequestFlyLand declarations for build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: target listing and anonymous sibling hints.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// PathingRequestFlyLand, GetType, BSCRC32, GenerateCRC, PathingRequestFlyLandCRC: GUESS(low)
#pragma once
extern unsigned int PathingRequestFlyLandCRC;
class BSCRC32 { public: static void GenerateCRC(unsigned int&, const char*, unsigned int); };
class PathingRequestFlyLand { public: unsigned int GetType() const; };
