#pragma once

#include <memory>
#include <core/Camera.h>
#include <game/EntitySystem.h>

class CameraSystem : public EntitySystem {
public:
    CameraSystem(int32_t width, int32_t height);

    void init() override;
    void update(uint64_t dt, std::shared_ptr<entt::registry> registry) override;

private:
    int32_t width;
    int32_t height;
    std::unique_ptr<Camera> camera;
};