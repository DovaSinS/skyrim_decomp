// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x8755c0, 11 bytes: CombatBehaviorTreeWrapperNode::GetName
// CombatBehaviorTreeWrapperNode::GetName: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:271
// RVA 0x8755e0, 11 bytes: CombatBehaviorTreeWrapperNode::Enter
// CombatBehaviorTreeWrapperNode::Enter: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:277
// RVA 0x875600, 11 bytes: CombatBehaviorTreeWrapperNode::Exit
// CombatBehaviorTreeWrapperNode::Exit: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:283
// RVA 0x875620, 11 bytes: CombatBehaviorTreeWrapperNode::Update
// CombatBehaviorTreeWrapperNode::Update: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:289
// RVA 0x875640, 11 bytes: CombatBehaviorTreeWrapperNode::Abort
// CombatBehaviorTreeWrapperNode::Abort: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:295
// RVA 0x875660, 11 bytes: CombatBehaviorTreeWrapperNode::SaveGame
// CombatBehaviorTreeWrapperNode::SaveGame: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:301
// RVA 0x875680, 11 bytes: CombatBehaviorTreeWrapperNode::LoadGame
// CombatBehaviorTreeWrapperNode::LoadGame: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:307
// RVA 0x8756a0, 11 bytes: CombatBehaviorTreeWrapperNode::Validate
// CombatBehaviorTreeWrapperNode::Validate: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorTreeNode.cpp:319
#include "CombatBehaviorTreeWrapperNode.h"
const BSFixedString& CombatBehaviorTreeWrapperNode::GetName() { return node->GetName(); }
void CombatBehaviorTreeWrapperNode::Enter(CombatBehaviorThread* t) { node->Enter(t); }
void CombatBehaviorTreeWrapperNode::Exit(CombatBehaviorThread* t) { node->Exit(t); }
void CombatBehaviorTreeWrapperNode::Update(CombatBehaviorThread* t) { node->Update(t); }
void CombatBehaviorTreeWrapperNode::Abort(CombatBehaviorThread* t) { node->Abort(t); }
void CombatBehaviorTreeWrapperNode::SaveGame(CombatBehaviorThread* t, BGSSaveFormBuffer* b) { node->SaveGame(t,b); }
void CombatBehaviorTreeWrapperNode::LoadGame(CombatBehaviorThread* t, BGSLoadFormBuffer* b) { node->LoadGame(t,b); }
bool CombatBehaviorTreeWrapperNode::Validate(const CombatBehaviorTreeNode* n) { return node->Validate(n); }
