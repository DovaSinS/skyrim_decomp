// BGSEntryPointPerkEntry declarations for build sse-steam-1-7-104.
// Labels: v2
// Origin: declarations adapted from labelled pinned community headers and target-specific partial declarations.
// Task: p177fb-0a327370
// Source exposure: mixed (pinned target listing and sibling hints).
// BGSEntryPointPerkEntry, BGSEntryPointPerkEntry::SetParent: GUESS(low)
// BGSEntryPointPerkEntry fields: STANDIN GUESS(low)
// Supporting types: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot order from the pinned community headers.
// MIT License
//
// Copyright (c) 2018 Ryan-rsm-McKenzie
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
class Perk; class File;
class FunctionData { public: virtual ~FunctionData() = default; virtual int GetType() const; virtual bool LoadFunctionData(File*); virtual void ResolveForms(File*); virtual void Unk04(); virtual void Unk05(); virtual void SetPerk(Perk*); };
class BGSEntryPointPerkEntry {
public: void SetParent(Perk* value);
private: std::uint8_t pad[0x18]; FunctionData* functionData; std::uint8_t gap[8]; Perk* parent;
};
