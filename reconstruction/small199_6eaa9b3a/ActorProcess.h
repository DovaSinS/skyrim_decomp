// ActorProcess, build sse-steam-1-7-104.
// Labels: v2
// ActorProcess, Function6e9a20, Check, GetData: GUESS(low)
// middleLow, middleHigh, high, currentPackage, packageLock, package, data, ActorPackage, ActorPackageData, MiddleLowProcessData, MiddleHighProcessData, HighProcessData, TESPackage: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Inferred names: GUESS(low)
// Origin: original body and partial public prefix adapted from CommonLibSSE-NG, MIT.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x6e9a20, 42 bytes: ActorProcess::Function6e9a20.
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
// ActorProcess, Function6e9a20, Check, GetData: GUESS(low)
// middleLow, middleHigh, high, currentPackage, packageLock, package, data, ActorPackage, ActorPackageData, MiddleLowProcessData, MiddleHighProcessData, HighProcessData, TESPackage: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class MiddleLowProcessData; class MiddleHighProcessData; class HighProcessData; class TESPackage; class ActorPackageData;
struct ActorPackage { std::uint32_t packageLock; TESPackage* package; ActorPackageData* data; };
class ActorProcess {
public:
    void* Check();
    ActorPackageData* GetData();
    ActorPackageData* Function6e9a20();
    MiddleLowProcessData* middleLow;
    MiddleHighProcessData* middleHigh;
    HighProcessData* high;
    ActorPackage currentPackage;
};
