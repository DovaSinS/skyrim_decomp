// ProcessLists, build sse-steam-1-7-104.
// Labels: v2
// RVA 0x780eb0, 9 bytes: ProcessLists::GetSystemTimeClock
// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/ProcessLists.cpp:256 (ProcessLists::GetSystemTimeClock)
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// ProcessLists, GetSystemTimeClock, systemTimeClock: GUESS(low)
#include "ProcessLists.h"
float ProcessLists::GetSystemTimeClock() { return systemTimeClock; }
