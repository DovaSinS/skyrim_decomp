// Source exposure: mixed (community headers; compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// BSFaceGenModel, modelMeshData, unk18, pad1C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiRefObject, BSFaceGenModelMeshData, BSTSmartPointer: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ms_totalObjects: GUESS(low); the name comes from the pack reference table
// refCount: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

class NiRefObject
{
public:
    NiRefObject()
    {
        _refCount = 0;
        _InterlockedIncrement(&ms_totalObjects);  // total live objects is shared by every thread
    }
    virtual ~NiRefObject();
    virtual void DeleteThis();

    static volatile long ms_totalObjects;

    volatile std::uint32_t _refCount;
    std::uint32_t _pad0C;
};

class BSFaceGenModelMeshData
{
public:
    volatile long refCount;
};

template <class T>
class BSTSmartPointer
{
public:
    T* ptr;
};

class BSFaceGenModel : public NiRefObject
{
public:
    BSFaceGenModel(const BSFaceGenModel& rhs);
    ~BSFaceGenModel() override;

    BSTSmartPointer<BSFaceGenModelMeshData> modelMeshData;
    std::uint32_t unk18;
    std::uint32_t pad1C;
};
