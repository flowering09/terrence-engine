#pragma once
#include "thing.h"

class Thing3D : public Thing {
    public:
        void init() override;
        void update(float dt) override;
        void draw() override;
        void load(Loadable args) override;
        void setPosition(float x2, float y2, float z2);
        void setRotation(float x2, float y2, float z2);
        void setScale(float x2, float y2, float z2);
        float x = 0;
        float y = 0;
        float z = 0;

        float xParent = 0;
        float yParent = 0;
        float zParent = 0;

        float xRot = 0;
        float yRot = 0;
        float zRot = 0;

        float xRParent = 0;
        float yRParent = 0;
        float zRParent = 0;

        float xScale = 1;
        float yScale = 1;
        float zScale = 1;

        float xSParent = 1;
        float ySParent = 1;
        float zSParent = 1;

        float xFinal = 0;
        float yFinal = 0;
        float zFinal = -2000;
};