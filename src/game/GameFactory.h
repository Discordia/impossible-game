#pragma once

#include <memory>

class EntityRegistry;

class GameFactory {
public:
    GameFactory() = default;;
    virtual ~GameFactory() = default;

    virtual void create(std::shared_ptr<EntityRegistry> entitySystem) = 0;
};