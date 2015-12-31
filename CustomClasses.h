#ifndef CUSTOMCLASSES_H
#define CUSTOMCLASSES_H

#include "Entity.h"
#include <memory>

class Physics;

class BouncingSquare : public Component
{
    public:
        BouncingSquare(Entity* iEntity);

        Physics* phys;
        Vector2 speed;
        Vector2 size;

        void update(float deltaTime);
        void start();
        std::shared_ptr<Component> clone();
    protected:
    private:
};

class Duplicator : public Component
{
    public:
        Duplicator(Entity* iEntity, Entity* iTarget);
        Entity* target;

        void update(float deltaTime);
        void start();
        std::shared_ptr<Component> clone();
};

//class CLASSNAME : public Component
//{
//    public:
//        CLASSNAME(Entity* iEntity);
//
//        void update(float deltaTime);
//        void start();
//        std::shared_ptr<Component> clone();
//};

#endif // CUSTOMCLASSES_H
