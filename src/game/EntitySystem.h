#pragma once

#include <memory>
#include <entt/entity/registry.hpp>

class EntitySystem {
public:
    EntitySystem() = default;
    virtual ~EntitySystem() = default;

    virtual void init() = 0;
    virtual void update(float_t dt, std::shared_ptr<entt::registry> registry) = 0;
};