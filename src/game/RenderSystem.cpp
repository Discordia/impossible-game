#include <game/RenderSystem.h>
#include <game/GameComponents.h>

RenderSystem::RenderSystem(std::shared_ptr<RenderQueue> renderQueue)
    : renderQueue(std::move(renderQueue)) {}

void RenderSystem::init() {
}

void RenderSystem::update(float dt, std::shared_ptr<EntityRegistry> entityRegistry) {
    auto registry = entityRegistry->getRegistry();
    registry->view<RenderComponent>().each([this](auto &renderComponent) {
        renderQueue->push_back(renderComponent.renderChunk);
    });
}