#include "thing2d.h"
#include "thing_factory.h"
#include "engine.h"

void Thing2D::init() {
    Thing::init();
}

void Thing2D::update(float dt) {
    Thing::update(dt);
}

void Thing2D::draw() {
    engine.End3D();
    Thing::draw();
}

void Thing2D::load(Loadable args) {
    
}

void Thing2D::setPosition(int x2, int y2) {
    x = x2;
    y = y2;
}


REGISTER_THING(Thing2D, "Thing2D");