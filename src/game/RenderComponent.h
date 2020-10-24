#pragma once

#include <core/RenderChunk.h>

#include <utility>

struct RenderComponent {
    std::shared_ptr<RenderChunk> renderChunk;

    explicit RenderComponent(std::shared_ptr<RenderChunk> renderChunk)
        : renderChunk(std::move(renderChunk)) {}
};