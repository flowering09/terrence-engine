#include <grrlib.h>
#include "mesh.h"
#include "transform.h"
#include "meshanimation.h"
#include "thing3d.h"
#include "thing2d.h"
#include "material.h"
class Engine
{
    public:
        void Init(Thing3D *root3, Thing2D *root2, Thing2D *rootui);
        void print(const char *);
        void DrawMesh(
            Mesh &mesh,
            Transform transform,
            Material material = Material());
        void DrawMesh(
            Mesh &mesh,
            float x,
            float y,
            float z,
            Material material = Material());
        void DrawAnimFrame(
            MeshAnimation &mesh,
            Transform transform,
            int frame,
            Material material = Material());
        void DrawAnimFrame(
            MeshAnimation &mesh,
            int frame,
            float x,
            float y,
            float z,
            Material material = Material());
        void Begin3D();
        void End3D();
        bool in3D = false;
        Thing3D *root3d;
        Thing2D *root2d;
        Thing2D *rootUI;

    private:
        GRRLIB_texImg *tex_font;
};

extern Engine engine;