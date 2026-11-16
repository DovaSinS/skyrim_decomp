// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x1f34e0, 118 bytes: TESValueForm::CopyComponent
// TESValueForm::CopyComponent: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESValueForm.cpp:30
#include "TESValueForm.h"
void TESValueForm::CopyComponent(BaseFormComponent* other) { TESValueForm* copy=dynamic_cast<TESValueForm*>(other); if(copy) { value=copy->value; TESForm* form=dynamic_cast<TESForm*>(this); if(form) form->AddChange(2); } }
