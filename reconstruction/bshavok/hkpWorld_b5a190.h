// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; layouts as the listing reads them
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// hkpWorld, getClosestPoints: GUESS(low); the name is the timer text the function logs
// broadPhase, kdTreeManager, collisionInput, collisionFilter, ownerOffset: CRASHLOGGER_PDB(59818@2026.10.24)
// hkpShape::type, hkMemoryAllocator: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// hkpCollidable, hkpBroadPhase, hkpCollisionFilter, hkBool, hkAabb, hkInplaceArray, hkTempArray, hkMonitorStream, hkTimerCommand, hkContainerHeapAllocator, hkContainerTempAllocator, TreeWorldManager, CollisionInput, CollisionDispatcher: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>
#include <new>

extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long a_index);

struct hkMonitorStream
{
    std::uint8_t unknown00[0x8];  // 00
    char* current;  // 08
    std::uint8_t unknown10[0x8];  // 10
    char* end;  // 18
};

extern std::uint32_t g_hkMonitorStreamTlsIndex;

// a timer command in the monitor stream: a name that starts with the command code, then a time stamp
struct hkTimerCommand
{
    const char* name;  // 00
    std::uint32_t time;  // 08
};

// the command that opens a timer list also names the first timer of the list
struct hkTimerBeginListCommand : hkTimerCommand
{
    const char* firstName;  // 10
};

// open a timer list and start its first timer
inline void hkTimerBeginList(const char* a_list, const char* a_first)
{
    hkMonitorStream& stream = *static_cast<hkMonitorStream*>(TlsGetValue(g_hkMonitorStreamTlsIndex));
    if (stream.current < stream.end) {
        hkTimerBeginListCommand* command = reinterpret_cast<hkTimerBeginListCommand*>(stream.current);
        command->name = a_list;
        command->firstName = a_first;
        // the time stamp is the low half of the cpu counter
        command->time = static_cast<std::uint32_t>(__rdtsc());
        stream.current = reinterpret_cast<char*>(command + 1);
    }
}

// end the running timer of a list and start the next one
inline void hkTimerSplitList(const char* a_name)
{
    hkMonitorStream& stream = *static_cast<hkMonitorStream*>(TlsGetValue(g_hkMonitorStreamTlsIndex));
    if (stream.current < stream.end) {
        hkTimerCommand* command = reinterpret_cast<hkTimerCommand*>(stream.current);
        command->name = a_name;
        // the time stamp is the low half of the cpu counter
        command->time = static_cast<std::uint32_t>(__rdtsc());
        stream.current = reinterpret_cast<char*>(command + 1);
    }
}

// close a timer list
inline void hkTimerEndList()
{
    hkMonitorStream& stream = *static_cast<hkMonitorStream*>(TlsGetValue(g_hkMonitorStreamTlsIndex));
    if (stream.current < stream.end) {
        hkTimerCommand* command = reinterpret_cast<hkTimerCommand*>(stream.current);
        command->name = "lt";
        // the time stamp is the low half of the cpu counter
        command->time = static_cast<std::uint32_t>(__rdtsc());
        stream.current = reinterpret_cast<char*>(command + 1);
    }
}

// a Havok memory allocator: containers free their buffers through it
class hkMemoryAllocator
{
public:
    virtual ~hkMemoryAllocator();  // 00
    virtual void* blockAlloc(int a_numBytes) noexcept;  // 01
    virtual void blockFree(void* a_ptr, int a_numBytes) noexcept;  // 02
    virtual void* bufAlloc(int& a_reqNumBytes) noexcept;  // 03
    virtual void bufFree(void* a_ptr, int a_numBytes) noexcept;  // 04
};

// the allocators containers use: each is one global allocator object, handed out as a plain memory allocator
struct hkContainerTempAllocator
{
    struct Allocator : hkMemoryAllocator
    {
    };

    static Allocator s_alloc;
    static hkMemoryAllocator& get() { return s_alloc; }
};

struct hkContainerHeapAllocator
{
    struct Allocator : hkMemoryAllocator
    {
    };

    static Allocator s_alloc;
    static hkMemoryAllocator& get() { return s_alloc; }
};

struct hkAabb
{
    __m128 min;  // 00
    __m128 max;  // 10
};

// an array that starts in its own storage and frees a grown buffer through the heap allocator
template <class T, int N>
struct hkInplaceArray
{
    hkInplaceArray() : data(reinterpret_cast<T*>(storage)), size(0), capacityAndFlags(N | static_cast<int>(0x80000000)) {}
    ~hkInplaceArray()
    {
        size = 0;
        if (capacityAndFlags >= 0) {
            hkContainerHeapAllocator::get().bufFree(data, (capacityAndFlags & 0x3FFFFFFF) * static_cast<int>(sizeof(T)));
        }
    }

