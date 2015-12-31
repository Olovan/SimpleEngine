#include "CustomClasses.h"

#include "Game.h"
#include "Physics.h"
#include "Component.h"
#include "Vector2.h"
#include "Renderer.h"

BouncingSquare::BouncingSquare(Entity* iEntity) : Component(iEntity)
{
    entity = iEntity;
}

void BouncingSquare::start()
{
    phys = entity->getComponent<Physics>();
    if(phys)
    {
        std::cout << "Physics found" << std::endl;
        speed = phys->velocity;
        if(speed.x < 0)
            speed.x = -1 * speed.x;
        if(speed.y < 0)
            speed.y = -1 * speed.y;
    }
    Renderer* renderer = entity->getComponent<Renderer>();
    if(renderer)
    {
        size = renderer->dimensions;
    }
}

void BouncingSquare::update(float deltaTime)
{
    if(phys)
    {
        if(entity->position.x > 800 - size.x)
        {
            phys->velocity.x = -speed.x;
        }
        else if(entity->position.x < 0)
        {
            phys->velocity.x = speed.x;
        }
        if(entity->position.y > 800 - size.y)
        {
            phys->velocity.y = -1 * speed.y;
        }
        else if(entity->position.y < 0)
        {
            phys->velocity.y = speed.y;
        }
    }
}

std::shared_ptr<Component> BouncingSquare::clone()
{
    return std::make_shared<BouncingSquare>(entity);
}




Duplicator::Duplicator(Entity* iEntity, Entity* iTarget) : Component(iEntity)
{
    entity = iEntity;
    target = iTarget;
}

float timePast = 0;

void Duplicator::update(float deltaTime)
{
    timePast += deltaTime;
    if(timePast > 0.001)
    {
        Entity* newEntity = entity->game->createEntity(target);
        newEntity->position = entity->position;
        std::cout << "Number of Renderers: " << entity->game->renderers.size() << std::endl;
        std::cout << "Number of Entities: " << entity->game->entities.size() << std::endl;
        timePast = 0;
    }
}
void Duplicator::start()
{

}
std::shared_ptr<Component> Duplicator::clone()
{
    return std::make_shared<Duplicator>(entity, target);
}
