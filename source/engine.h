#include <grrlib.h>
#include "mesh.h"
#include "transform.h"
#include "meshanimation.h"
class Engine {
    public:
        void Init();
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
    private:
        GRRLIB_texImg *tex_font;

};

extern Engine engine;