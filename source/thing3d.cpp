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
}

void Thing3D::setPosition(int x2, int y2, int z2)
{
    x = x2;
    y = y2;
    z = z2;
}

REGISTER_THING(Thing3D, "Thing3D");