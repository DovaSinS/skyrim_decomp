// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf111a20, ArrayLeaf111a20Storage, ArrayLeaf111a20Size, FreeArrayLeaf111a20, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf111a20Storage
{
    ~ArrayLeaf111a20Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf111a20Size
{
    ~ArrayLeaf111a20Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf111a20 : public ArrayLeaf111a20Storage, public ArrayLeaf111a20Size
{
    ~ArrayLeaf111a20();  // compared: 0x111a20
};

void FreeArrayLeaf111a20(ArrayLeaf111a20* array);
