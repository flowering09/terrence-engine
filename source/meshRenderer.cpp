#include "thing_factory.h"
#include "meshRenderer.h"
#include "engine.h"
#include "controls.h"
#include "terrencewiianim.h"

void MeshRenderer::init()
{
    Thing3D::init();
}

void MeshRenderer::update(float dt)
{
    Thing3D::update(dt);
}

void MeshRenderer::draw()
{
    if (visible)
    {
        Transform t;
        t.position.x = xFinal;
        t.position.y = yFinal;
        t.position.z = zFinal;

        t.rotation.x = xRot + xRParent;
        t.rotation.y = yRot + yRParent;
        t.rotation.z = zRot + zRParent;

        t.scale.x = 1;
        t.scale.y = 1;
        t.scale.z = 1;
        engine.DrawMesh(mesh, t, mat);
        Thing3D::draw();
    }
}

void MeshRenderer::load(Loadable args)
{
    if (args.forWhat == "Thing3D") {
        Thing3D::load(args);
        return;
    }
    mesh = *args.mesh;
    mat = args.mat;
}

REGISTER_THING(MeshRenderer, "MeshRenderer");