// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1afa60, ArrayLeaf1afa60Storage, ArrayLeaf1afa60Size, FreeArrayLeaf1afa60, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1afa60Storage
{
    ~ArrayLeaf1afa60Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1afa60Size
{
    ~ArrayLeaf1afa60Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1afa60 : public ArrayLeaf1afa60Storage, public ArrayLeaf1afa60Size
{
    ~ArrayLeaf1afa60();  // compared: 0x1afa60
};

void FreeArrayLeaf1afa60(ArrayLeaf1afa60* array);
