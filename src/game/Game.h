#pragma once

#include <vector>
#include <core/desktop/BGFXWindow.h>
#include <core/desktop/InputHandler.h>
#include <core/Renderer.h>
#include <game/GameConfig.h>
#include <game/GameFactory.h>
#include <game/EntitySystem.h>

class RenderChunk;

class Game {
public:
    Game(const GameConfig& config, std::unique_ptr<GameFactory> game);
    int run();

private:
    GameConfig config;

    std::unique_ptr<GameFactory> gameFactory;
    std::unique_ptr<BGFXWindow> window;
    std::unique_ptr<InputHandler> inputHandler;

    std::shared_ptr<RenderQueue> renderQueue;
    std::unique_ptr<Renderer> renderer;

    std::shared_ptr<EntitySystem> entitySystem;
};