// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf3de260, ArrayLeaf3de260Storage, ArrayLeaf3de260Size, FreeArrayLeaf3de260, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf3de260Storage
{
    ~ArrayLeaf3de260Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf3de260Size
{
    ~ArrayLeaf3de260Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf3de260 : public ArrayLeaf3de260Storage, public ArrayLeaf3de260Size
{
    ~ArrayLeaf3de260();  // compared: 0x3de260
};

void FreeArrayLeaf3de260(ArrayLeaf3de260* array);
