// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf20aa40, ArrayLeaf20aa40Storage, ArrayLeaf20aa40Size, FreeArrayLeaf20aa40, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf20aa40Storage
{
    ~ArrayLeaf20aa40Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf20aa40Size
{
    ~ArrayLeaf20aa40Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf20aa40 : public ArrayLeaf20aa40Storage, public ArrayLeaf20aa40Size
{
    ~ArrayLeaf20aa40();  // compared: 0x20aa40
};

void FreeArrayLeaf20aa40(ArrayLeaf20aa40* array);
