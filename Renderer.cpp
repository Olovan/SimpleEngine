#include "Renderer.h"
#include "Entity.h"
#include "Game.h"
#include <memory>

Renderer::Renderer(Entity* iEntity, Vector2 iDimensions) : Component(iEntity)
{
    std::cout << "I live!" << std::endl;
    dimensions = iDimensions;
    entity = iEntity;
    shape.setSize(sf::Vector2f(dimensions.x,dimensions.y));
}

Renderer::Renderer(Entity *iEntity, Vector2 iDimensions, sf::Color iColor ) : Component(iEntity)
{
    std::cout << "I live!" << std::endl;
    dimensions = iDimensions;
    entity = iEntity;
    shape.setFillColor(iColor);
    shape.setSize(sf::Vector2f(dimensions.x,dimensions.y));
}

Renderer::~Renderer()
{
    std::cout << "Should only see this once" << this << std::endl;
    entity->game->renderers.erase(this);
}

void Renderer::start()
{
    entity->game->renderers.insert(this);
}

void Renderer::update(float deltaTime)
{
    shape.setPosition(entity->position.x, entity->position.y);
}

