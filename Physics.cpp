#include "Physics.h"
#include "Entity.h"

Physics::Physics(Entity* iEntity) : Component(iEntity)
{
    entity = iEntity;
}

Physics::Physics(Entity* iEntity, Vector2 iVelocity) : Component(iEntity)
{
    entity = iEntity;
    velocity = iVelocity;
}

void Physics::start()
{

}

void Physics::update(float deltaTime)
{
    entity->position += velocity * deltaTime;
}
