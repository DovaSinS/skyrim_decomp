// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1af100 ArrayLeaf1af100::~ArrayLeaf1af100
// Adapted bodies: none
// CI hash: 0x1af100 ??1ArrayLeaf1af100@@QEAA@XZ
#include "ArrayLeaf1af100.h"

ArrayLeaf1af100::~ArrayLeaf1af100()
{
    if (data) {
        FreeArrayLeaf1af100(this);
        size = 0;
    }
}
