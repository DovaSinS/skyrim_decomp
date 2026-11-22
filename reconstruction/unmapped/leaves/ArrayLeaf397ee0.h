// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf397ee0, ArrayLeaf397ee0Storage, ArrayLeaf397ee0Size, FreeArrayLeaf397ee0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf397ee0Storage
{
    ~ArrayLeaf397ee0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf397ee0Size
{
    ~ArrayLeaf397ee0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf397ee0 : public ArrayLeaf397ee0Storage, public ArrayLeaf397ee0Size
{
    ~ArrayLeaf397ee0();  // compared: 0x397ee0
};

void FreeArrayLeaf397ee0(ArrayLeaf397ee0* array);