    T* data;  // 00
    std::int32_t size;  // 08
    std::int32_t capacityAndFlags;  // 0C
    alignas(16) std::uint8_t storage[N * sizeof(T)];  // 10
};

// an array whose buffer comes from the temp allocator
template <class T>
struct hkTempArray
{
    hkTempArray() : data(nullptr), size(0), capacityAndFlags(static_cast<int>(0x80000000)) {}
    ~hkTempArray()
    {
        size = 0;
        if (capacityAndFlags >= 0) {
            hkContainerTempAllocator::get().bufFree(data, (capacityAndFlags & 0x3FFFFFFF) * static_cast<int>(sizeof(T)));
        }
    }

    T* data;  // 00
    std::int32_t size;  // 08
    std::int32_t capacityAndFlags;  // 0C
};

struct hkpShape
{
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void getAabb(const void* a_transform, float a_tolerance, hkAabb* a_out) const noexcept;  // 07

    std::uint8_t unknown08[0x10];  // 08
    std::int32_t type;  // 18
};

struct hkpCollidable
{
    const hkpShape* shape;  // 00
    std::uint8_t unknown08[0x8];  // 08
    const void* motion;  // 10
};

struct BroadPhaseHandle
{
    std::uint8_t unknown00[0x5];  // 00
    std::int8_t ownerOffset;  // 05
};

struct BroadPhaseHandlePair
{
    BroadPhaseHandle* a;  // 00
    BroadPhaseHandle* b;  // 08
};

class hkpBroadPhase
{
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot0A();
    virtual void slot0B();
    virtual void slot0C();
    virtual void slot0D();
    virtual void slot0E();
    virtual void slot0F();
    virtual void slot10();
    virtual void slot11();
    virtual void querySingleAabb(const hkAabb& a_aabb, hkInplaceArray<BroadPhaseHandlePair, 128>* a_hits) const noexcept;  // 12
};

class TreeWorldManager
{
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual bool hasTrees() const noexcept;  // 04

    std::uint8_t unknown08[0x10];  // 08
    void* aabbTree;  // 18
    void* kdTree;  // 20
};

// Havok's bool: one byte, built from a C++ bool
struct hkBool
{
    hkBool() {}
    hkBool(bool a_value) : value(a_value) {}
    operator bool() const { return value != 0; }

    char value;  // 00
};

class hkpCollisionFilter
{
public:
    virtual void slot00();
    virtual hkBool isCollisionEnabled(const hkpCollidable& a_a, const hkpCollidable& a_b) const noexcept;  // 01
};

struct FilterHolder
{
    std::uint8_t unknown00[0x10];  // 00
    hkpCollisionFilter filter;  // 10
};

struct ClosestPointsFunction
{
    void (*getClosestPoints)(const hkpCollidable* a_a, const hkpCollidable* a_b, const struct CollisionInput* a_input, void* a_collector);  // 00
    std::uint8_t unknown08[0x20];  // 08
};
static_assert(sizeof(ClosestPointsFunction) == 0x28, "ClosestPointsFunction size");

struct CollisionDispatcher
{
    std::uint8_t unknown000[0x2B0];  // 000
    std::uint8_t agent2Types[0x20][0x20];  // 2B0
    std::uint8_t unknown6B0[0x410];  // 6B0
    ClosestPointsFunction agentFunctions[1];  // AC0
};

struct CollisionInput
{
    CollisionDispatcher* dispatcher;  // 00
    std::uint8_t unknown08[0x8];  // 08
    float tolerance;  // 10
};

struct WorldCollisionInput
{
    std::uint8_t unknown00[0x10];  // 00
    float tolerance;  // 10
};

using TreeQueryFunction = void (*)(void* a_tree, const hkAabb* a_aabb, void* a_hits);
extern TreeQueryFunction g_aabbTreeQueryAabb;
extern TreeQueryFunction g_kdTreeQueryAabb;

class hkpWorld
{
public:
    void getClosestPoints(const hkpCollidable* a_collidable, const CollisionInput* a_input, void* a_collector) noexcept;  // compared: 0xb5a190

    std::uint8_t unknown00[0x88];  // 00
    hkpBroadPhase* broadPhase;  // 88
    TreeWorldManager* kdTreeManager;  // 90
    std::uint8_t unknown98[0x30];  // 98
    WorldCollisionInput* collisionInput;  // C8
    FilterHolder* collisionFilter;  // D0
};
