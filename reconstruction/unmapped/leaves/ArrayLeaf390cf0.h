// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf390cf0, ArrayLeaf390cf0Storage, ArrayLeaf390cf0Size, FreeArrayLeaf390cf0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf390cf0Storage
{
    ~ArrayLeaf390cf0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf390cf0Size
{
    ~ArrayLeaf390cf0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf390cf0 : public ArrayLeaf390cf0Storage, public ArrayLeaf390cf0Size
{
    ~ArrayLeaf390cf0();  // compared: 0x390cf0
};

void FreeArrayLeaf390cf0(ArrayLeaf390cf0* array);
