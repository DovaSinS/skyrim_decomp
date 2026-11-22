// Source exposure: binary-analysis (the shape of the compared function in the pinned image).
// Code origin: original stand-in stamped from matched exemplar 0x1581e30 (reconstruction/bsshader/BSShadowDirectionalLight.cpp); no external declaration or body reused.
// 0x1af940 ArrayLeaf1af940::~ArrayLeaf1af940
// Adapted bodies: none
// CI hash: 0x1af940 ??1ArrayLeaf1af940@@QEAA@XZ
#include "ArrayLeaf1af940.h"

ArrayLeaf1af940::~ArrayLeaf1af940()
{
    if (data) {
        FreeArrayLeaf1af940(this);
        size = 0;
    }
}
