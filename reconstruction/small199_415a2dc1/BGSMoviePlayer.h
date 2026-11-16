// BGSMoviePlayer, build sse-steam-1-7-104.
// Labels: v2
// Inferred names: GUESS(low)
// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; bodies original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// Drafted by gpt-6.1-terra.
// Evidence: findings/ghidra-import.md
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Names, signatures and layout remain inferred; only checked bytes are claimed.
// Compared functions:
// RVA 0x644870, 40 bytes: BGSMoviePlayer::Func3.
// RVA 0x6448a0, 40 bytes: BGSMoviePlayer::Func4.
// MIT License
// Copyright (c) 2018 Ryan-rsm-McKenzie
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// BGSMoviePlayer, MoviePlayer, BSTEventSink, BSTEventSource, BSTArray, BSTArrayBase, BSTArrayHeapAllocator, BSMusicEvent, BSIMusicType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Unk_03, Unk_04, musicType, msgType, kPause, kUnpause, sinks, pendingRegisters, pendingUnregisters, lock, notifying: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// pad51, pad52, pad54, unk08, unk10, unk18, unk20, unk28, unk30, unk38, unk40, unk48, unk50: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstdint>
class InputEvent; class BSIMusicType;
struct BSMusicEvent { enum class MUSIC_MESSAGE_TYPE { kAdd, kRemove, kRemoveImmediate, kPause, kUnpause }; BSIMusicType* musicType; MUSIC_MESSAGE_TYPE msgType; std::uint32_t pad0C; };
class BSTArrayHeapAllocator { public: void* _data; std::uint32_t _capacity; };
class BSTArrayBase { public: std::uint32_t _size; };
template <class T> class BSTArray : public BSTArrayHeapAllocator, public BSTArrayBase {};
struct BSSpinLock { std::uint32_t owningThread, lockCount; };
template <class T> class BSTEventSink { public: virtual ~BSTEventSink(); };
template <class T> class BSTEventSource { public: void SendEvent(const T*); BSTArray<BSTEventSink<T>*> sinks, pendingRegisters, pendingUnregisters; BSSpinLock lock; bool notifying; std::uint8_t pad51; std::uint16_t pad52; std::uint32_t pad54; };
class MoviePlayer { public: virtual ~MoviePlayer(); std::uint64_t unk08, unk10, unk18, unk20, unk28, unk30, unk38, unk40, unk48, unk50; };
class BGSMoviePlayer : public MoviePlayer, public BSTEventSink<InputEvent*>, public BSTEventSource<BSMusicEvent> { public: void Unk_03(); void Unk_04(); };
