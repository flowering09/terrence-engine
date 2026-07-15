#include "thing3d.h"
#include "thing_factory.h"
#include "engine.h"
#include "camera3d.h"

void Thing3D::init()
{
    Thing::init();
}

void Thing3D::update(float dt)
{
    Thing::update(dt);
    xFinal = x + xParent - cam3d.x;
    yFinal = y + yParent - cam3d.y;
    zFinal = z + zParent - cam3d.z;
    Loadable load;
    load.f1 = x;
    load.f2 = y;
    load.f3 = z;
    load.f4 = xRot;
    load.f5 = yRot;
    load.f6 = zRot;
    load.f7 = xScale;
    load.f8 = yScale;
    load.f9 = zScale;

    load.forWhat = "Thing3D";
    for (Thing* child : children)
    {
        child->load(load);
    }
}

void Thing3D::draw()
{
    engine.Begin3D();
    Thing::draw();
}

void Thing3D::load(Loadable args)
{
    xParent = args.f1;
    yParent = args.f2;
    zParent = args.f3;
    xRParent = args.f4;
    yRParent = args.f5;
    zRParent = args.f6;
    xSParent = args.f7;
    ySParent = args.f8;
    zSParent = args.f9;
}

void Thing3D::setPosition(float x2, float y2, float z2)
{
    x = x2;
    y = y2;
    z = z2;
}

void Thing3D::setRotation(float x2, float y2, float z2)
{
    xRot = x2;
    yRot = y2;
    zRot = z2;
}

void Thing3D::setScale(float x2, float y2, float z2)
{
    xScale = x2;
    yScale = y2;
    zScale = z2;
}

REGISTER_THING(Thing3D, "Thing3D");