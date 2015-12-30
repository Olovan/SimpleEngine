#include "Renderer.h"
#include "Entity.h"
#include "Game.h"
#include <memory>

Renderer::Renderer(Entity* iEntity, Vector2 iDimensions) : Component(iEntity)
{
    dimensions = iDimensions;
    entity = iEntity;
    shape.setSize(sf::Vector2f(dimensions.x,dimensions.y));
}

Renderer::Renderer(Entity *iEntity, Vector2 iDimensions, sf::Color iColor ) : Component(iEntity)
{
    dimensions = iDimensions;
    entity = iEntity;
    shape.setFillColor(iColor);
    shape.setSize(sf::Vector2f(dimensions.x,dimensions.y));
}

void Renderer::start()
{
    entity->game->renderers.push_back(std::shared_ptr<Renderer>(this));
}

void Renderer::update(float deltaTime)
{
    shape.setPosition(entity->position.x, entity->position.y);
}

