#include "Game.h"
#include <memory>

Game::Game()
{
    window.create(sf::VideoMode(800,800),"Test",sf::Style::Close);
}

Entity* Game::createEntity(Vector2 iPosition)
{
    auto entity = std::make_shared<Entity>(iPosition);
    entities.insert(entity);
    entity.get()->game = this;
    return entity.get();
}

void Game::deleteEntity(Entity* iEntity)
{
    int i = 0;
    for(auto entity : entities)
    {
        if(entity.get() == iEntity)
        {
            entities.erase(entity);
            return;
        }
        i++;
    }
}

void Game::start()
{
    for(auto entity : entities)
    {
        entity.get()->start();
    }
}

void Game::update()
{
    //CLOCK CODE
    float deltaTime = clock.getElapsedTime().asSeconds();
    clock.restart();
    //WINDOW EVENT CODE
    handleWindowEvents();
    //RENDER
    window.clear(sf::Color::Black);
    for(auto renderer : renderers)
    {
        window.draw((*renderer).shape);
    }
    window.display();
    //UPDATE
    for(auto entity : entities)
    {
        entity.get()->update(deltaTime);
    }
}

void Game::handleWindowEvents()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}
