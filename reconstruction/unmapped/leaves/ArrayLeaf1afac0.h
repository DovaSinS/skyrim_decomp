// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1afac0, ArrayLeaf1afac0Storage, ArrayLeaf1afac0Size, FreeArrayLeaf1afac0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1afac0Storage
{
    ~ArrayLeaf1afac0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1afac0Size
{
    ~ArrayLeaf1afac0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1afac0 : public ArrayLeaf1afac0Storage, public ArrayLeaf1afac0Size
{
    ~ArrayLeaf1afac0();  // compared: 0x1afac0
};

void FreeArrayLeaf1afac0(ArrayLeaf1afac0* array);
