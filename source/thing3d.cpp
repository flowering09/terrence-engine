#include "thing3d.h"
#include "thing_factory.h"
#include "engine.h"
#include "camera3d.h"

void Thing3D::init() {
    Thing::init();
}

void Thing3D::update(float dt) {
    Thing::update(dt);
    xFinal = x - cam3d.x;
    yFinal = y - cam3d.y;
    zFinal = z - cam3d.z;
}

void Thing3D::draw() {
    engine.Begin3D();
    Thing::draw();
}

void Thing3D::load(Loadable args) {
    x = args.x;
    y = args.y;
    z = args.z;
}

void Thing3D::setPosition(int x2, int y2, int z2) {
    x = x2;
    y = y2;
    z = z2;
}


REGISTER_THING(Thing3D, "Thing3D");