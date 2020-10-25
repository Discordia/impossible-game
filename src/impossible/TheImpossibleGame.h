#pragma once

#include <game/GameFactory.h>

class TheImpossibleGame : public GameFactory {
public:
    TheImpossibleGame() = default;
    ~TheImpossibleGame() override = default;

    void create(std::shared_ptr<EntityRegistry> entityRegistry) override;
};
