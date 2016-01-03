#include "Collider.h"


Collider::Collider(Entity* iEntity) : Component(iEntity)
{
    type = UNKNOWN;
}

void Collider::start()
{
}

bool Collider::checkCollision(Collider* other)
{
}
