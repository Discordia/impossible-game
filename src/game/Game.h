#pragma once

#include <vector>
#include "GameConfig.h"
#include <core/desktop/BGFXWindow.h>
#include <core/desktop/InputHandler.h>
#include <core/Camera.h>
#include <core/Renderer.h>

class RenderChunk;

using std::unique_ptr;
using std::shared_ptr;
using std::string;
using std::vector;


class Game {
public:
    Game(const GameConfig& config);
    int run();

private:
    BGFXWindow window;
    InputHandler inputHandler;
    Camera camera;
    unique_ptr<Renderer> renderer;
    vector<shared_ptr<RenderChunk>> renderQueue;
};