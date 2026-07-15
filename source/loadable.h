#pragma once

#include "meshanimation.h"
#include "mesh.h"
#include "material.h"

struct Loadable {
    MeshAnimation* animatedMesh = nullptr;
    Mesh* mesh = nullptr;
    Material mat = Material();

    float f1 = 0;
    float f2 = 0;
    float f3 = 0;

    const char* text;
    const char* forWhat;
};