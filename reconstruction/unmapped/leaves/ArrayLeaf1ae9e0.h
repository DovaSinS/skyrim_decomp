// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1ae9e0, ArrayLeaf1ae9e0Storage, ArrayLeaf1ae9e0Size, FreeArrayLeaf1ae9e0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1ae9e0Storage
{
    ~ArrayLeaf1ae9e0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1ae9e0Size
{
    ~ArrayLeaf1ae9e0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1ae9e0 : public ArrayLeaf1ae9e0Storage, public ArrayLeaf1ae9e0Size
{
    ~ArrayLeaf1ae9e0();  // compared: 0x1ae9e0
};

void FreeArrayLeaf1ae9e0(ArrayLeaf1ae9e0* array);
