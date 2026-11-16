// BGSProjectile declarations for build sse-steam-1-7-104.
// Labels: v2
// Origin: declarations adapted from labelled pinned community headers and target-specific partial declarations.
// Task: p177fb-38ff5fbe
// Source exposure: mixed (pinned target listing and sibling hints).
// BGSProjectile, BGSProjectile::ClearData: GUESS(low)
// BGSProjectile fields: STANDIN GUESS(low)
// Model: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); TESModel virtual slots.
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
class Model { public: virtual ~Model() = default; virtual void InitializeDataComponent(); virtual void ClearDataComponent(); };
class BGSProjectile {
public: void ClearData();
private: std::uint8_t pad[0x108]; Model muzzleFlashModel;
};
