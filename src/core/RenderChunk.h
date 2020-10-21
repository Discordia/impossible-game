#pragma once

#include <core/GeometryChunk.h>

class RenderChunk {
public:
    explicit RenderChunk(std::shared_ptr<GeometryChunk> geometryChunk)
        : geometryChunk(std::move(geometryChunk)) {}

    ~RenderChunk() = default;

    static std::shared_ptr<RenderChunk> forGeometry(std::shared_ptr<GeometryChunk> geometry) {
        return std::make_shared<RenderChunk>(geometry);
    }

    std::shared_ptr<GeometryChunk> getGeometry() {
        return geometryChunk;
    }

private:
    std::shared_ptr<GeometryChunk> geometryChunk;
};