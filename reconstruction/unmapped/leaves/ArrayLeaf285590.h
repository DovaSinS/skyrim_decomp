// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf285590, ArrayLeaf285590Storage, ArrayLeaf285590Size, FreeArrayLeaf285590, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf285590Storage
{
    ~ArrayLeaf285590Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf285590Size
{
    ~ArrayLeaf285590Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf285590 : public ArrayLeaf285590Storage, public ArrayLeaf285590Size
{
    ~ArrayLeaf285590();  // compared: 0x285590
};

void FreeArrayLeaf285590(ArrayLeaf285590* array);
