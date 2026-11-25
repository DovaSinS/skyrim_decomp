// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original; the listing and community declarations
// 0x150e330 ShadowSceneNode::QueueLightRemove
// 0x150cf20 ShadowSceneNode::AttachObject
// 0x150d120 ShadowSceneNode::QueueLightAdd
#include "ShadowSceneNode_R5A1.h"
#include <intrin.h>

// Adapted bodies: BSSpinLock::Unlock (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp, MIT) inlined
// The lock release is inlined into every guard, as the engine does.
void BSSpinLock::Unlock()
{
    _mm_lfence();  // ordering: serialise earlier loads before reading the owner
    std::uint32_t myThreadID = GetCurrentThreadId();

    if (owningThread == myThreadID) {
        if (lockCount == 1) {
            owningThread = 0;
            _mm_mfence();  // ordering: publish the cleared owner before releasing the count
            // atomic release: other threads spin on this count
            _InterlockedCompareExchange(reinterpret_cast<volatile long*>(&lockCount), 0, 1);
        } else {
            // atomic release: other threads spin on this count
            _InterlockedDecrement(reinterpret_cast<volatile long*>(&lockCount));
        }
    }
}

// QueueLightRemove, AttachObject, QueueLightAdd: CRASHLOGGER_PDB(59818@2026.10.24)
void ShadowSceneNode::QueueLightRemove(BSLight* a_light)
{
    if (a_light) {
        BSAutoLock lock(&lightQueueLock);
        MemoryContextScope scope(0x41);
        lightQueueRemove.Append(a_light);
    }
}

void ShadowSceneNode::AttachObject(NiAVObject* a_object)
{
    if (a_object) {
        // NiAVObject::flags at 0xF4: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
        if (!(a_object->unknown30[0xF4 - 0x30] & 1)) {
            BSAutoLock lock(&objectListLock);
            MemoryContextScope scope(0x20);
            particleNodes.Append(a_object);
        }
    }
}

void ShadowSceneNode::QueueLightAdd(const NiPointer<BSLight>& a_light)
{
    if (a_light.m_pObject && allowLightRemoveQueues) {
        BSAutoLock lock(&lightQueueLock);
        MemoryContextScope scope(0x1D);
        queuedRemove.Add(a_light);
    }
}

