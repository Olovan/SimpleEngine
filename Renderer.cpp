#include "Renderer.h"
#include "Entity.h"
#include "Game.h"
#include <memory>

Renderer::Renderer(Entity* iEntity, Vector2 iDimensions) : Component(iEntity)
{
    dimensions = iDimensions;
    entity = iEntity;
    shape.setSize(dimensions.sfml());
}

Renderer::Renderer(Entity *iEntity, Vector2 iDimensions, sf::Color iColor ) : Component(iEntity)
{
    dimensions = iDimensions;
    entity = iEntity;
    shape.setFillColor(iColor);
    shape.setSize(dimensions.sfml());
}

Renderer::Renderer(Entity *entity, Vector2 iDimensions, std::string path) : Component(entity)
{
    dimensions = iDimensions;
    texture = entity->game->textureManager.getTexture(path);
    shape.setSize(dimensions.sfml());
    if(texture)
        shape.setTexture(texture,false);
    else
        std::cout << "Failed to load Texture" << std::endl;

}

Renderer::~Renderer() //Remove self from Game renderers set
{
    entity->game->renderers.erase(this);
}

void Renderer::start() //insert self into Game renderers set
{
    entity->game->renderers.insert(this);
}

void Renderer::update(float deltaTime)
{
    shape.setPosition(entity->position.x, entity->position.y);
}

std::shared_ptr<Component> Renderer::clone()
{
    return std::make_shared<Renderer>(*this);
}
