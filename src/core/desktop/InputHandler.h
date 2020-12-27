#pragma once

#include <SDL.h>

class InputHandler {
public:
    InputHandler()
        : quit(false) {}

    void poll() {
        SDL_Event event;
        while(SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                quit = true;
            }
        }
    }

    [[nodiscard]] bool exitRequested() const {
        return quit;
    }

private:
    bool quit;
};