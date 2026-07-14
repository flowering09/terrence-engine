#pragma once

#include <vector>
#include "loadable.h"

class Thing {
public:
    virtual ~Thing();

    virtual void init();
    virtual void update(float dt);
    virtual void draw();

    virtual void load(Loadable args);

    void addChild(Thing* child);
    void removeChild(Thing* child);

    const char* name;
    
    std::vector<Thing*> children;
};