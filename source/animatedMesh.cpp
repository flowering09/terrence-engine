#include "thing_factory.h"
#include "animatedMesh.h"
#include "engine.h"
#include "controls.h"
#include "terrencewiianim.h"

void AnimatedMesh::init() {
    Thing3D::init();
}

void AnimatedMesh::update(float dt) {
    frame += 1;
    if (frame >= mesh.frame_count) {
        frame = 0;
    }
    Thing3D::update(dt);
}

void AnimatedMesh::draw() {
    engine.DrawAnimFrame(mesh, frame, xFinal, yFinal, zFinal);
    Thing3D::draw();
}

void AnimatedMesh::load(Loadable args) {
    Thing3D::load(args);
    mesh = *args.animatedMesh;
}

REGISTER_THING(AnimatedMesh, "AnimatedMesh");