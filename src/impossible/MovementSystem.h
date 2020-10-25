#pragma once

#include <game/EntitySystem.h>

class MovementSystem : public EntitySystem {
public:
    MovementSystem() = default;
    ~MovementSystem() override = default;

    void init() override;
    void update(float_t dt, std::shared_ptr<EntityRegistry> entityRegistry) override;

private:

};