// Build: sse-steam-1-7-104; RVA 0x63a640; 22 bytes
// Labels: v2
// Source exposure: mixed
// Origin: independently decoded target, anonymous sibling and public declarations.
// Drafted by gpt-6.1-terra
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Evidence: findings/ghidra-import.md
// LoadStorageWrapper::GetPosition: SIBLING(fo4-private@1b765c70, author-permission); adapted to target observations.
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/Buffers/BGSSaveLoadStorageWrappers.cpp:113
// LoadStorageWrapper, BSFile: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); declarations adapted from include/RE/L/LoadStorageWrapper.h, include/RE/B/BSMemStorage.h, include/RE/B/BSStorage.h, include/RE/B/BSFile.h, include/RE/N/NiFile.h and include/RE/N/NiBinaryStream.h.
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
class NiBinaryStream { public: virtual ~NiBinaryStream(); unsigned absolutePosition, pad; void* readFn; void* writeFn; };
class NiFile : public NiBinaryStream { public: unsigned bufferAllocSize, bufferReadSize, position, pad; char* buffer; void* file; unsigned mode; bool good; };
class BSFile : public NiFile { public: bool useAuxBuffer; unsigned char pad49; unsigned short pad4a; unsigned pad4c; char* auxBuffer; int auxTrueFilePos; unsigned auxBufferMinIndex, auxBufferMaxIndex; char fileName[260]; unsigned result, ioSize, trueFilePos, fileSize; };
class BSStorage { public: virtual ~BSStorage(); unsigned refCount; bool swapBytes, unknown0d; unsigned short unknown0e; void* unknown10; unsigned long long unknown18; };
class BSMemStorage : public BSStorage { public: BSFile* file; unsigned long long startingPosition; };
class LoadStorageWrapper : public BSMemStorage { public: unsigned long long GetPosition() const; };
