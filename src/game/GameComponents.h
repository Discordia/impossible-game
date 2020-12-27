#pragma once

#include <core/RenderChunk.h>

struct PositionComponent {
    float x;
    float y;
};

struct VelocityComponent {
    float dx;
    float dy;
};

struct RenderComponent {
    std::shared_ptr<RenderChunk> renderChunk;

    explicit RenderComponent(std::shared_ptr<RenderChunk> renderChunk)
            : renderChunk(std::move(renderChunk)) {}
};