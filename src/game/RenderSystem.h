#pragma once

#include <core/RenderQueue.h>

class RenderSystem {
public:
    explicit RenderSystem(std::shared_ptr<RenderQueue> renderQueue);

    void init();
    void update();

private:
    std::shared_ptr<RenderQueue> renderQueue;
    std::shared_ptr<RenderChunk> renderChunk1;
    std::shared_ptr<RenderChunk> renderChunk2;
};