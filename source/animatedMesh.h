#pragma once
#include "thing3d.h"
#include "meshanimation.h"

class AnimatedMesh : public Thing3D {
public:
    void init() override;
    void update(float dt) override;
    void draw() override;
    void load(Loadable args) override;
    MeshAnimation mesh;
    int frame;
};