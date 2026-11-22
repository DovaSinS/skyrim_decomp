// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1af520 ArrayLeaf1af520::~ArrayLeaf1af520
// Adapted bodies: none
// CI hash: 0x1af520 ??1ArrayLeaf1af520@@QEAA@XZ
#include "ArrayLeaf1af520.h"

ArrayLeaf1af520::~ArrayLeaf1af520()
{
    if (data) {
        FreeArrayLeaf1af520(this);
        size = 0;
    }
}
