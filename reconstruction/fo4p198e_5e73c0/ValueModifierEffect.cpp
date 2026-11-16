// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed.
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// ValueModifierEffect::Update: SIBLING(fo4-private@1b765c70, author-permission); adapted to observed target behavior.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ValueModifierEffect.cpp:157
// ValueModifierEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/V/ValueModifierEffect.h.
// names: GUESS(low); method signatures and local names are inferred.
// RVA 0x5e73c0, 66 bytes: ValueModifierEffect::Update
#include "ValueModifierEffect.h"
void ValueModifierEffect::Update(float seconds) { if (ShouldModifyOnUpdate()) ModifyOnUpdate(seconds); ResearchLayouts::ActiveEffectLayout::DoStandardCustomSkillUsage(seconds); }
