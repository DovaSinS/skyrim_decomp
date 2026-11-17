// Build: sse-steam-1-7-104; RVA 0x33a010; 118 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// TESObjectREFR::HasKeywordHelper: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declaration in included header.
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::HasKeyword: GUESS(low); the static source container and original signature are unverified.
#pragma once
class BGSKeyword;
class TESObjectREFR;

class ConditionFunctions
{
public:
    static bool HasKeyword(TESObjectREFR* reference, BGSKeyword* keyword, void*, double* result);
};
