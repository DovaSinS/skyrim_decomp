// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf3de320, ArrayLeaf3de320Storage, ArrayLeaf3de320Size, FreeArrayLeaf3de320, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf3de320Storage
{
    ~ArrayLeaf3de320Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf3de320Size
{
    ~ArrayLeaf3de320Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf3de320 : public ArrayLeaf3de320Storage, public ArrayLeaf3de320Size
{
    ~ArrayLeaf3de320();  // compared: 0x3de320
};

void FreeArrayLeaf3de320(ArrayLeaf3de320* array);
