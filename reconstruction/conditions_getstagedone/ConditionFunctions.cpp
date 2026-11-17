// Build: sse-steam-1-7-104; RVA 0x332360; 119 bytes
// Labels: v2
// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetStageDone: GUESS(low); the static source container and original signature are unverified.
#include "ConditionFunctions.h"
class TESObjectREFR;
class TESQuest;
extern bool QuestStageDone(TESQuest*, unsigned short);
extern void* conditionLogger;
extern const char stageDoneLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::GetStageDone(TESObjectREFR*, TESQuest* quest, unsigned short stage, double* result)
{
    *result = 0.0;
    if (quest && QuestStageDone(quest, stage)) *result = 1.0;
    if (conditionLoggingEnabled) LogCondition(conditionLogger, stageDoneLogFormat, *result);
    return true;
}
