#include "Renderer.h"
#include "Entity.h"
#include "Game.h"
#include <memory>

Renderer::Renderer(Entity* iEntity, Vector2 iDimensions) : Component(iEntity)
{
    dimensions = iDimensions;
    entity = iEntity;
}

void Renderer::start()
{
    entity->game->renderers.push_back(std::shared_ptr<Renderer>(this));
}

void Renderer::update(float deltaTime)
{

}

