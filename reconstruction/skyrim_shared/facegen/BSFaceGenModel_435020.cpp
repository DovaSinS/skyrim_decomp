// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x435020 BSFaceGenModel::BSFaceGenModel
// Adapted bodies: none
#include "BSFaceGenModel_435020.h"

BSFaceGenModel::BSFaceGenModel(const BSFaceGenModel& rhs)
{
    modelMeshData.ptr = rhs.modelMeshData.ptr;
    if (rhs.modelMeshData.ptr) {
        _InterlockedIncrement(&rhs.modelMeshData.ptr->refCount);  // shared mesh data is reference counted atomically
    }
    unk18 = 0;
}
