// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf3de200, ArrayLeaf3de200Storage, ArrayLeaf3de200Size, FreeArrayLeaf3de200, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf3de200Storage
{
    ~ArrayLeaf3de200Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf3de200Size
{
    ~ArrayLeaf3de200Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf3de200 : public ArrayLeaf3de200Storage, public ArrayLeaf3de200Size
{
    ~ArrayLeaf3de200();  // compared: 0x3de200
};

void FreeArrayLeaf3de200(ArrayLeaf3de200* array);
