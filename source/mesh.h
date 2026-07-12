#pragma once

#include "vertex.h"

struct Mesh
{
    Vertex* vertices;
    unsigned int vertexCount;

    unsigned short* indices;
    unsigned int index_count;
};