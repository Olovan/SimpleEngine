#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include "Collider.h"
#include "Vector2.h"

class BoxCollider : public Collider
{
    public:
        BoxCollider(Entity* iEntity);

        Vector2 size;

        void start();
        bool checkCollision(Collider* other);

        float top();
        float bottom();
        float left();
        float right();
    protected:
    private:
};

#endif // BOXCOLLIDER_H
