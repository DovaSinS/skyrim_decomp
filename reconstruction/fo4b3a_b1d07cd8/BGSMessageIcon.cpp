// Build: sse-steam-1-7-104
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// RVA 0x1d9200, 12 bytes: BGSMessageIcon::InitializeDataComponent
// RVA 0x1d9220, 12 bytes: BGSMessageIcon::ClearDataComponent
// RVA 0x1d9200, 12 bytes: BGSMessageIcon::InitializeDataComponent
// BGSMessageIcon::InitializeDataComponent: SIBLING(fo4-private@1b765c70, author-permission); adaptation of src/Shared/FormComponents/BGSMessageIcon.cpp:45.
// RVA 0x1d9220, 12 bytes: BGSMessageIcon::ClearDataComponent
// BGSMessageIcon::ClearDataComponent: SIBLING(fo4-private@1b765c70, author-permission); adaptation of src/Shared/FormComponents/BGSMessageIcon.cpp:51.
// Semantic names and types: GUESS(low)
// Labels: v2
// Source exposure: mixed.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra. Evidence: findings/ghidra-import.md
#include "BGSMessageIcon.h"
void BGSMessageIcon::InitializeDataComponent() { icon.InitializeDataComponent(); }
void BGSMessageIcon::ClearDataComponent() { icon.ClearDataComponent(); }
