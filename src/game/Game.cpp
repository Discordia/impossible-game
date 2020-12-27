#include <game/Game.h>
#include <game/CameraSystem.h>
#include <game/RenderSystem.h>
#include <game/FrameTimer.h>


using std::make_unique;
using std::make_shared;

Game::Game(const GameConfig& config, std::unique_ptr<GameFactory> gameFactory) {
    this->config = config;
    this->gameFactory = std::move(gameFactory);
    this->window = make_unique<BGFXWindow>(config.getTitle(), config.getWidth(), config.getHeight());
    this->inputHandler = make_unique<InputHandler>();
    this->renderQueue = make_shared<RenderQueue>();
    this->renderer = make_unique<Renderer>(config.getStreamFactory(), renderQueue);
    this->entityRegistry = make_shared<EntityRegistry>();
}

int Game::run() {
    window->init();
    renderer->init();

    // setup entity system
    entityRegistry->registerSystem(make_unique<CameraSystem>(config.getWidth(), config.getHeight()));
    entityRegistry->registerSystem(make_unique<RenderSystem>(renderQueue));
    gameFactory->create(entityRegistry);
    entityRegistry->init();

    // Timing
    FrameTimer timer;

    // Poll for events and wait till user closes window
    bool running = true;
    while (running) {
        float dt = timer.startFrame();

        inputHandler->poll();
        running = !inputHandler->exitRequested();

        renderer->beginFrame();
        entityRegistry->update(dt);
        renderer->drawFrame();
        renderer->endFrame();
        timer.endFrame();
    }

    return 0;
}
