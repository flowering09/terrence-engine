#ifndef PLAYER_H
#define PLAYER_H

#include "thing.h"

class Test : public Thing {
public:
    void init() override;
    void update(float dt) override;
    void draw() override;
    float x = 0;
    float y = 0;
    float z = -2000;
    float spd = 0.1;
    int frame = 0;
};

#endif