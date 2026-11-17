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
#include "ConditionFunctions.h"
#include "../fo4p198c_refr/TESObjectREFR.h"
extern void* conditionLogger;
extern const char keywordLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::HasKeyword(TESObjectREFR* reference, BGSKeyword* keyword, void*, double* result)
{
    *result = 0.0;
    if (reference && keyword && reference->HasKeywordHelper(keyword)) *result = 1.0;
    if (conditionLoggingEnabled) LogCondition(conditionLogger, keywordLogFormat, *result);
    return true;
}
