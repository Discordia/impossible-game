#include <game/RenderSystem.h>
#include <core/VertexTypes.h>

static PosColorVertex cubeVertices[] = {
        {  0.5f,  2.5f, 0.0f, 0xff0000ff },
        {  0.5f,  1.5f, 0.0f, 0xff0000ff },
        { -0.5f,  1.5f, 0.0f, 0xff0000ff },
        { -0.5f,  2.5f, 0.0f, 0xff0000ff }};

static PosColorVertex cubeVertices2[] = {
        {  1.5f,  -1.5f, 0.0f, 0xff00ff00 },
        {  1.5f, -2.5f, 0.0f, 0xff00ff00 },
        { -1.5f, -2.5f, 0.0f, 0xff00ff00 },
        { -1.5f,  -1.5f, 0.0f, 0xff00ff00 }};

static const uint32_t cubeIndices[] = {
        0,1,3,
        1,2,3};

static const uint32_t cubeIndices2[] = {
        4,5,7,
        5,6,7};

RenderSystem::RenderSystem(std::shared_ptr<RenderQueue> renderQueue)
    : renderQueue(std::move(renderQueue)) {}

void RenderSystem::init() {
    auto chunk1 = GeometryChunk::create(
            cubeVertices, sizeof(cubeVertices), 4,
            cubeIndices, sizeof(cubeIndices), 6);
    this->renderChunk1 = RenderChunk::forGeometry(chunk1);

    auto chunk2 = GeometryChunk::create(
            cubeVertices2, sizeof(cubeVertices2), 4,
            cubeIndices2, sizeof(cubeIndices2), 6);
    this->renderChunk2 = RenderChunk::forGeometry(chunk2);
}

void RenderSystem::update(uint64_t dt, std::shared_ptr<entt::registry> registry) {
    renderQueue->push_back(renderChunk1);
    renderQueue->push_back(renderChunk2);
}