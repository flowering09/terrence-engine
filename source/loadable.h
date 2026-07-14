#include "meshanimation.h"
#include "mesh.h"
#include "material.h"

struct Loadable {
    MeshAnimation* animatedMesh = nullptr;
    Mesh* mesh = nullptr;
    Material mat = Material();

    const char* text;
};