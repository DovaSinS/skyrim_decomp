// BSFaceGenModel, build sse-steam-1-7-104.
// Labels: v2
// Origin: adapted public declarations from CommonLibSSE-NG, MIT, b93280e832f263dbef44e44cbe2936622a02f91a.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// BSFaceGenModel: EXE_RTTI
// Compared functions:
// RVA 0x435070, 48 bytes: BSFaceGenModel::Function435070.
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
#include "BSFaceGenModel.h"
BSFaceGenModel& BSFaceGenModel::Function435070(const BSFaceGenModel& rhs) {
 auto incoming = rhs.modelMeshData.ptr;
 auto previous = modelMeshData.ptr;
 if (incoming != previous) {
  // Shared mesh ownership requires an atomic reference increment.
  if (incoming) _InterlockedIncrement(&incoming->refCount);
  modelMeshData.ptr = incoming;
  ReleaseMesh(previous);
 }
 return *this;
}
