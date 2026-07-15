#pragma once

#include "thing.h"

class DebugCamera : public Thing {
public:
    void init() override;
    void update(float dt) override;
    void draw() override;
    void load(Loadable args) override;
    float spd = 0.1;
};