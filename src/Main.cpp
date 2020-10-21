#include <core/desktop/DesktopStreamFactory.h>
#include <game/Game.h>
#include <impossible/TheImpossibleGame.h>

using std::make_shared;
using std::make_unique;

int main () {
    GameConfig gameConfig = GameConfig()
            .withTitle("The Impossible Game")
            .withResolution(1440, 900)
            .withStreamFactory(make_shared<DesktopStreamFactory>("out/osx"));

    Game game(gameConfig, make_unique<TheImpossibleGame>());
    return game.run();
}