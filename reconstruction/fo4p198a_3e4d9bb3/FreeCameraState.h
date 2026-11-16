// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/F/FreeCameraState.h, include/RE/T/TESCameraState.h, include/RE/P/PlayerInputHandler.h, include/RE/B/BSIntrusiveRefCounted.h, include/RE/N/NiMatrix3.h and include/RE/N/NiQuaternion.h.
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
#pragma once
struct NiPoint3 { float x,y,z; }; struct NiPoint2 { float x,y; }; class NiMatrix3 { public: float entry[3][3]; void FromEulerAnglesZXY(float,float,float); }; class NiQuaternion { public: void FromRotation(const NiMatrix3&); }; class TESCamera;
class BSIntrusiveRefCounted { public: virtual ~BSIntrusiveRefCounted(); unsigned refCount; }; class TESCameraState : public BSIntrusiveRefCounted { public: TESCamera* camera; unsigned id; }; class PlayerInputHandler { public: virtual ~PlayerInputHandler(); bool inputEventHandlingEnabled; };
class FreeCameraState : public TESCameraState, public PlayerInputHandler { public: NiPoint3 translation; NiPoint2 rotation, zUpDown; short verticalDirection; bool useRunSpeed, lockToZPlane; void GetRotation(NiQuaternion&) const; };
