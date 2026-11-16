// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x1d72b0, 86 bytes: BGSEquipType::CopyComponent
// BGSEquipType::CopyComponent: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/BGSEquipType.cpp:65
#include "BGSEquipType.h"
void BGSEquipType::CopyComponent(BaseFormComponent* other) { BGSEquipType* type = dynamic_cast<BGSEquipType*>(other); if (type) SetEquipSlot(type->GetEquipSlot()); }
