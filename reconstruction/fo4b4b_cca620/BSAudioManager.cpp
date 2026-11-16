// Build: sse-steam-1-7-104; RVA 0xcca620; 8 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling hint.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// BSAudioManager::QPlatformInstance: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/BSAudio/BSAudioManager.cpp:75
// BSAudioManager, BSAudio, platformInstance: GUESS(low); names and types are tentative.
#include "BSAudioManager.h"
BSAudio& BSAudioManager::QPlatformInstance() { return *platformInstance; }
