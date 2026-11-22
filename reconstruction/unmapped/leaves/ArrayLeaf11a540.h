// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf11a540, ArrayLeaf11a540Storage, ArrayLeaf11a540Size, FreeArrayLeaf11a540, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf11a540Storage
{
    ~ArrayLeaf11a540Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf11a540Size
{
    ~ArrayLeaf11a540Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf11a540 : public ArrayLeaf11a540Storage, public ArrayLeaf11a540Size
{
    ~ArrayLeaf11a540();  // compared: 0x11a540
};

void FreeArrayLeaf11a540(ArrayLeaf11a540* array);
