// Build: sse-steam-1-7-104
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Source exposure: mixed; binary analysis, CommonLibSSE-NG declarations and permitted FNV string code inspected.
// Code origin: original reconstruction; no external implementation code copied.
// Drafted by GPT-6.1 Sol (template and generator).
// Only the generated initializer and EH cleanup are compared; other implementations are bindings.
// Owning system and original types unknown; this is not a behaviour or naming claim.
// Labels: v2
// StringStaticc6270, StringSlot, value, input, NullStringInput, text, object: GUESS(low) STANDIN
#pragma once
extern const char text[];
struct StringSlot {
    const char* value;
    StringSlot(const char*);
    ~StringSlot();
};
struct NullStringInput {};
struct StringStaticc6270 {
    StringSlot value;
    // Require a non-null string argument. Member ownership covers failure of the input contract.
    explicit StringStaticc6270(const char* input) : value(input) { if (!input) throw NullStringInput{}; }
    ~StringStaticc6270() {}
};
