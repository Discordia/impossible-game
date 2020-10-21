#pragma once

#include <memory>
#include <core/Camera.h>

class CameraSystem {
public:
    CameraSystem(int32_t width, int32_t height);

    void init();
    void update();

private:
    int32_t width;
    int32_t height;
    std::unique_ptr<Camera> camera;
};