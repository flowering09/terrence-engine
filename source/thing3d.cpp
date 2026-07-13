#include "thing3d.h"
#include "thing_factory.h"
#include "engine.h"

void Thing3D::init() {
    Thing::init();
}

void Thing3D::update(float dt) {
    Thing::update(dt);
}

void Thing3D::draw() {
    engine.Begin3d();
    Thing::draw();
}

void Thing3D::load(Loadable args) {
    x = args.x;
    y = args.y;
    z = args.z;
}


REGISTER_THING(Thing3D, "Thing3D");