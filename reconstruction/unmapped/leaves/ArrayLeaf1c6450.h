// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1c6450, ArrayLeaf1c6450Storage, ArrayLeaf1c6450Size, FreeArrayLeaf1c6450, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1c6450Storage
{
    ~ArrayLeaf1c6450Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1c6450Size
{
    ~ArrayLeaf1c6450Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1c6450 : public ArrayLeaf1c6450Storage, public ArrayLeaf1c6450Size
{
    ~ArrayLeaf1c6450();  // compared: 0x1c6450
};

void FreeArrayLeaf1c6450(ArrayLeaf1c6450* array);
