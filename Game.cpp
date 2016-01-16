#include "Game.h"
#include <memory>

Game::Game()
{
    window.create(sf::VideoMode(800,800),"Test",sf::Style::Close);
    world = std::unique_ptr<b2World>(new b2World(Vector2(0, -10).box2D()));
    heightToWidthRatio = window.getSize().x/window.getSize().y;
    sf::View view(sf::Vector2f(0,0),sf::Vector2f(20*heightToWidthRatio,20));
    window.setView(view);


}

//Entity* Game::createEntity(Vector2 iPosition)
//{
//    auto entity = std::make_shared<Entity>(iPosition);
//    entities.insert(entity);
//    entity.get()->game = this;
//    return entity.get();
//}

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
    if(deltaTime > 1/20.f) //If the game drops below 20FPS for any reason it will slow down instead of allowing such a large jump
        deltaTime = 1/20.f;
    elapsedTime += deltaTime;
    clock.restart();

    //WINDOW EVENT CODE
    handleWindowEvents();

    //UPDATE
    world.get()->Step(deltaTime, 8, 3);
    for(auto entity : entities)
    {
        entity.get()->update(deltaTime);
    }

    //RENDER
    window.clear(sf::Color::Black);
    for(auto renderer : renderers)
    {
        window.draw((*renderer).shape);
    }
    window.display();
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
