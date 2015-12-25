#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Component.h"

class Entity {

public:
    //Constructors
    Entity(sf::Vector2f iPosition);
    Entity(float iX, float iY);

    //Variables
    sf::Vector2f position;
    std::vector<Component*> components;

    //Methods
    void sendMessage(std::string iMessage);
    void addComponent(Component* iComponent);

    //Templates
    template <class T> T* getComponent()
    {
        std::cout << "Still working" << std::endl;
        T* result = nullptr; //so it will return a null if the component isn't found
        for(Component* component : components)
        {
            if(typeid(component) == typeid(T))
            {
                result = (T*)component;
            }
        }
        return result;
    }
};


#endif // ENTITY_H_INCLUDED
