#include <game/CameraSystem.h>

using std::make_unique;
using std::shared_ptr;

CameraSystem::CameraSystem(int32_t width, int32_t height)
    : width(width), height(height) {
    this->camera = make_unique<Camera>(width, height);
}

void CameraSystem::init() {
    const bx::Vec3 eye = {0.0f, 0.0f, 10.0f};
    const bx::Vec3 at = {0.0f, 0.0f, 0.0f};
    camera->setLookAt(eye, at);
    camera->setProjection(60.0f, 0.1f, 100.0f);
    camera->update();
}

void CameraSystem::update(uint64_t dt, shared_ptr<entt::registry> registry) {

}
