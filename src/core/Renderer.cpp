#include <core/Renderer.h>
#include <core/StreamFactory.h>
#include <core/Camera.h>

Renderer::Renderer(std::shared_ptr<StreamFactory> streamFactory, std::shared_ptr<RenderQueue> renderQueue)
        : streamFactory(std::move(streamFactory)), renderQueue(std::move(renderQueue)) {}

void Renderer::init() {
    // Shader program used to render setup
    this->shaderProgram = ShaderProgram::load(streamFactory, "v_simple.bin", "f_simple.bin");

    // VertexBuffer and IndexBuffer setup
    this->vertexBuffer = std::make_unique<VertexBuffer>(20, VertexType::POS3_COLOR4);
    this->indexBuffer = std::make_unique<IndexBuffer>(20);
}

void Renderer::beginFrame() {
}

void Renderer::drawFrame() {
    uint32_t vertexOffset = 0;
    uint32_t indexOffset = 0;

    for (const auto &chunk : *renderQueue) {
        auto geometry = chunk->getGeometry();
        vertexBuffer->update(vertexOffset, geometry->getVerticesAsRef());
        indexBuffer->update(indexOffset, geometry->getIndicesAsRef());

        vertexBuffer->bind();
        indexBuffer->bind(indexOffset, geometry->getIndexCount());
        shaderProgram->submit();

        vertexOffset += geometry->getVertexCount();
        indexOffset += geometry->getIndexCount();
    }
}

void Renderer::endFrame() {
    renderQueue->clear();
    bgfx::frame();
}

