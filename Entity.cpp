#include "Entity.h"
#include "Component.h"

Entity::Entity(sf::Vector2f iPosition)
{
    position = iPosition;
}

Entity::Entity(float iX, float iY)
{
    position.x = iX;
    position.y = iY;
}

void Entity::sendMessage(std::string iMessage)
{
    for(Component* component : components)
    {
        component->receiveMessage(iMessage);
    }
}

void Entity::addComponent(Component* iComponent)
{
    components.push_back(iComponent);
}
