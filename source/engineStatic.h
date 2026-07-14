#pragma once

#include "engine.h"
#include <string>

class StaticEngine {
public:
    static void print(std::string text);
    static void Begin3D();
    static void End3D();
};