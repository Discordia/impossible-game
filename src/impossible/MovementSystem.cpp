#include <impossible/MovementSystem.h>
#include <impossible/BaseComponents.h>

void MovementSystem::init() {

}

void MovementSystem::update(float_t dt, std::shared_ptr<entt::registry> registry) {
    registry->view<PositionComponent, VelocityComponent>().each([dt](auto &position, auto &velocity) {
        position.x = dt * velocity.dx;
        position.y = dt * velocity.dy;
    });
}
