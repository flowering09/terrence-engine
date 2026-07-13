#pragma once
#include "thing.h"

class Thing2D : public Thing {
    public:
        void init() override;
        void update(float dt) override;
        void draw() override;
        void load(Loadable args) override;
        float x = 0;
        float y = 0;
};