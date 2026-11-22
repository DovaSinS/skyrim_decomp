// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1af640 ArrayLeaf1af640::~ArrayLeaf1af640
// Adapted bodies: none
// CI hash: 0x1af640 ??1ArrayLeaf1af640@@QEAA@XZ
#include "ArrayLeaf1af640.h"

ArrayLeaf1af640::~ArrayLeaf1af640()
{
    if (data) {
        FreeArrayLeaf1af640(this);
        size = 0;
    }
}
