// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1afb20, ArrayLeaf1afb20Storage, ArrayLeaf1afb20Size, FreeArrayLeaf1afb20, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1afb20Storage
{
    ~ArrayLeaf1afb20Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1afb20Size
{
    ~ArrayLeaf1afb20Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1afb20 : public ArrayLeaf1afb20Storage, public ArrayLeaf1afb20Size
{
    ~ArrayLeaf1afb20();  // compared: 0x1afb20
};

void FreeArrayLeaf1afb20(ArrayLeaf1afb20* array);
