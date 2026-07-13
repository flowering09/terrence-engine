#include "thing_factory.h"
#include "meshRenderer.h"
#include "engine.h"
#include "controls.h"
#include "terrencewiianim.h"

void MeshRenderer::init() {
    Thing3D::init();
}

void MeshRenderer::update(float dt) {
    Thing3D::update(dt);
}

void MeshRenderer::draw() {
    engine.DrawMesh(mesh, xFinal, yFinal, zFinal, mat);
    Thing3D::draw();
}

void MeshRenderer::load(Loadable args) {
    Thing3D::load(args);
    mesh = *args.mesh;
    mat = args.mat;
}

REGISTER_THING(MeshRenderer, "MeshRenderer");