// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1af340 ArrayLeaf1af340::~ArrayLeaf1af340
// Adapted bodies: none
// CI hash: 0x1af340 ??1ArrayLeaf1af340@@QEAA@XZ
#include "ArrayLeaf1af340.h"

ArrayLeaf1af340::~ArrayLeaf1af340()
{
    if (data) {
        FreeArrayLeaf1af340(this);
        size = 0;
    }
}
