// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1eed80, ArrayLeaf1eed80Storage, ArrayLeaf1eed80Size, FreeArrayLeaf1eed80, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1eed80Storage
{
    ~ArrayLeaf1eed80Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1eed80Size
{
    ~ArrayLeaf1eed80Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1eed80 : public ArrayLeaf1eed80Storage, public ArrayLeaf1eed80Size
{
    ~ArrayLeaf1eed80();  // compared: 0x1eed80
};

void FreeArrayLeaf1eed80(ArrayLeaf1eed80* array);
