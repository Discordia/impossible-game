#include <game/Game.h>

#include <memory>
#include <core/desktop/DesktopStreamFactory.h>

using std::make_shared;

int main () {
    GameConfig gameConfig;
    gameConfig.withTitle("The Impossible Game");
    gameConfig.withResolution(1440, 900);
    gameConfig.withStreamFactory(make_shared<DesktopStreamFactory>("out/osx"));

    Game game(gameConfig);
    return game.run();
}