#include "CustomClasses.h"

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
    speed = phys->velocity;
    size = entity->getComponent<Renderer>()->dimensions;
}

void BouncingSquare::update(float deltaTime)
{
    if(phys)
    {
        if(entity->position.x > 800 - size.x)
        {
            phys->velocity.x = -1 * speed.x;
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
