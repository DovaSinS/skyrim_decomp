// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1aec20, ArrayLeaf1aec20Storage, ArrayLeaf1aec20Size, FreeArrayLeaf1aec20, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1aec20Storage
{
    ~ArrayLeaf1aec20Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1aec20Size
{
    ~ArrayLeaf1aec20Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1aec20 : public ArrayLeaf1aec20Storage, public ArrayLeaf1aec20Size
{
    ~ArrayLeaf1aec20();  // compared: 0x1aec20
};

void FreeArrayLeaf1aec20(ArrayLeaf1aec20* array);
