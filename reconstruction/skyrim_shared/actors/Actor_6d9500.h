// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Actor, Actor::GetSoul: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
// Actor::currentProcess, Actor::GetLevel: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG places currentProcess at 0F0, this build has it at 0F8
// AIProcess: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Actor::GetSoulLevel: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
// AIProcess::Function728580, Actor::Function6acad0: GUESS(low)
// TESSoulGem, TESSoulGem::GetSoulLevel: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// TESSoulGem::GetSoulLevelValue: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstdint>

class AIProcess
{
public:
    bool Function728580();  // callee at 0x728580
};

class TESSoulGem
{
public:
    static std::uint32_t GetSoulLevel(std::uint16_t a_level, std::uint8_t a_flag);  // callee at 0x4221e0
    static std::uint32_t GetSoulLevelValue(std::uint32_t a_value);  // callee at 0x28ef80
};

class Actor
{
public:
    std::uint32_t GetSoul();  // compared: 0x6d9500
    std::uint16_t GetLevel();  // callee at 0x6797a0
    std::uint8_t Function6acad0();  // callee at 0x6acad0
    std::uint32_t GetSoulLevel();  // inlined into the compared function; the standalone copy is another function

    char pad000[0xF8];
    AIProcess* currentProcess;  // 0xF8
};

inline std::uint32_t Actor::GetSoulLevel()
{
    if (currentProcess && !currentProcess->Function728580()) {
        std::uint8_t flag = Function6acad0();
        return TESSoulGem::GetSoulLevel(GetLevel(), flag);
    }
    return 0;
}
