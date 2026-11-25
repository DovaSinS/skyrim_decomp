// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original reconstruction from the pinned image listing
// 0x155dc00 BSTArray<ShadowmapDescriptor, BSTArrayHeapAllocator>::SetSize
// 0x155d970 BSTArray<ShadowmapDescriptor, BSTArrayHeapAllocator>::Clear
// 0x155c750 BSShadowLight::ReleaseShadowmapDescriptor
// CI hash: 0x155c750 ?ReleaseShadowmapDescriptor@BSShadowLight@@QEAAXI@Z
// CI hash: 0x155d970 ?Clear@?$BSTArray@UShadowmapDescriptor@@VBSTArrayHeapAllocator@@@@QEAAX_N@Z
// CI hash: 0x155dc00 ?SetSize@?$BSTArray@UShadowmapDescriptor@@VBSTArrayHeapAllocator@@@@QEAA_NI@Z
// Adapted bodies: none
#include "BSShadowLight_R5PCallees.h"

// g_freeShadowmapMask: GUESS(low); a bit per shadowmap slot that is free to hand out
extern std::uint32_t g_freeShadowmapMask;

// The descriptor destructor body is visible to the array code below, which releases the member smart pointers in place.
ShadowmapDescriptor::~ShadowmapDescriptor()
{
}

// SetSize and Clear are defined here, apart from the callers, as the engine's array code lives in its own unit.
template <class T, class A>
bool BSTArray<T, A>::SetSize(std::uint32_t aiSize)
{
    bool bResult = true;
    if (aiSize == 0) {
        T* pItem = static_cast<T*>(A::QBuffer());
        if (pItem) {
            std::uint32_t count = this->iSize;
            for (std::uint32_t i = 0; i < count; ++i) {
                pItem->~T();
                ++pItem;
            }
        }
    } else if (aiSize == this->iSize) {
        bResult = true;
    } else if (aiSize > QAllocSize()) {
        if (!QAllocSize()) {
            bResult = A::Allocate(aiSize, sizeof(T));
        } else {
            bResult = A::Reallocate(aiSize, this->iSize, 0, 0, sizeof(T));
        }
        if (bResult) {
            ConstructDefaultItems(this->iSize, aiSize - this->iSize);
        }
    } else if (aiSize < this->iSize) {
        DestructItems(aiSize, this->iSize - aiSize);
    } else {
        ConstructDefaultItems(this->iSize, aiSize - this->iSize);
    }
    if (bResult) {
        this->iSize = aiSize;
    }
    return bResult;
}

template <class T, class A>
void BSTArray<T, A>::Clear(bool abFree)
{
    if (A::QBuffer()) {
        std::uint32_t count = this->iSize;
        T* pItem = static_cast<T*>(A::QBuffer());
        for (std::uint32_t i = 0; i < count; ++i) {
            pItem->~T();
            ++pItem;
        }
        if (abFree) {
            A::Deallocate();
        }
        this->iSize = 0;
    }
}

template bool BSTArray<ShadowmapDescriptor, BSTArrayHeapAllocator>::SetSize(std::uint32_t);
template void BSTArray<ShadowmapDescriptor, BSTArrayHeapAllocator>::Clear(bool);

// ReleaseShadowmapDescriptor, SetShadowmapCount, ~BSShadowLight: CRASHLOGGER_PDB(59818@2026.10.24)
void BSShadowLight::ReleaseShadowmapDescriptor(std::uint32_t a_index)
{
    if (shadowmapDescriptors[a_index].renderTarget != -1) {
        g_freeShadowmapMask |= 1 << shadowmapDescriptors[a_index].shadowmapIndex;
        shadowmapDescriptors[a_index].renderTarget = -1;
        shadowmapDescriptors[a_index].shaderAccumulator = nullptr;
        shadowmapDescriptors[a_index].camera = nullptr;
        if (shadowmapDescriptors[a_index].cullingProcess != cullingProcess) {
            if (shadowmapDescriptors[a_index].cullingProcess) {
                shadowmapDescriptors[a_index].cullingProcess->Unk_15(1);
            }
            shadowmapDescriptors[a_index].cullingProcess = nullptr;
        }
    }
}
