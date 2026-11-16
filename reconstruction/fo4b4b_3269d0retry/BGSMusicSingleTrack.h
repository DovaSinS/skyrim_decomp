// Build: sse-steam-1-7-104; RVA 0x3269d0; 33 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// BGSMusicSingleTrack::GetDurationImpl: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Gameplay/BGSMusicSingleTrack.cpp:182
// BGSMusicSingleTrack: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/B/BGSMusicSingleTrack.h, include/RE/B/BGSMusicTrack.h, include/RE/B/BSIMusicTrack.h, include/RE/B/BSSoundHandle.h and include/RE/I/ID.h.
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
struct ResourceID { unsigned file, extension, directory; };
struct FloatArray { float* data; unsigned capacity; unsigned allocatorPad; unsigned size; unsigned sizePad; };
class SoundHandle { public: unsigned id; bool success; unsigned char pad; unsigned short pad2; unsigned state; int GetDuration() const; void FadeTo(unsigned short, unsigned short); };
class MusicTrackInterface { public: virtual ~MusicTrackInterface(); unsigned status; };
class BGSMusicTrack : public MusicTrackInterface { public: void* conditions; unsigned long long unknown; };
extern float musicUnduckingSeconds, musicDuckingSeconds;
unsigned short ClampFadeTimeSeconds(float);
class BGSMusicSingleTrack : public BGSMusicTrack { public: ResourceID trackID, finaleID; FloatArray cuePoints; unsigned nextCue, loopsRemaining, lastPosition, pad; void* loopData; SoundHandle trackHandle; float GetDurationImpl() const; void DoClearDucking(); void DoSetDuckingAttenuation(unsigned short); };
