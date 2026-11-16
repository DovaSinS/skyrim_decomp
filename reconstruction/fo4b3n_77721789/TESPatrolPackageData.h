// Build: sse-steam-1-7-104
// TESPatrolPackageData functions, build sse-steam-1-7-104.
// RVA 0x4a10d0, 69 bytes: Copy; RVA 0x4a1120, 83 bytes: Compare; RVA 0x4a11f0, 68 bytes: LoadGame.
// Labels: v2
// Source exposure: mixed (pinned image listing, public declarations and anonymous sibling hints).
// Origin: original reconstruction using target listing and anonymous sibling hints.
// Copy: SIBLING(fo4-private@1b765c70, author-permission); src/Shared/AI/PackageDataPatrol.cpp:42; adapted cast and copy.
// Compare: SIBLING(fo4-private@1b765c70, author-permission); src/Shared/AI/PackageDataPatrol.cpp:54; adapted cast and comparison.
// LoadGame: SIBLING(fo4-private@1b765c70, author-permission); src/Shared/AI/PackageDataPatrol.cpp:89; adapted two loads.
// Evidence: findings/ghidra-import.md; Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// TESPackageData and virtual declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); adapted declarations.
// TESPatrolPackageData: GUESS(low); qualified-name hint, target type name unverified.
// Field names and semantics: GUESS(low); from target accesses and sibling, signatures unverified.
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
class TESForm;
class BGSLoadFormBuffer { public: void LoadDataEndian(void*, unsigned int, unsigned int); };
class TESPackageData { public: virtual std::uint8_t Compare() const; virtual void Copy(TESPackageData*, TESForm*); virtual void InitItem(TESForm*); virtual void LoadGame(BGSLoadFormBuffer*); };
class TESPatrolPackageData : public TESPackageData { public: void Copy(TESPackageData*, TESForm*) override; bool Compare(TESPackageData*); void LoadGame(BGSLoadFormBuffer*) override; bool repeatable; bool startAtNearestPoint; };
