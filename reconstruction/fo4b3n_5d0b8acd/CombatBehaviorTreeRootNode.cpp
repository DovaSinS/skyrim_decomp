// Build: sse-steam-1-7-104
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// RVA 0x8757a0, 140 bytes: CombatBehaviorTreeRootNode::GetType
// CombatBehaviorTreeRootNode::GetType, build sse-steam-1-7-104, RVA 0x8757a0, 140 bytes.
// Labels: v2
// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: original reconstruction using target listing and anonymous sibling hints.
// GetType: SIBLING(fo4-private@1b765c70, author-permission); src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:331; adapted return behavior.
// BSFixedString and string content: GUESS(low); representation and type name inferred for this attempt.
// Evidence: findings/ghidra-import.md; Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
#include "CombatBehaviorTreeRootNode.h"
const BSFixedString& CombatBehaviorTreeRootNode::GetType() const { static BSFixedString type("Root"); return type; }
