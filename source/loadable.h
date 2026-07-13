#include "meshanimation.h"
#include "mesh.h"
#include "material.h"

struct Loadable {
    float x;
    float y;
    float z;

    MeshAnimation* animatedMesh = nullptr;
    Mesh* mesh = nullptr;
    Material mat = Material();

    const char* text;
};