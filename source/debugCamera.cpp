#include "thing_factory.h"
#include "debugCamera.h"
#include "engine.h"
#include "controls.h"
#include "camera3d.h"

void DebugCamera::init() {
    Thing::init();
}

void DebugCamera::update(float dt) {
    Thing::update(dt);
    if (controls.a) {
        cam3d.z -= spd * 500;
    }
    if (controls.b) {
        cam3d.z += spd * 500;
    }
    if (controls.left) {
        cam3d.x -= spd;
    }
    if (controls.right) {
        cam3d.x += spd;
    }
    if (controls.up) {
        cam3d.y += spd;
    }
    if (controls.down) {
        cam3d.y -= spd;
    }
}

void DebugCamera::draw() {
    Thing::draw();
}

REGISTER_THING(DebugCamera, "DebugCamera");