#ifndef CUSTOMCLASSES_H
#define CUSTOMCLASSES_H

#include "Entity.h"

class Physics;

class BouncingSquare : public Component
{
    public:
        BouncingSquare(Entity* iEntity);
        void update(float deltaTime);
        void start();

        Physics* phys;
        Vector2 speed;
        Vector2 size;
    protected:
    private:
};

#endif // CUSTOMCLASSES_H
