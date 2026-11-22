// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1ae860, ArrayLeaf1ae860Storage, ArrayLeaf1ae860Size, FreeArrayLeaf1ae860, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1ae860Storage
{
    ~ArrayLeaf1ae860Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1ae860Size
{
    ~ArrayLeaf1ae860Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1ae860 : public ArrayLeaf1ae860Storage, public ArrayLeaf1ae860Size
{
    ~ArrayLeaf1ae860();  // compared: 0x1ae860
};

void FreeArrayLeaf1ae860(ArrayLeaf1ae860* array);
