#pragma once
#include "thing.h"

class Thing3D : public Thing {
    public:
        void init() override;
        void update(float dt) override;
        void draw() override;
        void load(Loadable args) override;
        float x = 0;
        float y = 0;
        float z = 0;

        float xFinal = 0;
        float yFinal = 0;
        float zFinal = -2000;
};