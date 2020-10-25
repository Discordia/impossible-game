#pragma once

#include <memory>
#include <vector>
#include <entt/entt.hpp>
#include <game/EntitySystem.h>

class EntityRegistry {
public:
    EntityRegistry();

    std::shared_ptr<entt::registry> getRegistry();
    void registerSystem(std::unique_ptr<EntitySystem> entitySystem);

    void init();
    void update(float_t dt);

private:
    std::shared_ptr<entt::registry> registry;
    std::vector<std::unique_ptr<EntitySystem>> systems;
};