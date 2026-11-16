// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/B/bhkCharacterController.h, BSBound.h, BSTEvent.h, BSTArray.h and RE/H/hkStepInfo.h, hkpCharacterControl.h, hkpCharacterContext.h, hkReferencedObject.h, RE/N/NiExtraData.h.
// MIT License
// 
// Copyright (c) 2018 Ryan-rsm-McKenzie
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// names: GUESS(low); scene global and method identity inferred from target.
#pragma once
#include <cstddef>
struct alignas(16) hkVector4 { float x,y,z,w; }; struct alignas(16) hkStepInfo { float startTime,endTime,deltaTime,invDeltaTime; };
template<class T> struct ArrayAllocator { T* data; unsigned capacity; }; struct ArrayBase { unsigned size; }; template<class T> struct Array : ArrayAllocator<T>, ArrayBase {};
class NiRefObject { public: virtual ~NiRefObject(); unsigned refCount; }; class NiExtraData : public NiRefObject { public: const char* name; };
class BSBound : public NiExtraData { public: struct Point3 { float x,y,z; } center, extents; };
struct EventSource { Array<void*> sinks, pendingRegisters, pendingUnregisters; unsigned owningThread, lockCount; bool notifying; };
struct hkpSurfaceInfo { unsigned supportedState, pad04; unsigned long long pad08; hkVector4 surfaceNormal, surfaceVelocity; float surfaceDistanceExcess; bool surfaceIsDynamic; unsigned long long pad38; };
class hkReferencedObject { public: virtual ~hkReferencedObject(); unsigned short memSizeAndFlags; short referenceCount; unsigned pad0C; };
class hkpCharacterStateManager; class hkpCharacterContext : public hkReferencedObject { public: unsigned characterType; hkpCharacterStateManager* stateManager; unsigned currentState, previousState; bool filterEnable; float maxLinearAcceleration, maxLinearVelocity, gain; };
class bhkICharOrientationController;
class bhkCharacterController : public NiRefObject, public EventSource { public: hkVector4 forwardVec; hkStepInfo stepInfo; hkVector4 outVelocity, initialVelocity, velocityMod, direction, rotCenter, pushDelta, fakeSupportStart, up, supportNorm; BSBound collisionBound, bumperCollisionBound; unsigned long long unk180, unk188; bhkICharOrientationController* orientationCtrl; unsigned long long pad198; hkpSurfaceInfo surfaceInfo; hkpCharacterContext context; unsigned flags; };
static_assert(offsetof(bhkCharacterController, flags)==0x218, "flags offset");
extern int sceneIsComplex;
class Actor { public: void UpdateCharacterControllerSimulationSettings(bhkCharacterController&); };
