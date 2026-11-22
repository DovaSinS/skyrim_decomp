// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1af880, ArrayLeaf1af880Storage, ArrayLeaf1af880Size, FreeArrayLeaf1af880, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1af880Storage
{
    ~ArrayLeaf1af880Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1af880Size
{
    ~ArrayLeaf1af880Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1af880 : public ArrayLeaf1af880Storage, public ArrayLeaf1af880Size
{
    ~ArrayLeaf1af880();  // compared: 0x1af880
};

void FreeArrayLeaf1af880(ArrayLeaf1af880* array);
