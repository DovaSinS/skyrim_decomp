// Source exposure: mixed (community headers and the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ShadowSceneNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// activeLights, shadowCasterLights, sceneGraphIndex: CRASHLOGGER_PDB(59818@2026.10.24)
// queue arrays, padding: GUESS(low); shapes measured from the listing
// Code origin: original reconstruction from the pinned image listing
#pragma once

#include "ShadowKit.h"

class ShadowSceneNode : public NiNode
{
public:
    void ClearShadowCasterArray();
    BSShadowLight* GetShadowCasterLightArrayEntry(std::uint32_t a_index);
    BSLight* GetActiveLightAt(std::uint32_t a_index);
    BSLight* GetShadowCasterLightByIndex(std::uint32_t a_index);
    // noinline: the engine calls this out of line from its callers
    __declspec(noinline) BSLight* FindActiveLight(NiLight* a_light);
    BSLight* FindQueuedAddLight(NiLight* a_light);
    std::uint16_t CountLitShadowLights();
    BSLight* AddLight(NiLight* a_light, bool a_flag);
    void AddLight(BSLight* a_light);
    BSLight* AddLight(NiLight* a_light, LIGHT_CREATE_PARAMS* a_params);
    void ClearLights_Flagged(bool a_clear, bool a_keepArrays);
    // noinline: the engine calls this out of line from its callers
    __declspec(noinline) void ClearLightArrays();
    void RemoveLightByNode(NiLight* a_light);
    // noinline: the engine calls this out of line from its callers
    __declspec(noinline) void QueueLightAdd(const NiPointer<BSLight>& a_light);
    // noinline: the engine calls this out of line from its callers, which tail-call it
    __declspec(noinline) void QueueLightRemove(BSLight* a_light);
    void TryQueueLightRemove(NiLight* a_light);
    void AttachObject(NiAVObject* a_object);
    void ClearShadowLightShadowmaps();
    void UnlinkLightFromPortalGraph(NiAVObject* a_object);
    void UnlinkChildLights(NiNode* a_node);
    void CollectLightingShaderGeometry(void* a_visitor);
    void CollectLitGeometry();

    std::uint8_t unknown128[8];
    BSTArray<NiPointer<BSLight>> activeLights;  // 130
    BSTArray<NiPointer<BSLight>> shadowLights;  // 148
    BSTArray<NiPointer<BSLight>> queuedAdd;  // 160
    BSTArray<NiPointer<BSLight>> queuedRemove;  // 178
    ShadowLightArray lightQueueRemove;  // 190
    BSSpinLock lightQueueLock;  // 1A8
    std::uint8_t unknown1B0[0x1C8 - 0x1B0];
    ShadowObjectArray particleNodes;  // 1C8
    std::uint8_t unknown1E0[0x1F8 - 0x1E0];
    BSSpinLock objectListLock;  // 1F8
    std::uint8_t unknown200[0x210 - 0x200];
    BSShadowDirectionalLight* shadowDirLight;  // 210
    std::uint8_t sceneGraphIndex;  // 218
    std::uint8_t unknown219[0x228 - 0x219];
    BSPortalGraph* portalGraph;  // 228
    BSTArray<BSShadowLight*> shadowCasterLights;  // 230
    std::uint8_t unknown248[0x300 - 0x248];
    bool allowLightRemoveQueues;  // 300
    std::uint8_t unknown301[0x308 - 0x301];
};
static_assert(sizeof(ShadowSceneNode) == 0x308, "ShadowSceneNode size");
