// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1af100, ArrayLeaf1af100Storage, ArrayLeaf1af100Size, FreeArrayLeaf1af100, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1af100Storage
{
    ~ArrayLeaf1af100Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1af100Size
{
    ~ArrayLeaf1af100Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1af100 : public ArrayLeaf1af100Storage, public ArrayLeaf1af100Size
{
    ~ArrayLeaf1af100();  // compared: 0x1af100
};

void FreeArrayLeaf1af100(ArrayLeaf1af100* array);
