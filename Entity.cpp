#include "Entity.h"
#include "Component.h"

Entity::Entity(Vector2 iPosition)
{
    position = iPosition;
}

Entity::Entity(float iX, float iY)
{
    position.x = iX;
    position.y = iY;
}

void Entity::start()
{
    for(auto component : components)
    {
        component.get()->start();
    }
}

void Entity::update(float deltaTime)
{
    for(auto component : components)
    {
        component.get()->update(deltaTime);
    }
}

void Entity::sendMessage(std::string iMessage)
{
    for(std::shared_ptr<Component> component : components)
    {
        component.get()->receiveMessage(iMessage);
    }
}

void Entity::addComponent(std::shared_ptr<Component> iComponent)
{
    components.push_back(iComponent);
}
