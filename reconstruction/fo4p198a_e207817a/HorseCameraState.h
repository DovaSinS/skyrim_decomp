// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/H/HorseCameraState.h, include/RE/T/ThirdPersonState.h, include/RE/T/TESCameraState.h, include/RE/P/PlayerInputHandler.h.
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
// names: GUESS(low); target callees and signatures are inferred independently from the target call sequence.
// PlayerControls and PlayerControlsData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted from include/RE/P/PlayerControls.h, include/RE/P/PlayerControlsData.h and include/RE/B/BSTEvent.h.
#pragma once
struct NiPoint3 { float x,y,z; }; struct NiPoint2 { float x,y; }; struct NiQuaternion { float w,x,y,z; }; class TESCamera; class NiAVObject; class NiNode; class BGSLoadFormBuffer;
class BSIntrusiveRefCounted { public: virtual ~BSIntrusiveRefCounted(); unsigned refCount; }; class TESCameraState : public BSIntrusiveRefCounted { public: TESCamera* camera; unsigned id; }; class PlayerInputHandler { public: virtual ~PlayerInputHandler(); bool inputEventHandlingEnabled; };
class ThirdPersonState : public TESCameraState, public PlayerInputHandler { public:
 void End(); void Revert(BGSLoadFormBuffer*);
 NiAVObject* thirdPersonCameraObj; NiNode* thirdPersonFOVControl; NiPoint3 translation; NiQuaternion rotation; NiPoint3 posOffsetExpected, posOffsetActual; float targetZoomOffset,currentZoomOffset,targetYaw,currentYaw,savedZoomOffset,pitchZoomOffset,unk8C; NiPoint3 collisionPos; float collisionPosValid; unsigned long long unkA0; const char* animatedBoneName; NiQuaternion animationRotation; unsigned long long unkC0,unkC8; unsigned unkD0; NiPoint2 freeRotation; bool freeRotationEnabled,stateNotActive; unsigned short unkDE; bool toggleAnimCam,applyOffsets; unsigned short unkE2; unsigned unkE4;
};
template<class T> class BSTEventSink { public: virtual ~BSTEventSink(); }; class InputEvent; class MenuOpenCloseEvent; class MenuModeChangeEvent; class TESFurnitureEvent;
struct PlayerControlsData { NiPoint2 moveInputVec, lookInputVec, prevMoveVec, prevLookVec; unsigned unk20; bool autoMove, running; unsigned char unk26; bool fovSlideMode; bool povScriptMode,povBeastMode; unsigned char unk2A,unk2B; bool remapMode; };
class PlayerControls : public BSTEventSink<InputEvent*>, public BSTEventSink<MenuOpenCloseEvent>, public BSTEventSink<MenuModeChangeEvent>, public BSTEventSink<TESFurnitureEvent> { public: unsigned char singletonState; PlayerControlsData data; };
extern PlayerControls* playerControls;
extern unsigned nullHandle;
class HorseCameraState : public ThirdPersonState { public: unsigned horseRefHandle; float horseCurrentDirection; bool atMaxHorseAngle; void End(); void Revert(BGSLoadFormBuffer*); bool GetFreeRotationMode() const; };

