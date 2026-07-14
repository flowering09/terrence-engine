#pragma once

#include <map>
#include <string>
#include <functional>
#include "thing.h"
#define REGISTER_THING(TYPE, NAME) \
static bool TYPE##_registered = [](){ \
    ThingFactory::registerType<TYPE>(NAME); \
    return true; \
}();

class ThingFactory {
public:
    static Thing* create(const std::string& name);

    template<typename T>
    static void registerType(const std::string& name) {
        registry[name] = []() -> Thing* {
            return new T();
        };
    }

private:
    static std::map<std::string, std::function<Thing*()>> registry;
};