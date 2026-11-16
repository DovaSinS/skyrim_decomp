// PlayerCamera, build sse-steam-1-7-104.
// Labels: v2
// Origin: adapted declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// PlayerCamera: EXE_RTTI
// Compared functions:
// RVA 0x8fa270, 47 bytes: PlayerCamera::Function8fa270.
// RVA 0x8f94c0, 49 bytes: PlayerCamera::Function8f94c0.
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
#pragma once
#include <cstdint>
// PlayerCamera, TESCamera, BSTSmallArray, BSTArrayBase, BSTSmallArrayHeapAllocator, BSTSingletonSDM, BSTSmartPointer, NiPointer, BSSpinLock, BSTPoint2, BSTPoint3, NiPoint3, ObjectRefHandle, ActorHandle, Unk120, TESCameraState, cameraStates, currentState, tempReturnStates, unk165, SetState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Function8fa270, Function8f94c0, GetTargetState, ptr: GUESS(low)
class NiNode; class TESCameraState; class bhkRigidBody;
template<class T> class NiPointer { public: T* ptr; };
template<class T> class BSTSmartPointer { public: T* ptr; };
struct BSTArrayBase { std::uint32_t size; };
template<class T, std::uint32_t N> struct BSTSmallArrayHeapAllocator {
 std::uint32_t capacity:31; std::uint32_t local:1;
 union Data { void* heap; T localValues[N]; } data;
};
template<class T, std::uint32_t N> struct BSTSmallArray : BSTSmallArrayHeapAllocator<T,N>, BSTArrayBase {};
template<class T> struct BSTSingletonSDMOpStaticBuffer {};
template<class T, class Alloc = BSTSingletonSDMOpStaticBuffer<T>> struct BSTSDMTraits { using Type=T; using Allocator=Alloc; };
template<class Traits> struct BSTSingletonSDMBase : Traits, Traits::Allocator {};
template<class T> struct BSTSingletonSDM : BSTSingletonSDMBase<BSTSDMTraits<T>> {};
template<class T> struct BSTPoint2 { T x,y; };
template<class T> struct BSTPoint3 { T x,y,z; };
struct NiPoint3 { float x,y,z; };
struct BSSpinLock { volatile std::uint32_t owningThread, lockCount; };
struct ObjectRefHandle { std::uint32_t value; };
struct ActorHandle { std::uint32_t value; };
class TESCamera {
public:
 virtual ~TESCamera();
 void SetState(TESCameraState*);
 BSTPoint2<float> rotationInput;
 BSTPoint3<float> translationInput;
 float zoomInput;
 NiPointer<NiNode> cameraRoot;
 BSTSmartPointer<TESCameraState> currentState;
 bool enabled;
 std::uint8_t pad31;
 std::uint16_t pad32;
 std::uint32_t pad34;
};
class PlayerCamera : public TESCamera, public BSTSingletonSDM<PlayerCamera> {
public:
 TESCameraState* GetTargetState();
 void Function8fa270();
 void Function8f94c0();
 std::uint8_t pad039;
 std::uint16_t pad03A;
 ActorHandle cameraTarget;
 BSTSmallArray<TESCameraState*, 13> tempReturnStates;
 BSTSmartPointer<TESCameraState> cameraStates[13];
 struct Unk120;
 Unk120* unk120;
 NiPointer<bhkRigidBody> rigidBody;
 ObjectRefHandle objectFadeHandle;
 BSSpinLock lock;
 float worldFOV, firstPersonFOV;
 NiPoint3 pos;
 float idleTimer, yaw;
 std::uint32_t unk158, unk15C;
 bool allowAutoVanityMode, bowZoomedIn, isWeapSheathed, isProcessed;
 std::uint8_t unk164, unk165;
};
