#include "Component.h"
#include "Entity.h"

Component::Component(Entity* iEntity)
{
    entity = iEntity;
}

//All of these should be empty and overridden by the individual components as needed.

void Component::receiveMessage(std::string iMessage)
{
}

void Component::start()
{
}

void Component::update(float deltaTime)
{
}
