// Build: sse-steam-1-7-104; RVA 0x3342c0; 119 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently reconstructed from target observations and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// Form and TESGlobal fields: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/T/TESForm.h and include/RE/T/TESGlobal.h.
// names: GUESS(low); names and signatures are tentative.
// MIT License
//
// Copyright (c) 2018 Ryan-rsm-McKenzie
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// ConditionFunctions, ConditionFunctions::GetGlobalValue: GUESS(low); the static source container and original signature are unverified.
#include "ConditionFunctions.h"
class TESObjectREFR;
struct Form {
    void* virtualTable;
    void* sourceFiles;
    unsigned int formFlags, formID;
    unsigned short inGameFlags;
    unsigned char formType, pad1b;
    unsigned int pad1c;
};
struct BSString { char* data; unsigned short size, capacity; };
struct TESGlobal : Form { BSString editorID; unsigned char type, pad31; unsigned short pad32; float value; };
extern void* conditionLogger;
extern const char globalLogFormat[];
extern thread_local bool conditionLoggingEnabled;
extern void LogCondition(void*, const char*, ...);
bool ConditionFunctions::GetGlobalValue(TESObjectREFR*, Form* parameter, void*, double* result)
{
    *result = -1.0;
    TESGlobal* global = nullptr;
    if (parameter && parameter->formType == 9) global = static_cast<TESGlobal*>(parameter);
    double value = -1.0;
    if (global) { value = global->value; *result = value; }
    if (conditionLoggingEnabled) LogCondition(conditionLogger, globalLogFormat, value);
    return true;
}
