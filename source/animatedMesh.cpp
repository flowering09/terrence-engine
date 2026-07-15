#include "thing_factory.h"
#include "animatedMesh.h"
#include "engine.h"
#include "controls.h"
#include "terrencewiianim.h"

void AnimatedMesh::init()
{
    Thing3D::init();
}

void AnimatedMesh::update(float dt)
{
    frame += 1;
    if (frame >= mesh.frame_count)
    {
        frame = 0;
    }
    Thing3D::update(dt);
}

void AnimatedMesh::draw()
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

        t.scale.x = xScale * xSParent;
        t.scale.y = yScale * ySParent;
        t.scale.z = zScale * zSParent;

        engine.DrawAnimFrame(mesh, t, frame, mat);
        Thing3D::draw();
    }
}

void AnimatedMesh::load(Loadable args)
{
    if (args.forWhat == "Thing3D") {
        Thing3D::load(args);
        return;
    }
    mesh = *args.animatedMesh;
    mat = args.mat;
}

REGISTER_THING(AnimatedMesh, "AnimatedMesh");