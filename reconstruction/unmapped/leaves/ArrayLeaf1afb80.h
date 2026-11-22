// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1afb80, ArrayLeaf1afb80Storage, ArrayLeaf1afb80Size, FreeArrayLeaf1afb80, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1afb80Storage
{
    ~ArrayLeaf1afb80Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1afb80Size
{
    ~ArrayLeaf1afb80Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1afb80 : public ArrayLeaf1afb80Storage, public ArrayLeaf1afb80Size
{
    ~ArrayLeaf1afb80();  // compared: 0x1afb80
};

void FreeArrayLeaf1afb80(ArrayLeaf1afb80* array);
