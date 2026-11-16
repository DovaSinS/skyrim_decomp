// Build: sse-steam-1-7-104
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// RVA 0x1e6d00, 75 bytes: TESForm::AddCompileIndex
// TESForm::AddCompileIndex, build sse-steam-1-7-104, RVA 0x1e6d00, 75 bytes.
// Labels: v2
// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: original reconstruction using target listing and anonymous sibling hints.
// AddCompileIndex: SIBLING(fo4-private@1b765c70, author-permission); src/Shared/FormComponents/TESForm.cpp:997; adapted control flow.
// Evidence: findings/ghidra-import.md; Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Types and method names: GUESS(low); signatures inferred from target calling convention and sibling.
#include "TESForm.h"
void TESForm::AddCompileIndex(unsigned int& id, TESFile* file) {
    if (id - 1 > 0x7fe && file) {
        TESFile* indexFile = file->GetIndexFile((id >> 24) + 1);
        if (!indexFile) indexFile = file;
        indexFile->AdjustFormIDFileIndex(id);
    }
}
