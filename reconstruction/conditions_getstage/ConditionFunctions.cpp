// Build: sse-steam-1-7-104; RVA 0x3322e0; 111 bytes
// Labels: v2
// Source exposure: binary-analysis
// Origin: independently reconstructed from target observations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// names: GUESS(low); names and signatures are tentative.
// ConditionFunctions, ConditionFunctions::GetStage: GUESS(low); the static source container and original signature are unverified.
#include "ConditionFunctions.h"
class TESObjectREFR;
class TESQuest;
extern unsigned int GetQuestStage(TESQuest*);
extern void* conditionLogger;
extern const char conditionLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::GetStage(TESObjectREFR*, TESQuest* quest, void*, double* result)
{
    *result = 0.0;
    double value = 0.0;
    if (quest) {
        value = static_cast<float>(GetQuestStage(quest));
        *result = value;
    }
    if (conditionLoggingEnabled) LogCondition(conditionLogger, conditionLogFormat, value);
    return true;
}
