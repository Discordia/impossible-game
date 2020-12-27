#pragma once

#include <memory>
#include <vector>
#include <entt/entt.hpp>

class EntitySystem;

class EntityRegistry : public std::enable_shared_from_this<EntityRegistry> {
public:
    EntityRegistry();

    std::shared_ptr<entt::registry> getRegistry();
    void registerSystem(std::unique_ptr<EntitySystem> entitySystem);

    void init();
    void update(float dt);

private:
    std::shared_ptr<entt::registry> registry;
    std::vector<std::unique_ptr<EntitySystem>> systems;
};