// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1af460 ArrayLeaf1af460::~ArrayLeaf1af460
// Adapted bodies: none
// CI hash: 0x1af460 ??1ArrayLeaf1af460@@QEAA@XZ
#include "ArrayLeaf1af460.h"

ArrayLeaf1af460::~ArrayLeaf1af460()
{
    if (data) {
        FreeArrayLeaf1af460(this);
        size = 0;
    }
}
