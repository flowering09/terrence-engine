#pragma once
#include "thing.h"

class Thing2D : public Thing {
    public:
        void init() override;
        void update(float dt) override;
        void draw() override;
        void load(Loadable args) override;
        void setPosition(int x2, int y2);
        float x = 0;
        float y = 0;
};