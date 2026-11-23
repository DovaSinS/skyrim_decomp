// Source exposure: binary-analysis (pinned image listing only).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1002970 BSPSysStripUpdateModifier::LoadBinary
// Adapted bodies: none
#include "BSPSysStripUpdateModifier_1002970.h"

void BSPSysStripUpdateModifier::LoadBinary(NiStream& stream)
{
    NiPSysModifier::LoadBinary(stream);
    unk18 = 8000;
    NiStreamBinarySource* source = stream.source298;
    std::uint32_t count = 4;
    source->position08 += static_cast<std::uint32_t>(source->read10(source, &fUpdateDeltaTime, 4, &count, 1));
}
