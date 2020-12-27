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
    const bx::Vec3 up = {0.0f, 1.0f, 0.0f};
    camera->setLookAt(eye, at, up);
    camera->setProjection(60.0f, 0.1f, 100.0f);
    camera->update();
}

void CameraSystem::update(float dt, std::shared_ptr<EntityRegistry> entityRegistry) {
    camera->translate(dt);
    camera->update();
}
