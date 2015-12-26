#include "Physics.h"
#include "Entity.h"

Physics::Physics(Entity* iOwner) : Component(iOwner)
{
    owner = iOwner;
}

void Physics::start()
{

}

void Physics::update(float deltaTime)
{
    owner->position += velocity * deltaTime;
}
