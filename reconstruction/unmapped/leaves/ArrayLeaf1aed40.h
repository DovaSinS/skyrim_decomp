// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// ArrayLeaf1aed40, ArrayLeaf1aed40Storage, ArrayLeaf1aed40Size, FreeArrayLeaf1aed40, data, capacity, size: GUESS(low) STANDIN
#pragma once
#include <cstdint>

struct ArrayLeaf1aed40Storage
{
    ~ArrayLeaf1aed40Storage();
    void* data;
    std::uint32_t capacity;
    std::uint32_t pad0C;
};

struct ArrayLeaf1aed40Size
{
    ~ArrayLeaf1aed40Size();
    std::uint32_t size;
    std::uint32_t pad04;
};

struct ArrayLeaf1aed40 : public ArrayLeaf1aed40Storage, public ArrayLeaf1aed40Size
{
    ~ArrayLeaf1aed40();  // compared: 0x1aed40
};

void FreeArrayLeaf1aed40(ArrayLeaf1aed40* array);
