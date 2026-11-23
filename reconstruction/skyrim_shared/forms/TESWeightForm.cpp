// Code origin: original from the listing and community declarations, except InitializeDataComponent and CopyComponent, which are close to the sibling bodies named below
// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image. Names are from CharmedBaryon/CommonLibSSE-NG b93280e (MIT).
// Adapted bodies: InitializeDataComponent and CopyComponent are close to the sibling bodies (tools/check_origin.py similarity 0.75 and 0.92).
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESWeightForm.cpp:25
// Sibling source: fo4-private@1b765c70 src/Shared/FormComponents/TESWeightForm.cpp:36
// TESWeightForm::InitializeDataComponent, TESWeightForm::CopyComponent: SIBLING(fo4-private@1b765c70, author-permission)
// 0x1f3740 TESWeightForm::InitializeDataComponent
// 0x1f3760 TESWeightForm::CopyComponent
#include "TESWeightForm.h"

void TESWeightForm::InitializeDataComponent()
{
    weight = 0.0f;
}

void TESWeightForm::CopyComponent(BaseFormComponent* a_rhs)
{
    TESWeightForm* rhs = dynamic_cast<TESWeightForm*>(a_rhs);
    if (rhs) {
        weight = rhs->weight;
    }
}
