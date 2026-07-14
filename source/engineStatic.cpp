#include "engineStatic.h"

void StaticEngine::print(std::string text)
{
    engine.print(text.c_str());
}

void StaticEngine::Begin3D()
{
    engine.Begin3D();
}

void StaticEngine::End3D()
{
    engine.End3D();
}