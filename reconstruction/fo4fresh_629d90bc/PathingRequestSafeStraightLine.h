// PathingRequestSafeStraightLine declarations for build sse-steam-1-7-104.
// Labels: v2
// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: target listing and anonymous sibling hints.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// PathingRequestSafeStraightLine, GetType, BSCRC32, GenerateCRC, PathingRequestSafeStraightLineCRC: GUESS(low)
#pragma once
extern unsigned int PathingRequestSafeStraightLineCRC;
class BSCRC32 { public: static void GenerateCRC(unsigned int&, const char*, unsigned int); };
class PathingRequestSafeStraightLine { public: unsigned int GetType() const; };
