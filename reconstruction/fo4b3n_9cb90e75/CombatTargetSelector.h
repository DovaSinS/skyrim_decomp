// Build: sse-steam-1-7-104
// CombatTargetSelector::GetObjectType, build sse-steam-1-7-104, RVA 0x861f40, 121 bytes.
// Labels: v2
// Source exposure: mixed (pinned image listing and anonymous sibling hints).
// Origin: original reconstruction using target listing and anonymous sibling hints.
// GetObjectType: SIBLING(fo4-private@1b765c70, author-permission); src/Game/AI/Combat/CombatTargetSelector.cpp:102; adapted behavior.
// Semantic names and signatures: GUESS(low); static type-name literal and generator inferred from target and related reconstructions.
// Evidence: findings/ghidra-import.md; Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
#pragma once
class CombatObjectBase { public: static unsigned int GenerateClassType(const char*); };
class CombatTargetSelector { public: unsigned int GetObjectType() const; };
