#pragma once

#include <bx/math.h>
#include <bgfx/bgfx.h>

class Camera {
public:
    Camera(int32_t width, int32_t height)
        : width(width), height(height) {
        bx::mtxIdentity(model);
    }

    void setProjection(float fovy, float near, float far) {
        bx::mtxProj(projection,
                    fovy,
                    float(width)/float(height),
                    near, far,
                    bgfx::getCaps()->homogeneousDepth);
    }

    void setLookAt(const bx::Vec3 &newEye, const bx::Vec3 &newAt, const bx::Vec3 &newUp) {
        this->eye = newEye;
        this->at = newAt;
        this->up = newUp;
    }

    void translate(float dt) {
        eye.x -= dt * 2;
        at.x -= dt * 2;
    }

    void update() {
        bx::mtxLookAt(view, eye, at, up);
        bgfx::setViewTransform(0, view, projection);
        bgfx::setTransform(model);
    }

private:
    int32_t width;
    int32_t height;
    bx::Vec3 eye;
    bx::Vec3 at;
    bx::Vec3 up;
    float view[16]{};
    float projection[16]{};
    float model[16]{};
};