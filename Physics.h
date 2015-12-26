#ifndef PHYSICS_H
#define PHYSICS_H

#include <Component.h>
#include "Vector2.h"

class Entity;

class Physics : public Component
{
    public:
        Physics(Entity* iOwner);
        bool gravityEnabled = false;
        Vector2 velocity{0,0};
        void update(float deltaTime);
        void start();
    protected:
    private:
};

#endif // PHYSICS_H
