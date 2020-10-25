#pragma once

#include <memory>
#include <entt/entity/registry.hpp>
#include <game/EntityRegistry.h>

class EntitySystem {
public:
    EntitySystem() = default;
    virtual ~EntitySystem() = default;

    virtual void init() = 0;
    virtual void update(float_t dt, std::shared_ptr<EntityRegistry> entityRegistry) = 0;
};