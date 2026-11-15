// Build: sse-steam-1-7-104
// Source exposure: mixed (local access, copy, RTTI and size evidence).
// Drafted by GPT-6.1 Sol; p144 box2, owner awarebayes, 2026-11-15.
// Evidence: findings/represented-layout-preparation-2.md
// Labels: v2
// CodeTaskletFieldLayout: GUESS(medium) STANDIN; represented physical declaration alias.
// Field names and interpretations are guesses unless explicitly labelled otherwise.
// Observed scalar slots are individually supported by accesses, never filler selected only for allocation size.
// Omitted methods, pointee semantics and original complete C++ source remain unassessed.
// A Mac accessor pass proves its own code; size assertions and other field evidence are separate claims.
// BSScript::Internal::CodeTasklet: EXE_RTTI
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT; include/RE/C/CodeTasklet.h and include/RE/I/IFuncCallQuery.h.
// Code origin: adapted public data declarations only, no external implementation body.
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
#include <cstddef>
#include "CommunityLeafStorageLayout.h"
namespace ResearchLayouts {
// stack, vm, errorLogger, resumeReason, topFrame, frameMemoryPage, jumpBitCount, localVarBitCount, memberVarBitCount, instructionDataBitCount, instructionDataStart: GUESS(medium) STANDIN; physical fields, meanings unverified.
class CodeTaskletFieldLayout : public CommunityRef14c8960 { public: ~CodeTaskletFieldLayout();
    void* stack;
    void* vm;
    void* errorLogger;
    std::uint32_t resumeReason;
    void* topFrame;
    std::uint32_t frameMemoryPage;
    std::int8_t jumpBitCount;
    std::int8_t localVarBitCount;
    std::int8_t memberVarBitCount;
    std::uint32_t instructionDataBitCount;
    const void* instructionDataStart;
};
static_assert(sizeof(CodeTaskletFieldLayout)==80,"represented size");
static_assert(offsetof(CodeTaskletFieldLayout,stack)==16,"observed field offset");
static_assert(offsetof(CodeTaskletFieldLayout,vm)==24,"observed field offset");
static_assert(offsetof(CodeTaskletFieldLayout,errorLogger)==32,"observed field offset");
static_assert(offsetof(CodeTaskletFieldLayout,resumeReason)==40,"observed field offset");
static_assert(offsetof(CodeTaskletFieldLayout,topFrame)==48,"observed field offset");
static_assert(offsetof(CodeTaskletFieldLayout,frameMemoryPage)==56,"observed field offset");
static_assert(offsetof(CodeTaskletFieldLayout,jumpBitCount)==60,"observed field offset");
static_assert(offsetof(CodeTaskletFieldLayout,localVarBitCount)==61,"observed field offset");
static_assert(offsetof(CodeTaskletFieldLayout,memberVarBitCount)==62,"observed field offset");
static_assert(offsetof(CodeTaskletFieldLayout,instructionDataBitCount)==64,"observed field offset");
static_assert(offsetof(CodeTaskletFieldLayout,instructionDataStart)==72,"observed field offset");
}
