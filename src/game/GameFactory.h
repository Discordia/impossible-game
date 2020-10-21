#pragma once

#include <memory>

class EntitySystem;

class GameFactory {
public:
    GameFactory() = default;;
    virtual ~GameFactory() = default;

    virtual void create(std::shared_ptr<EntitySystem> entitySystem) = 0;
};