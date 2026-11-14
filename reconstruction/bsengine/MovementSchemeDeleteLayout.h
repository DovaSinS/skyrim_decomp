// Build: sse-steam-1-7-104
// Source exposure: mixed (community declarations and local binary analysis).
// Drafted by GPT-6.1 Sol; p104b shared layout recovery.
// Labels: v2
// Code origin: interface and reference-count declarations adapted from the pinned public headers; derived scalar declarations originally inferred from target member accesses. No implementation bodies reused.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT), include/RE/B/BSTEvent.h and BSIntrusiveRefCounted.h.
// Structural aliases do not recover original template arguments, concrete definitions or omitted methods.
// Each capture scalar has a member access; no array or padding field forces allocation size.
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
// MovementSchemeRefCount: GUESS(medium) STANDIN; public reference-count alias.
// _refCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstdint>
#include <cstddef>
namespace ResearchLayouts {
struct MovementSchemeRefCount { mutable volatile std::uint32_t _refCount; };
// MovementSchemeDeleteLayout: GUESS(medium) STANDIN; represented public refcount inheritance.
class MovementSchemeDeleteLayout : public MovementSchemeRefCount { public: virtual ~MovementSchemeDeleteLayout(); };
static_assert(sizeof(MovementSchemeDeleteLayout)==16, "represented refcount layout");
static_assert(offsetof(MovementSchemeDeleteLayout, _refCount)==8, "reference-count subobject");
// MovementSchemeDeleteLayout1: GUESS(medium) STANDIN; represented public refcount inheritance.
class MovementSchemeDeleteLayout1 : public MovementSchemeRefCount { public: virtual ~MovementSchemeDeleteLayout1(); };
static_assert(sizeof(MovementSchemeDeleteLayout1)==16, "represented refcount layout");
static_assert(offsetof(MovementSchemeDeleteLayout1, _refCount)==8, "reference-count subobject");
// MovementSchemeDeleteLayout2: GUESS(medium) STANDIN; represented public refcount inheritance.
class MovementSchemeDeleteLayout2 : public MovementSchemeRefCount { public: virtual ~MovementSchemeDeleteLayout2(); };
static_assert(sizeof(MovementSchemeDeleteLayout2)==16, "represented refcount layout");
static_assert(offsetof(MovementSchemeDeleteLayout2, _refCount)==8, "reference-count subobject");
// MovementSchemeDeleteLayout3: GUESS(medium) STANDIN; represented public refcount inheritance.
class MovementSchemeDeleteLayout3 : public MovementSchemeRefCount { public: virtual ~MovementSchemeDeleteLayout3(); };
static_assert(sizeof(MovementSchemeDeleteLayout3)==16, "represented refcount layout");
static_assert(offsetof(MovementSchemeDeleteLayout3, _refCount)==8, "reference-count subobject");
}
