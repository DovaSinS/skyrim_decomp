// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1af400 ArrayLeaf1af400::~ArrayLeaf1af400
// Adapted bodies: none
// CI hash: 0x1af400 ??1ArrayLeaf1af400@@QEAA@XZ
#include "ArrayLeaf1af400.h"

ArrayLeaf1af400::~ArrayLeaf1af400()
{
    if (data) {
        FreeArrayLeaf1af400(this);
        size = 0;
    }
}
