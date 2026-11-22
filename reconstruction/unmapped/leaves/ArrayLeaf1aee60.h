// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1aee60, ArrayLeaf1aee60Storage, ArrayLeaf1aee60Size, FreeArrayLeaf1aee60, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1aee60Storage
{
    ~ArrayLeaf1aee60Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1aee60Size
{
    ~ArrayLeaf1aee60Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1aee60 : public ArrayLeaf1aee60Storage, public ArrayLeaf1aee60Size
{
    ~ArrayLeaf1aee60();  // compared: 0x1aee60
};

void FreeArrayLeaf1aee60(ArrayLeaf1aee60* array);
