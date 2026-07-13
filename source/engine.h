#include <grrlib.h>
#include "mesh.h"
#include "transform.h"
#include "meshanimation.h"
#include "thing3d.h"
#include "thing2d.h"
class Engine {
    public:
        void Init(Thing3D* root3, Thing2D* root2);
        void print(const char*);
        void DrawMesh(
            Mesh& mesh,
            Transform transform);
        void DrawMesh(
            Mesh& mesh,
            float x,
            float y,
            float z
        );
        void DrawAnimFrame(
            MeshAnimation& mesh,
            Transform transform,
            int frame);
        void DrawAnimFrame(
            MeshAnimation& mesh,
            int frame,
            float x,
            float y,
            float z
        );
        void Begin3D();
        void End3D();
        bool in3D;
        Thing3D* root3d;
        Thing2D* root2d;
    private:
        GRRLIB_texImg *tex_font;

};

extern Engine engine;