#include <impossible/MovementSystem.h>
#include <game/GameComponents.h>

void MovementSystem::init() {

}

void MovementSystem::update(float dt, std::shared_ptr<EntityRegistry> entityRegistry) {
    auto registry = entityRegistry->getRegistry();
    registry->view<PositionComponent, VelocityComponent>().each([dt](auto &position, auto &velocity) {
        position.x = dt * velocity.dx;
        position.y = dt * velocity.dy;
    });
}
