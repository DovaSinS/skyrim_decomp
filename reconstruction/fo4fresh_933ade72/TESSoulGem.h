// TESSoulGem, build sse-steam-1-7-104.
// Labels: v2
// RVA 0x28ef80, 63 bytes: TESSoulGem::GetSoulLevelValue
// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESSoulGem.cpp:135 (TESSoulGem::GetSoulLevelValue)
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Drafted by gpt-6.1-terra.
// TESSoulGem, GetSoulLevelValue: GUESS(low)
#pragma once
// soul, petty, lesser, common, greater, grand, SOUL_LEVEL: GUESS(low)
enum SOUL_LEVEL { PETTY = 1, LESSER, COMMON, GREATER, GRAND };
class TESSoulGem { public: static unsigned int petty, lesser, common, greater, grand; static unsigned int GetSoulLevelValue(SOUL_LEVEL soul); };
