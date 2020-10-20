#include "Game.h"
#include <core/Camera.h>

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

using std::make_unique;
using std::make_shared;

Game::Game(const GameConfig& config)
    : window(config.getTitle(), config.getWidth(), config.getHeight()),
      camera(config.getWidth(), config.getHeight()) {
    this->renderer = make_unique<Renderer>(config.getStreamFactory(), renderQueue);
}

int Game::run() {
    window.init();
    renderer->init();

    // Camera setup
    const bx::Vec3 eye = {0.0f, 0.0f, 10.0f};
    const bx::Vec3 at = {0.0f, 0.0f, 0.0f};
    camera.setLookAt(eye, at);
    camera.setProjection(60.0f, 0.1f, 100.0f);
    camera.update();


    // Poll for events and wait till user closes window
    bool running = true;

    auto chunk1 = GeometryChunk::create(
            cubeVertices, sizeof(cubeVertices), 4,
            cubeIndices, sizeof(cubeIndices), 6);
    auto renderChunk1 = RenderChunk::forGeometry(chunk1);

    auto chunk2 = GeometryChunk::create(
            cubeVertices2, sizeof(cubeVertices2), 4,
            cubeIndices2, sizeof(cubeIndices2), 6);
    auto renderChunk2 = RenderChunk::forGeometry(chunk2);

    while (running) {
        inputHandler.poll();
        running = !inputHandler.exitRequested();

        renderer->beginFrame();
        renderQueue.push_back(renderChunk1);
        renderQueue.push_back(renderChunk2);

        renderer->drawFrame();
        renderer->endFrame();
    }

    return 0;
}
