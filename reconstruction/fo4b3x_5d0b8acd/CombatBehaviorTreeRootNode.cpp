// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x875730, 7 bytes: CombatBehaviorTreeRootNode::Abort
// CombatBehaviorTreeRootNode::Abort: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:325
#include "CombatBehaviorTreeRootNode.h"
void CombatBehaviorTreeRootNode::Abort(CombatBehaviorThread* t) { Update(t); }
