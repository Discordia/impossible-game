#pragma once

#include <core/RenderChunk.h>

struct PositionComponent {
    float_t x;
    float_t y;
};

struct VelocityComponent {
    float_t dx;
    float_t dy;
};

struct RenderComponent {
    std::shared_ptr<RenderChunk> renderChunk;

    explicit RenderComponent(std::shared_ptr<RenderChunk> renderChunk)
            : renderChunk(std::move(renderChunk)) {}
};