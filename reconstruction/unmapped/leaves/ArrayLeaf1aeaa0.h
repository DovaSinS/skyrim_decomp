// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1aeaa0, ArrayLeaf1aeaa0Storage, ArrayLeaf1aeaa0Size, FreeArrayLeaf1aeaa0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1aeaa0Storage
{
    ~ArrayLeaf1aeaa0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1aeaa0Size
{
    ~ArrayLeaf1aeaa0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1aeaa0 : public ArrayLeaf1aeaa0Storage, public ArrayLeaf1aeaa0Size
{
    ~ArrayLeaf1aeaa0();  // compared: 0x1aeaa0
};

void FreeArrayLeaf1aeaa0(ArrayLeaf1aeaa0* array);
