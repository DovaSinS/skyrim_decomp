// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1af820, ArrayLeaf1af820Storage, ArrayLeaf1af820Size, FreeArrayLeaf1af820, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1af820Storage
{
    ~ArrayLeaf1af820Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1af820Size
{
    ~ArrayLeaf1af820Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1af820 : public ArrayLeaf1af820Storage, public ArrayLeaf1af820Size
{
    ~ArrayLeaf1af820();  // compared: 0x1af820
};

void FreeArrayLeaf1af820(ArrayLeaf1af820* array);
