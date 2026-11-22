// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf11a400, ArrayLeaf11a400Storage, ArrayLeaf11a400Size, FreeArrayLeaf11a400, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf11a400Storage
{
    ~ArrayLeaf11a400Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf11a400Size
{
    ~ArrayLeaf11a400Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf11a400 : public ArrayLeaf11a400Storage, public ArrayLeaf11a400Size
{
    ~ArrayLeaf11a400();  // compared: 0x11a400
};

void FreeArrayLeaf11a400(ArrayLeaf11a400* array);
