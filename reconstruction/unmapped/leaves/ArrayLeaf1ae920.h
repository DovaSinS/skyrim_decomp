// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1ae920, ArrayLeaf1ae920Storage, ArrayLeaf1ae920Size, FreeArrayLeaf1ae920, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1ae920Storage
{
    ~ArrayLeaf1ae920Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1ae920Size
{
    ~ArrayLeaf1ae920Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1ae920 : public ArrayLeaf1ae920Storage, public ArrayLeaf1ae920Size
{
    ~ArrayLeaf1ae920();  // compared: 0x1ae920
};

void FreeArrayLeaf1ae920(ArrayLeaf1ae920* array);
