// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1af2e0, ArrayLeaf1af2e0Storage, ArrayLeaf1af2e0Size, FreeArrayLeaf1af2e0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1af2e0Storage
{
    ~ArrayLeaf1af2e0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1af2e0Size
{
    ~ArrayLeaf1af2e0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1af2e0 : public ArrayLeaf1af2e0Storage, public ArrayLeaf1af2e0Size
{
    ~ArrayLeaf1af2e0();  // compared: 0x1af2e0
};

void FreeArrayLeaf1af2e0(ArrayLeaf1af2e0* array);
