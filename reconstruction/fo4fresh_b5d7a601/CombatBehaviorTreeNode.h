// CombatBehaviorTreeNode, build sse-steam-1-7-104.
// Labels: v2
// RVA 0x875560, 8 bytes: CombatBehaviorTreeNode::Update
// RVA 0x875570, 8 bytes: CombatBehaviorTreeNode::Abort
// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:61 (CombatBehaviorTreeNode::Update)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:67 (CombatBehaviorTreeNode::Abort)
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// CombatBehaviorTreeNode, Update, Abort: GUESS(low)
#pragma once

// CombatBehaviorThread, Ascend, thread: GUESS(low)
class CombatBehaviorThread { public: void Ascend(); };
class CombatBehaviorTreeNode { public: void Update(CombatBehaviorThread* thread) const; void Abort(CombatBehaviorThread* thread) const; };
