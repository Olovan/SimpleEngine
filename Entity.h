#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "Component.h"

class Entity {

public:
    //Constructors
    Entity(sf::Vector2f iPosition);
    Entity(float iX, float iY);

    //Variables
    sf::Vector2f position;
    std::vector<std::shared_ptr<Component>> components;

    //Methods
    void sendMessage(std::string iMessage);
    void addComponent(std::shared_ptr<Component> iComponent);

    //Templates
    template <class T> T* getComponent()
    {
        for(std::shared_ptr<Component> component : components)
        {
            T* result = dynamic_cast<T*>(component.get());
            if(result != nullptr)
            {
                return result;
            }
        }
        return nullptr;
    }

    template <class T> T* createComponent()
    {
        std::shared_ptr<T> newComponent = std::make_shared<T>();
        components.push_back(newComponent);
        return newComponent.get();
    }
};


#endif // ENTITY_H_INCLUDED
