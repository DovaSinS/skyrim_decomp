// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf25fec0, ArrayLeaf25fec0Storage, ArrayLeaf25fec0Size, FreeArrayLeaf25fec0, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf25fec0Storage
{
    ~ArrayLeaf25fec0Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf25fec0Size
{
    ~ArrayLeaf25fec0Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf25fec0 : public ArrayLeaf25fec0Storage, public ArrayLeaf25fec0Size
{
    ~ArrayLeaf25fec0();  // compared: 0x25fec0
};

void FreeArrayLeaf25fec0(ArrayLeaf25fec0* array);
