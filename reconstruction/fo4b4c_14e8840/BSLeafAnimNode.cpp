// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// RVA 0x14e8840, 19 bytes: BSLeafAnimNode::RegisterStreamables
// BSLeafAnimNode::RegisterStreamables: SIBLING(fo4-private@1b765c70, author-permission); adapted to the target call and boolean normalization.
// Sibling source: fo4-private@1b765c70 src/BSShader/BSLeafAnimNode.cpp:21
// names: GUESS(low); qualified name is unverified.
#include "BSLeafAnimNode.h"
bool BSLeafAnimNode::RegisterStreamables(NiStream& stream) { return NiNode::RegisterStreamables(stream) != 0; }
