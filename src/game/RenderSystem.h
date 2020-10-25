#pragma once

#include <core/RenderQueue.h>
#include <game/EntitySystem.h>

class RenderSystem : public EntitySystem {
public:
    explicit RenderSystem(std::shared_ptr<RenderQueue> renderQueue);

    void init() override;
    void update(float_t dt, std::shared_ptr<EntityRegistry> entityRegistry) override;

private:
    std::shared_ptr<RenderQueue> renderQueue;
    std::shared_ptr<RenderChunk> renderChunk1;
    std::shared_ptr<RenderChunk> renderChunk2;
};