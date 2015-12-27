#ifndef COMPONENT_H_INCLUDED
#define COMPONENT_H_INCLUDED

#include <string>
class Entity;

class Component {
public:
    Entity* entity;
    Component(Entity* entity);
    virtual void receiveMessage(std::string iMessage);
    virtual void update(float deltaTime);
    virtual void start();
};

#endif // COMPONENT_H_INCLUDED
