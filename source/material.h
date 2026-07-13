#pragma once
#include <grrlib.h>

struct Material {
    GRRLIB_texImg* texture = nullptr;
    bool textured = false;

    GXTexObj texObj;
    bool texObjInitialized = false;
};