// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// Declarations adapt CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT).
// Helper spellings and local variable names are inferred; individual labels accompany declarations.
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
// BSAudioManagerThread: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
#pragma once
#include <cstdint>
#include <cstddef>
struct ThreadCriticalSection { void* debugInfo; std::int32_t lockCount,recursionCount; void* owningThread; void* lockSemaphore; std::uintptr_t spinCount; };
class BSThread { public: virtual ~BSThread(); virtual std::uint32_t Unk_01(); virtual void Unk_02(); ThreadCriticalSection lock; void* thread; void* ownerThread; std::uint32_t threadID,ownerThreadID; bool initialized; };
class BSAudioManagerThread : public BSThread { public: BSAudioManagerThread(); ~BSAudioManagerThread() override; std::uint32_t Unk_01() override; void* wakeEvent; void* exitSemaphore; bool stopRequested,processing; std::uint16_t unknown62; std::uint32_t delay; };
static_assert(sizeof(BSAudioManagerThread)==0x68,"audio thread size");
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);
extern "C" __declspec(dllimport) std::uint32_t __stdcall WaitForSingleObject(void*,std::uint32_t);
extern "C" __declspec(dllimport) void __stdcall Sleep(std::uint32_t);
extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void*,std::int32_t,std::int32_t*);
extern std::uint32_t AudioHeapState; extern std::uint64_t AudioHeapManager; extern const char AudioHeapName[]; extern void* AudioManager;
void InitializeAudioHeap(void*,std::uint32_t*); void SetAudioHeapName(void*,const char*); void AudioWorkA(void*); void AudioWorkB(void*);

