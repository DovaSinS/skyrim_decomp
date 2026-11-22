// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1af700, ArrayLeaf1af700Storage, ArrayLeaf1af700Size, FreeArrayLeaf1af700, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1af700Storage
{
    ~ArrayLeaf1af700Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1af700Size
{
    ~ArrayLeaf1af700Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1af700 : public ArrayLeaf1af700Storage, public ArrayLeaf1af700Size
{
    ~ArrayLeaf1af700();  // compared: 0x1af700
};

void FreeArrayLeaf1af700(ArrayLeaf1af700* array);
