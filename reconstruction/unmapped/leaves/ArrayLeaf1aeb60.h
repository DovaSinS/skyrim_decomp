// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1aeb60, ArrayLeaf1aeb60Storage, ArrayLeaf1aeb60Size, FreeArrayLeaf1aeb60, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1aeb60Storage
{
    ~ArrayLeaf1aeb60Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1aeb60Size
{
    ~ArrayLeaf1aeb60Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1aeb60 : public ArrayLeaf1aeb60Storage, public ArrayLeaf1aeb60Size
{
    ~ArrayLeaf1aeb60();  // compared: 0x1aeb60
};

void FreeArrayLeaf1aeb60(ArrayLeaf1aeb60* array);
