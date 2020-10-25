#include <core/VertexTypes.h>
#include <game/EntityRegistry.h>
#include <game/GameComponents.h>
#include <impossible/TheImpossibleGame.h>
#include <impossible/MovementSystem.h>

using std::shared_ptr;
using std::make_unique;

static PosColorVertex cubeVertices[] = {
        {  0.5f,   0.5f, -20.0f, 0xff0000ff },
        {  0.5f,  -0.5f, -20.0f, 0xff0000ff },
        { -0.5f,  -0.5f, -20.0f, 0xff0000ff },
        { -0.5f,   0.5f, -20.0f, 0xff0000ff }};

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

void TheImpossibleGame::create(shared_ptr<EntityRegistry> entityRegistry) {
    // Create systems
    entityRegistry->registerSystem(make_unique<MovementSystem>());

    // Create entities
    const auto &registry = entityRegistry->getRegistry();

    auto entity1 = registry->create();
    auto chunk1 = GeometryChunk::create(
            cubeVertices, sizeof(cubeVertices), 4,
            cubeIndices, sizeof(cubeIndices), 6);
    auto renderChunk1 = RenderChunk::forGeometry(chunk1);
    registry->emplace<PositionComponent>(entity1, 0.0f, 0.0f);
    registry->emplace<VelocityComponent>(entity1, 2.0f, 2.0f);
    registry->emplace<RenderComponent>(entity1, renderChunk1);


    auto entity2 = registry->create();
    auto chunk2 = GeometryChunk::create(
            cubeVertices2, sizeof(cubeVertices2), 4,
            cubeIndices2, sizeof(cubeIndices2), 6);
    auto renderChunk2 = RenderChunk::forGeometry(chunk2);
    registry->emplace<PositionComponent>(entity2, -10.0f, -20.0f);
    registry->emplace<RenderComponent>(entity2, renderChunk2);
}
