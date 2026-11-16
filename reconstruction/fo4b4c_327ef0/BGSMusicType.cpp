// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x327ef0, 26 bytes: BGSMusicType::DoClearDucking
// BGSMusicType::DoClearDucking: SIBLING(fo4-private@1b765c70, author-permission); adapted to the target interface layout.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicType.cpp:77
// names: GUESS(low); qualified name is unverified.
#include "BGSMusicType.h"
void BGSMusicType::DoClearDucking() { if (currentTrackIndex < tracks.size) tracks.data[currentTrackIndex]->DoClearDucking(); }
