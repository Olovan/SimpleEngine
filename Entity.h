#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "Vector2.h"
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <iostream>
#include "Component.h"

class Game;

class Entity {

public:
    //Constructors
    Entity(Vector2 iPosition);
    Entity(float iX, float iY);
    Entity(Entity* iEntity);

    //Variables
    Vector2 position;
    float angle;
    std::vector<std::shared_ptr<Component>> components;
    Game* game;

    //Methods
    void start();
    void update(float deltaTime);
    void sendMessage(std::string iMessage);
    void addComponent(std::shared_ptr<Component> iComponent); //Use createComponent to make new components. Only use addComponent to transfer ownership of existing components. Should avoid using addComponent in most cases
    Entity* clone(Entity* iEntity);

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

    template<class T>T* createComponent()
    {
        std::shared_ptr<T> newComponent = std::make_shared<T>();
        components.push_back(newComponent);
        return newComponent.get();
    }

    template <class T, class... ARG> T* createComponent(ARG&&... args)
    {
        std::shared_ptr<T> newComponent = std::make_shared<T>(std::forward<ARG>(args)...);
        components.push_back(newComponent);
        return newComponent.get();
    }
};


#endif // ENTITY_H_INCLUDED
