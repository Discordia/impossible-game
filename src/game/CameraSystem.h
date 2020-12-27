#pragma once

#include <memory>
#include <game/Camera.h>
#include <game/EntitySystem.h>

class CameraSystem : public EntitySystem {
public:
    CameraSystem(int32_t width, int32_t height);

    void init() override;
    void update(float dt, std::shared_ptr<EntityRegistry> entityRegistry) override;

private:
    int32_t width;
    int32_t height;
    std::unique_ptr<Camera> camera;
};