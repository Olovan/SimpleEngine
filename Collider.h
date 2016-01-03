#ifndef COLLIDER_H
#define COLLIDER_H

#include "Component.h"

class Collider : public Component
{
    public:
        Collider(Entity* iEntity);

        void start();
        virtual bool checkCollision(Collider other);

    protected:
    private:
};

#endif // COLLIDER_H
