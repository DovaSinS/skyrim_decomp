// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BSNullImplGameSound: EXE_RTTI
// Unk_08: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// member, padding: GUESS(low); storage names invented for the measured member offset
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xcd6aa0 BSNullImplGameSound::Unk_08
// Code origin: original; the listing and community declarations only
// 0xcd6bf0 BSNullImplGameSound::Functioncd6bf0
// 0xcd6bc0 BSNullImplGameSound::Functioncd6bc0
#include "BSNullImplGameSound.h"

// Functioncd6bf0: GUESS(low)
void BSNullImplGameSound::Functioncd6bf0()
{
    flags5C &= ~std::uint32_t{0x60};
}
void BSNullImplGameSound::Functioncd6bc0()
{
    volatile std::uint32_t& f = flags5C;
    std::uint32_t v = f;
    v = (v & ~std::uint32_t{0x40}) | std::uint32_t{0x20};
    f = v;
}

// Unk_08: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
std::uint8_t BSNullImplGameSound::Unk_08() const
{
    return 0x1;
}
