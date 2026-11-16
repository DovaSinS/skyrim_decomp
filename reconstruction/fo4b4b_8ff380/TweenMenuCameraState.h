// Build: sse-steam-1-7-104; RVA 0x8ff380; 14 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// TweenMenuCameraState::End: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/TweenMenuCameraState.cpp:37
// TweenMenuCameraState: COMMUNITY(powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944, GPL-3.0); declaration adapted from include/RE/T/TweenMenuCameraState.h.
// The declaration derived from powerof3/CommonLibSSE is GPL-3.0.
// PlayerCamera, TESCameraState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/P/PlayerCamera.h, include/RE/T/TESCamera.h, include/RE/T/TESCameraState.h and include/RE/B/BSTArray.h and include/RE/B/BSAtomic.h.
// names: GUESS(low); names and original signatures are tentative.
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
struct Point2 { float x,y; }; struct Point3 { float x,y,z; }; struct Quaternion { float w,x,y,z; };
class TESCameraState;
class TESCamera { public: virtual ~TESCamera(); Point2 rotationInput; Point3 translationInput; float zoomInput; void* cameraRoot; TESCameraState* currentState; bool enabled; unsigned char pad31; unsigned short pad32; unsigned pad34; };
class Singleton {};
struct SmallStates { unsigned capacity:31, local:1; union { TESCameraState** heap; TESCameraState* localData[13]; }; unsigned size; };
class PlayerCamera : public TESCamera, public Singleton { public: unsigned char pad39; unsigned short pad3a; unsigned cameraTarget; SmallStates tempReturnStates; TESCameraState* cameraStates[13]; void* unknown120; void* rigidBody; unsigned objectFadeHandle; struct SpinLock { unsigned owningThread, lockCount; } lock; float worldFOV; };
class TESCameraState { public: virtual ~TESCameraState(); unsigned refCount, pad; TESCamera* camera; unsigned id, pad2; };
class TweenMenuCameraState : public TESCameraState { public: Quaternion initialRotation; float initialFOV; Point2 currentAddedRot, targetAddedRot; float currentAddedFOV, targetAddedFOV; bool endingState; void End(); };
