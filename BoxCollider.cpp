#include "BoxCollider.h"

#include "Entity.h"
#include "Game.h"

BoxCollider::BoxCollider(Entity* iEntity, Vector2 iDimensions, b2BodyType iBodyType) : Collider(iEntity)
{
    type = BOXCOLLIDER;
    size = iDimensions;

    //Body Def
    b2BodyDef bodyDef;
    bodyDef.type = iBodyType;
    bodyDef.position = entity->position.box2D();

    //Body
    body = entity->game->world.get()->CreateBody(&bodyDef);

    //Shape
    b2PolygonShape shape;
    shape.SetAsBox(size.x / 2, size.y / 2);

    //Fixture
    b2FixtureDef fixtureDef;
    fixtureDef.density = 1;
    fixtureDef.shape = &shape;
    body->CreateFixture(&fixtureDef);
}

void BoxCollider::start()
{

}

void BoxCollider::update(float deltaTime)
{
    entity->position = body->GetPosition();
    entity->angle = body->GetAngle() * 180.0f / 3.14159265359;

}

bool BoxCollider::checkCollision(Collider* other)
{
    switch(other->type)
    {
    case BOXCOLLIDER:
        {
        BoxCollider* myBox = static_cast<BoxCollider*>(other);
        if (left() < myBox->right() && right() > myBox->left() && top() < myBox->bottom() && bottom() > myBox->top())
            return true;
        else
            return false;
        break;
        }
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
