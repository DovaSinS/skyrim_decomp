// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original reconstruction from the pinned image listing
// 0x155c850 BSShadowLight::SetShadowmapCount
// 0x155c590 BSShadowLight::~BSShadowLight
// 0x155d890 BSShadowLight::`scalar deleting destructor'
// CI hash: 0x155c590 ??1BSShadowLight@@UEAA@XZ
// CI hash: 0x155c850 ?SetShadowmapCount@BSShadowLight@@QEAAXI@Z
// CI hash: 0x155d890 ??_GBSShadowLight@@UEAAPEAXI@Z
// Adapted bodies: none
#include "BSShadowLight_R5PCallers.h"

// SetShadowmapCount, ~BSShadowLight: CRASHLOGGER_PDB(59818@2026.10.24)
void BSShadowLight::SetShadowmapCount(std::uint32_t a_count)
{
    if (a_count > shadowMapCount) {
        shadowmapDescriptors.SetSize(a_count);
        for (std::uint32_t i = shadowMapCount; i < a_count; ++i) {
            shadowmapDescriptors[i].unkCC = 1.0f;
            shadowmapDescriptors[i].unkE8 = 1;
            shadowmapDescriptors[i].shaderAccumulator = nullptr;
            shadowmapDescriptors[i].cullingProcess = nullptr;
        }
    } else if (a_count < shadowMapCount) {
        for (std::uint32_t i = a_count; i < shadowMapCount - 1; ++i) {
            ReleaseShadowmapDescriptor(i);
        }
        shadowmapDescriptors.SetSize(a_count);
    }
    shadowMapCount = a_count;
}

BSShadowLight::~BSShadowLight()
{
    for (std::uint32_t i = 0; i < shadowMapCount; ++i) {
        ReleaseShadowmapDescriptor(i);
    }
}
