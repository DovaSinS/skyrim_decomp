// Build: sse-steam-1-7-104
// Labels: v2
// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Drafted by gpt-6.1-terra.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/B/BSIMusicType.h, BSIMusicTrack.h and BSTArray.h.
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
// names: GUESS(low); BGSMusicType represents its music interface subobject here.
#pragma once
class BSIMusicTrack { public: virtual ~BSIMusicTrack(); virtual void DoUpdate(); virtual void DoPlay(); virtual void DoPause(); virtual void DoFinish(bool,float); virtual float GetDurationImpl() const; virtual unsigned GetType() const; virtual bool TestCanPlay() const; virtual unsigned GetMusicStatus() const; virtual void DoSetDuckingAttenuation(unsigned short); virtual void DoClearDucking(); };
template<class T> struct ArrayAllocator { T* data; unsigned capacity; }; struct ArrayBase { unsigned size; }; template<class T> struct Array : ArrayAllocator<T>, ArrayBase {};
class BGSMusicType { public: virtual void DoUpdate(); virtual void DoPlay(); virtual void DoPause(); virtual void DoFinish(bool); virtual void DoApplyDuckingAttenuation(unsigned short); virtual void DoClearDucking(); virtual void DoPrepare(); virtual ~BGSMusicType(); unsigned flags; unsigned char priority, padding; unsigned short ducksOtherMusicBy; float fadeTime; unsigned currentTrackIndex; Array<unsigned> trackHistory; Array<BSIMusicTrack*> tracks; };
