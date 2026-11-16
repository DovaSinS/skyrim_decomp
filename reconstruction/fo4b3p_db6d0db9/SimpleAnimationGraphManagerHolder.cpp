// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x556670, 69 bytes: SimpleAnimationGraphManagerHolder::SetAnimationGraphManagerImpl
// SimpleAnimationGraphManagerHolder::SetAnimationGraphManagerImpl: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Shared/Animation/SimpleAnimationGraphManagerHolder.cpp:73
// RVA 0x556610, 76 bytes: SimpleAnimationGraphManagerHolder::GetAnimationGraphManagerImpl
// SimpleAnimationGraphManagerHolder::GetAnimationGraphManagerImpl: SIBLING(fo4-private@1b765c70, author-permission); adaptation
// Sibling source: fo4-private@1b765c70 src/Shared/Animation/SimpleAnimationGraphManagerHolder.cpp:66
#include "SimpleAnimationGraphManagerHolder.h"
bool SimpleAnimationGraphManagerHolder::GetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>& out) const { out=animationGraphManager; return out.ptr != nullptr; }
bool SimpleAnimationGraphManagerHolder::SetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>& in) { animationGraphManager=in; return true; }
