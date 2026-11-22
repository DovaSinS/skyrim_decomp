// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf2f7d50, ArrayLeaf2f7d50Storage, ArrayLeaf2f7d50Size, FreeArrayLeaf2f7d50, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf2f7d50Storage
{
    ~ArrayLeaf2f7d50Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf2f7d50Size
{
    ~ArrayLeaf2f7d50Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf2f7d50 : public ArrayLeaf2f7d50Storage, public ArrayLeaf2f7d50Size
{
    ~ArrayLeaf2f7d50();  // compared: 0x2f7d50
};

void FreeArrayLeaf2f7d50(ArrayLeaf2f7d50* array);
