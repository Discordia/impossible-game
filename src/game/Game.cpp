#include <game/Game.h>
#include <game/CameraSystem.h>
#include <game/RenderSystem.h>

using std::make_unique;
using std::make_shared;

Game::Game(const GameConfig& config, std::unique_ptr<GameFactory> gameFactory) {
    this->config = config;
    this->gameFactory = std::move(gameFactory);
    this->window = make_unique<BGFXWindow>(config.getTitle(), config.getWidth(), config.getHeight());
    this->inputHandler = make_unique<InputHandler>();
    this->renderQueue = make_shared<RenderQueue>();
    this->renderer = make_unique<Renderer>(config.getStreamFactory(), renderQueue);
}

int Game::run() {
    window->init();
    renderer->init();

    //
    // setup entity system
    //

    // camera system
    CameraSystem cameraSystem(config.getWidth(), config.getHeight());
    cameraSystem.init();

    // render system
    RenderSystem renderSystem(renderQueue);
    renderSystem.init();

    // create game with entity system
    gameFactory->create(entitySystem);

    // Poll for events and wait till user closes window
    bool running = true;

    while (running) {
        inputHandler->poll();
        running = !inputHandler->exitRequested();

        renderer->beginFrame();
        renderSystem.update();
        renderer->drawFrame();
        renderer->endFrame();
    }

    return 0;
}
