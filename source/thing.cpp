#include "thing_factory.h"
#include "thing.h"

Thing::~Thing() {
    for (Thing* child : children) {
        delete child;
    }
}


void Thing::addChild(Thing* child) {
    children.push_back(child);
}


void Thing::removeChild(Thing* child) {
    for (auto it = children.begin(); it != children.end(); ++it) {
        if (*it == child) {
            children.erase(it);
            return;
        }
    }
}

void Thing::init() {
    for (Thing* child : children) {
        child->init();
    }
}

void Thing::update(float dt) {
    for (Thing* child : children) {
        child->update(dt);
    }
}


void Thing::draw() {
    if (visible) {
        for (Thing* child : children) {
            child->draw();
        }
    }
}

void Thing::setVisible(bool vis) {
    visible = vis;
}

void Thing::load(Loadable)
{
}

REGISTER_THING(Thing, "Thing");