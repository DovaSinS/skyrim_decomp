// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x25fec0 ArrayLeaf25fec0::~ArrayLeaf25fec0
// Adapted bodies: none
// CI hash: 0x25fec0 ??1ArrayLeaf25fec0@@QEAA@XZ
#include "ArrayLeaf25fec0.h"

ArrayLeaf25fec0::~ArrayLeaf25fec0()
{
    if (data) {
        FreeArrayLeaf25fec0(this);
        size = 0;
    }
}
