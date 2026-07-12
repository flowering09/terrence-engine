#include "thing_factory.h"

std::map<std::string, std::function<Thing*()>> ThingFactory::registry;


Thing* ThingFactory::create(const std::string& name) {
    auto it = registry.find(name);

    if (it != registry.end()) {
        return it->second();
    }

    return nullptr;
}