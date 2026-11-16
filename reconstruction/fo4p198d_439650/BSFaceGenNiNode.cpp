// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: independently decoded target and anonymous sibling; declarations adapted from community headers.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x439650, 67 bytes: BSFaceGenNiNode::UpdateDownwardPass
// BSFaceGenNiNode::UpdateDownwardPass: SIBLING(fo4-private@1b765c70, author-permission); adapted to target calls.
// Sibling source: fo4-private@1b765c70 src/Shared/FaceGen/BSFaceGenNiNode.cpp:156
// names: GUESS(low); signatures and helper identities need independent review.
#include "BSFaceGenNiNode.h"
void BSFaceGenNiNode::UpdateDownwardPass(NiUpdateData& data, unsigned flagsValue) { if ((flags & 1) == 0) UpdateMorphing(data); NiNode::UpdateDownwardPass(data, flagsValue); }
