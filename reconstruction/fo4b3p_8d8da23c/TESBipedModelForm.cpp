// Build: sse-steam-1-7-104
// Labels: v2
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra. Evidence: findings/ghidra-import.md
// RVA 0x1df3e0, 74 bytes: TESBipedModelForm::InitializeDataComponent
// RVA 0x1df430, 74 bytes: TESBipedModelForm::ClearDataComponent
// TESBipedModelForm::InitializeDataComponent: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// TESBipedModelForm::ClearDataComponent: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESBipedModelForm.cpp:38
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESBipedModelForm.cpp:48
#include "TESBipedModelForm.h"
void TESBipedModelForm::InitializeDataComponent() { worldModels[0].InitializeDataComponent(); worldModels[1].InitializeDataComponent(); inventoryIcons[0].InitializeDataComponent(); inventoryIcons[1].InitializeDataComponent(); constraintTemplate.InitializeDataComponent(); }
void TESBipedModelForm::ClearDataComponent() { worldModels[0].ClearDataComponent(); worldModels[1].ClearDataComponent(); inventoryIcons[0].ClearDataComponent(); inventoryIcons[1].ClearDataComponent(); constraintTemplate.ClearDataComponent(); }
