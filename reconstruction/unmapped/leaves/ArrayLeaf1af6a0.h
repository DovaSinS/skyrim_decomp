// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1af6a0, ArrayLeaf1af6a0Storage, ArrayLeaf1af6a0Size, FreeArrayLeaf1af6a0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1af6a0Storage
{
    ~ArrayLeaf1af6a0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1af6a0Size
{
    ~ArrayLeaf1af6a0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1af6a0 : public ArrayLeaf1af6a0Storage, public ArrayLeaf1af6a0Size
{
    ~ArrayLeaf1af6a0();  // compared: 0x1af6a0
};

void FreeArrayLeaf1af6a0(ArrayLeaf1af6a0* array);
