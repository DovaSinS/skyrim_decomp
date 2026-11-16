// Character, build sse-steam-1-7-104.
// Labels: v2
// Character, Point3, x, y, z, Value, Compute, Function685c00, Function68ab20, PrecacheData, Lookup, Apply, Start, Continue, Finish: GUESS(low)
// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis only).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x685c00, 38 bytes: Character::sub.
// RVA 0x73a9f0, 40 bytes: Character::PrecacheData.
// RVA 0x68ab20, 41 bytes: Character::sub.

#pragma once
// Character, Point3, x, y, z, Value, Compute, Function685c00, Function68ab20, PrecacheData, Lookup, Apply, Start, Continue, Finish: GUESS(low)
struct Point3 { float x, y, z; };
class Value { public: void Apply(void*); };
class Character {
public:
    float Compute(float);
    Value* Lookup();
    void Start();
    void Continue();
    void Finish(int, int);
    bool Function685c00(Point3*, void*, float);
    void Function68ab20(void*);
    void PrecacheData();
};
