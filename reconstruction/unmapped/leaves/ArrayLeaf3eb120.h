// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf3eb120, ArrayLeaf3eb120Storage, ArrayLeaf3eb120Size, FreeArrayLeaf3eb120, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf3eb120Storage
{
    ~ArrayLeaf3eb120Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf3eb120Size
{
    ~ArrayLeaf3eb120Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf3eb120 : public ArrayLeaf3eb120Storage, public ArrayLeaf3eb120Size
{
    ~ArrayLeaf3eb120();  // compared: 0x3eb120
};

void FreeArrayLeaf3eb120(ArrayLeaf3eb120* array);
