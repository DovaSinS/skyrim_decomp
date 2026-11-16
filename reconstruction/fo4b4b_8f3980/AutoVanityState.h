// Build: sse-steam-1-7-104; RVA 0x8f3980; 12 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling hint.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// AutoVanityState::End: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/AutoVanityState.cpp:61
// names: GUESS(low); names and original signatures are tentative.
#pragma once
extern const char resumeMessage[];
void SendUptimeEvent(const char*);
class AutoVanityState { public: void End(); };
