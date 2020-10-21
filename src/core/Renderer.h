#pragma once

#include <memory>
#include <vector>
#include <bgfx/bgfx.h>
#include <core/RenderQueue.h>
#include <core/ShaderProgram.h>
#include <core/VertexBuffer.h>
#include <core/IndexBuffer.h>

class StreamFactory;

class Renderer {
public:
    Renderer(std::shared_ptr<StreamFactory> streamFactory, std::shared_ptr<RenderQueue> renderQueue);
    ~Renderer() = default;

    void init();
    void beginFrame();
    void drawFrame();
    void endFrame();

private:
    std::shared_ptr<StreamFactory> streamFactory;
    std::shared_ptr<RenderQueue> renderQueue;
    std::unique_ptr<ShaderProgram> shaderProgram;
    std::unique_ptr<VertexBuffer> vertexBuffer;
    std::unique_ptr<IndexBuffer> indexBuffer;
};
