#include "meshanimation.h"
#include "mesh.h"

struct Loadable {
    float x;
    float y;
    float z;

    MeshAnimation* animatedMesh = nullptr;
    Mesh* mesh = nullptr;
};