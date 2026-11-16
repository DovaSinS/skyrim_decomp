// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x1eacb0, 86 bytes: TESModel::CopyComponent
// TESModel::CopyComponent: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESModel.cpp:46
#include "TESModel.h"
void TESModel::CopyComponent(BaseFormComponent* other) { TESModel* model = dynamic_cast<TESModel*>(other); if (model) SetModel(model->GetModel()); }
