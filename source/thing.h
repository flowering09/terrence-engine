#pragma once

#include <vector>

class Thing {
public:
    virtual ~Thing();

    virtual void init();
    virtual void update(float dt);
    virtual void draw();

    void addChild(Thing* child);
    void removeChild(Thing* child);

protected:
    std::vector<Thing*> children;
};