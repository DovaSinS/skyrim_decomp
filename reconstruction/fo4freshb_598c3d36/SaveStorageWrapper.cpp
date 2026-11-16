// SaveStorageWrapper functions for build sse-steam-1-7-104.
// Labels: v2
// Task: p177fb-598c3d36
// Source exposure: mixed (pinned target listing and sibling hints).
// Evidence: findings/ghidra-import.md
// RVA 0x63a4d0, 44 bytes: SaveStorageWrapper::GetPosition
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// Origin: adapted sibling source and target listing.
// SaveStorageWrapper::GetPosition: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/Buffers/BGSSaveLoadStorageWrappers.cpp:50
// SaveStorageWrapper, SaveStorageWrapper::GetPosition: GUESS(low)
// SaveStorageWrapper fields: STANDIN GUESS(low)
#include "SaveStorageWrapper.h"
std::uint32_t SaveStorageWrapper::GetPosition() const { if (useBuffer && buffer) return buffer->head - buffer->start; return (file->position != 0xffffffff ? file->position : file->fallback) - start; }
