// Main functions for build sse-steam-1-7-104.
// Labels: v2
// Task: p177fb-eb814be3
// Source exposure: mixed (pinned target listing and sibling hints).
// Evidence: findings/ghidra-import.md
// RVA 0x65c480, 15 bytes: Main::WorldRootCamera
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// Origin: adapted sibling source and target listing.
// Main::WorldRootCamera: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/Misc/Main.cpp:137
// Main, Main::WorldRootCamera: GUESS(low)
// Main fields: STANDIN GUESS(low)
#include "Main.h"
void* Main::WorldRootCamera() { return worldRoot->camera; }
