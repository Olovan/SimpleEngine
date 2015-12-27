#include "Physics.h"
#include "Entity.h"

Physics::Physics(Entity* iEntity) : Component(iEntity)
{
    entity = iEntity;
}

void Physics::start()
{

}

void Physics::update(float deltaTime)
{
    entity->position += velocity * deltaTime;
}
