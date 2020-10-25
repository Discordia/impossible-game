#include <game/RenderSystem.h>
#include <game/RenderComponent.h>

RenderSystem::RenderSystem(std::shared_ptr<RenderQueue> renderQueue)
    : renderQueue(std::move(renderQueue)) {}

void RenderSystem::init() {
}

void RenderSystem::update(float_t dt, std::shared_ptr<entt::registry> registry) {
    registry->view<RenderComponent>().each([this](auto &renderComponent) {
        renderQueue->push_back(renderComponent.renderChunk);
    });
}