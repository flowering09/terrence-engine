#pragma once
#include "thing3d.h"
#include "meshanimation.h"

class MeshRenderer : public Thing3D {
public:
    void init() override;
    void update(float dt) override;
    void draw() override;
    void load(Loadable args) override;
    Mesh mesh;
    Material mat;
};