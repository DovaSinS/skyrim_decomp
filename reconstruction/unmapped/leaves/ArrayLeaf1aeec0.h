// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1aeec0, ArrayLeaf1aeec0Storage, ArrayLeaf1aeec0Size, FreeArrayLeaf1aeec0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1aeec0Storage
{
    ~ArrayLeaf1aeec0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1aeec0Size
{
    ~ArrayLeaf1aeec0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1aeec0 : public ArrayLeaf1aeec0Storage, public ArrayLeaf1aeec0Size
{
    ~ArrayLeaf1aeec0();  // compared: 0x1aeec0
};

void FreeArrayLeaf1aeec0(ArrayLeaf1aeec0* array);
