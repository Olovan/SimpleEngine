#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include "Collider.h"
#include "Vector2.h"
#include <Box2D/Box2D.h>

class BoxCollider : public Collider
{
    public:
        BoxCollider(Entity *iEntity, Vector2 iDimensions, b2BodyType iBodyType);

        b2Body* body;
        Vector2 size;

        void start();
        void update(float deltaTime);
        bool checkCollision(Collider* other);

        float top();
        float bottom();
        float left();
        float right();
    protected:
    private:
};

#endif // BOXCOLLIDER_H
