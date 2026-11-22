// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1aebc0, ArrayLeaf1aebc0Storage, ArrayLeaf1aebc0Size, FreeArrayLeaf1aebc0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1aebc0Storage
{
    ~ArrayLeaf1aebc0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1aebc0Size
{
    ~ArrayLeaf1aebc0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1aebc0 : public ArrayLeaf1aebc0Storage, public ArrayLeaf1aebc0Size
{
    ~ArrayLeaf1aebc0();  // compared: 0x1aebc0
};

void FreeArrayLeaf1aebc0(ArrayLeaf1aebc0* array);
