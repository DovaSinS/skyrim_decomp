// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1af760 ArrayLeaf1af760::~ArrayLeaf1af760
// Adapted bodies: none
// CI hash: 0x1af760 ??1ArrayLeaf1af760@@QEAA@XZ
#include "ArrayLeaf1af760.h"

ArrayLeaf1af760::~ArrayLeaf1af760()
{
    if (data) {
        FreeArrayLeaf1af760(this);
        size = 0;
    }
}
