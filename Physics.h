#ifndef PHYSICS_H
#define PHYSICS_H

#include "Component.h"
#include "Vector2.h"

class Entity;

class Physics : public Component
{
    public:
        Physics(Entity* iEntity);
        Physics(Entity* iEntity, Vector2 iVelocity);
        bool gravityEnabled = false;
        Vector2 velocity{0,0};
        void update(float deltaTime);
        void start();
        std::shared_ptr<Component> clone();
    protected:
    private:
};

#endif // PHYSICS_H
