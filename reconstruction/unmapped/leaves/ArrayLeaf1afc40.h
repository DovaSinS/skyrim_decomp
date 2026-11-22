// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1afc40, ArrayLeaf1afc40Storage, ArrayLeaf1afc40Size, FreeArrayLeaf1afc40, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1afc40Storage
{
    ~ArrayLeaf1afc40Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1afc40Size
{
    ~ArrayLeaf1afc40Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1afc40 : public ArrayLeaf1afc40Storage, public ArrayLeaf1afc40Size
{
    ~ArrayLeaf1afc40();  // compared: 0x1afc40
};

void FreeArrayLeaf1afc40(ArrayLeaf1afc40* array);
