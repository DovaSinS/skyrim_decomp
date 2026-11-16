// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x98ca60, 55 bytes: UIBlurManager::IncrementBlurCount
// UIBlurManager::IncrementBlurCount: SIBLING(fo4-private@1b765c70, author-permission); adapted to target counter width.
// Sibling source: fo4-private@1b765c70 src/Game/Interface/UIBlurManager.cpp:77
// names: GUESS(low); helper names and signature are unverified.
#include "UIBlurManager.h"
void UIBlurManager::IncrementBlurCount() { if (!blurCount) ImageSpaceModifierInstanceForm::Trigger(blurEffect, 1.0f, nullptr); ++blurCount; }
