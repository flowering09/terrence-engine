#include "thing_factory.h"
#include "testThing.h"
#include "engine.h"
#include "controls.h"
#include "terrencewiianim.h"

void Test::init() {
    Thing::init();
}

void Test::update(float dt) {
    Thing::update(dt);
    if (controls.a) {
        z += spd * 500;
    }
    if (controls.b) {
        z -= spd * 500;
    }
    if (controls.left) {
        x += spd;
    }
    if (controls.right) {
        x -= spd;
    }
    if (controls.up) {
        y -= spd;
    }
    if (controls.down) {
        y += spd;
    }
    frame += 1;
    if (frame >= head_animation.frame_count) {
        frame = 0;
    }
}

void Test::draw() {
    Thing::draw();
    engine.Begin3D();
    engine.DrawAnimFrame(head_animation, frame, x, y, z);
    engine.End3D();
    engine.print("I AM IN PAIN");
}

REGISTER_THING(Test, "Test");