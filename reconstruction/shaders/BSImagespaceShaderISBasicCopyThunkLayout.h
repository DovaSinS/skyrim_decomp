// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed (RTTI and member-local tailcall; community base declarations).
// Drafted by tools/shader_adjustor_template_v1.py (GPT-6.1 Sol).
// Labels: v2
// BSImagespaceShaderISBasicCopy: EXE_RTTI
// BSImagespaceShaderISBasicCopyThunkLayout: GUESS(low) STANDIN
// Adapted bodies: none. Ordinary constructor over independently reconciled RTTI inheritance.
// Base layouts adapt licensed community declarations in their own headers.
// Owner fields and methods outside the compared adjustor are omitted; owner size is not claimed.
// The owner destructor and base constructor remain external; only the listed adjustor is compared.
// No original-source, behavior, allocation-size or name-correctness claim.
// Origin: {"family": "shader-destructor-adjustor", "template_digest": "4ab2e536874974a73312bf220196c9e7ff540a0daa29fb509df98017f624db5d", "version": "1"}
// RVA 0x1507468; 9 bytes
#pragma once
#include "ImagespaceShaderLayout.h"
namespace ResearchLayouts {
class BSImagespaceShaderISBasicCopyThunkLayout : public ImagespaceShaderLayout {
public:
    BSImagespaceShaderISBasicCopyThunkLayout();
    ~BSImagespaceShaderISBasicCopyThunkLayout() override;
};
}
