// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1aef80, ArrayLeaf1aef80Storage, ArrayLeaf1aef80Size, FreeArrayLeaf1aef80, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1aef80Storage
{
    ~ArrayLeaf1aef80Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1aef80Size
{
    ~ArrayLeaf1aef80Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1aef80 : public ArrayLeaf1aef80Storage, public ArrayLeaf1aef80Size
{
    ~ArrayLeaf1aef80();  // compared: 0x1aef80
};

void FreeArrayLeaf1aef80(ArrayLeaf1aef80* array);
