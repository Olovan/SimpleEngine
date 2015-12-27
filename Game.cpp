#include "Game.h"

Game::Game()
{
    //ctor
}

Entity* Game::createEntity(Vector2 iPosition)
{
    auto entity = std::make_shared<Entity>(iPosition);
    entities.push_back(entity);
    entity.get()->game = this;
    return entity.get();
}
