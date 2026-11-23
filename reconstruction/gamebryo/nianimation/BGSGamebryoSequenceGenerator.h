// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BGSGamebryoSequenceGenerator: EXE_RTTI
// Unk_18: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Functionbaf630, Functionbafba0, pad, field68, field68Float, field6C: GUESS(low); storage names invented for the measured member offsets
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
// Unk_18: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BGSGamebryoSequenceGenerator
{
public:
    virtual std::uint8_t Unk_18() const;
    // BGSGamebryoSequenceGenerator::Functionbaf630: GUESS(low); resets the two state fields at 0x68 and 0x6C
    void Functionbaf630();
    // BGSGamebryoSequenceGenerator::Functionbafba0: stores the incoming float at 0x68
    void Functionbafba0(float a_value);

private:
    std::uint64_t pad[0x68 / 8 - 1];  // 08 .. 68
    union {
        float         field68Float;  // 68
        std::uint32_t field68;       // 68
    };
    std::uint8_t field6C;   // 6C
};
