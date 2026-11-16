// CombatBehaviorTreeRootNode reconstruction.
// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x875700, 30 bytes: CombatBehaviorTreeRootNode::Update
// CombatBehaviorTreeRootNode::Update: SIBLING(fo4-private@1b765c70, author-permission); adapted using target evidence
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:179
// CombatBehaviorTreeRootNode, CombatBehaviorThread, CombatBehaviorTreeNode, CombatBehaviorStack, buffer, capacity, size, stack, Ascend: GUESS(low); names and declarations are provisional
#pragma once
#include <cstdint>
class CombatBehaviorTreeNode;
struct CombatBehaviorStack {
    unsigned char* buffer;
    std::uint32_t capacity;
    std::uint32_t size;
};
class CombatBehaviorThread {
public:
    CombatBehaviorStack stack;
    void Ascend(const CombatBehaviorTreeNode* node);
};
class CombatBehaviorTreeRootNode {
public:
    void Update(CombatBehaviorThread* thread) const;
};
