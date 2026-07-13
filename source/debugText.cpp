#include "debugText.h"
#include "thing_factory.h"
#include "engine.h"

void DebugText::init() {
    Thing::init();
}

void DebugText::update(float dt) {
    Thing::update(dt);
}

void DebugText::draw() {
    engine.End3D();
    Thing::draw();
    engine.print(text);
}

void DebugText::load(Loadable args) {
    text = args.text;
}


REGISTER_THING(DebugText, "DebugText");