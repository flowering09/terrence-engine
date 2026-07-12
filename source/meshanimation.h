#pragma once
#include "vertex.h"
struct MeshAnimation
{
    Vertex** frames;
    int frame_count;

    unsigned short* indices;
    int index_count;

    float fps;
};