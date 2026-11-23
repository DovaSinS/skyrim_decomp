// Source exposure: binary-analysis (names from CrashLogger output; shapes from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// PlayerCharacter::Function66fc60: CRASHLOGGER_PDB(59818@2026.10.24) GUESS(low); placeholder name for PlayerCharacter::sub_1405CCE30
// ActorProcess::GetEquippedLeftHand: CRASHLOGGER_PDB(59818@2026.10.24); callee name from CrashLogger output; NG names it on AIProcess
// ActorProcess::Function6eb4b0: CRASHLOGGER_PDB(59818@2026.10.24) GUESS(low); callee placeholder, declared as a stand-in
// FormLike, FormLike::formType: GUESS(low); stand-in for a form with its type byte at 0x1A
#pragma once

#include <cstdint>
#include <cstddef>

class FormLike
{
public:
    std::uint8_t unk00[0x1A];
    std::uint8_t formType;
};

class ActorProcess
{
public:
    FormLike* GetEquippedLeftHand();
    FormLike* Function6eb4b0();
};

class PlayerCharacter
{
public:
    FormLike* Function66fc60(const std::uint32_t* a_hand);

    std::uint8_t unk00[0xF8];
    ActorProcess* unkF8;
};
