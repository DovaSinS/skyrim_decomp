// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf325320, ArrayLeaf325320Storage, ArrayLeaf325320Size, FreeArrayLeaf325320, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf325320Storage
{
    ~ArrayLeaf325320Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf325320Size
{
    ~ArrayLeaf325320Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf325320 : public ArrayLeaf325320Storage, public ArrayLeaf325320Size
{
    ~ArrayLeaf325320();  // compared: 0x325320
};

void FreeArrayLeaf325320(ArrayLeaf325320* array);
