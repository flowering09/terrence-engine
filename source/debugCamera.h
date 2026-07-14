#pragma once

#include "thing.h"

class DebugCamera : public Thing {
public:
    void init() override;
    void update(float dt) override;
    void draw() override;
    float spd = 0.1;
};