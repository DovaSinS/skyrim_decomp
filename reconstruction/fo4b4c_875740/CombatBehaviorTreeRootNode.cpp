// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x875740, 19 bytes: CombatBehaviorTreeRootNode::Validate
// CombatBehaviorTreeRootNode::Validate: SIBLING(fo4-private@1b765c70, author-permission); adapted to the target's simplified predicate.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:190
// names: GUESS(low); names are unverified.
#include "CombatBehaviorTreeRootNode.h"
bool CombatBehaviorTreeRootNode::Validate(const CombatBehaviorTreeNode* node) { return node->childCount == 1 && !node->parent; }
