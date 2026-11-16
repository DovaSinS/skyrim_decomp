// Character, build sse-steam-1-7-104.
// Labels: v2
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis.
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x868f80, 44 bytes: Character::Function868f80.
// Character, Function868f80, CheckReference, OtherReference, CheckOther: GUESS(low)
// Character, OtherReference: STANDIN GUESS(low)
#pragma once
class OtherReference {
public:
 bool CheckOther();
};
class Character {
public:
 bool CheckReference();
 bool Function868f80(OtherReference* a_other);
};
