#include <game/EntityRegistry.h>

using std::shared_ptr;
using std::make_shared;

EntityRegistry::EntityRegistry() {
    this->registry = make_shared<entt::registry>();
}

shared_ptr <entt::registry> EntityRegistry::getRegistry() {
    return registry;
}

void EntityRegistry::registerSystem(std::unique_ptr<EntitySystem> entitySystem) {
    systems.push_back(std::move(entitySystem));
}

void EntityRegistry::init() {
    for (const auto &system : systems) {
        system->init();
    }
}

void EntityRegistry::update(float_t dt) {
    for (const auto &system : systems) {
        system->update(dt, registry);
    }
}
