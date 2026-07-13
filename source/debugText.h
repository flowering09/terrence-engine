#pragma once
#include "thing2d.h"

class DebugText : public Thing {
    public:
        void init() override;
        void update(float dt) override;
        void draw() override;
        void load(Loadable args) override;
        const char* text = nullptr;
};