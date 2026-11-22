// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf39bf10, ArrayLeaf39bf10Storage, ArrayLeaf39bf10Size, FreeArrayLeaf39bf10, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf39bf10Storage
{
    ~ArrayLeaf39bf10Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf39bf10Size
{
    ~ArrayLeaf39bf10Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf39bf10 : public ArrayLeaf39bf10Storage, public ArrayLeaf39bf10Size
{
    ~ArrayLeaf39bf10();  // compared: 0x39bf10
};

void FreeArrayLeaf39bf10(ArrayLeaf39bf10* array);
