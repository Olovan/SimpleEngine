#include "BoxCollider.h"

#include "Entity.h"
#include "Game.h"

BoxCollider::BoxCollider(Entity* iEntity) : Collider(iEntity)
{
    type = BOXCOLLIDER;
}

void BoxCollider::start()
{
    entity->game->colliders.insert(this);
}

bool BoxCollider::checkCollision(Collider* other)
{
    switch(other.type)
    {
    case BOXCOLLIDER:
        BoxCollider* myBox = static_cast<BoxCollider> other;
        if (left() < myBox->right() && right() > myBox->left() && top() < myBox->bottom() && bottom() > myBox->top())
            return true;
        else
            return false;
        break;
    case UNKNOWN:
        return false;
        break;
    default:
        return false;
        break;
    }
}

float BoxCollider::top()
{
    return entity->position.y;
}

float BoxCollider::bottom()
{
    return entity->position.y + size.y;
}

float BoxCollider::left()
{
    return entity->position.x;
}

float BoxCollider::right()
{
    return entity->position.x + size.x;
}
