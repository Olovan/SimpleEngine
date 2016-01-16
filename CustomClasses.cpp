#include "CustomClasses.h"

#include "Game.h"
#include <iostream>
#include "Physics.h"
#include "Component.h"
#include "Vector2.h"
#include "Renderer.h"
#include "BoxCollider.h"

BouncingSquare::BouncingSquare(Entity* iEntity) : Component(iEntity)
{
    entity = iEntity;
}

void BouncingSquare::start()
{
    phys = entity->getComponent<Physics>();
    if(phys)
    {
        speed = phys->velocity;
        if(speed.x < 0)
            speed.x = -1 * speed.x;
        if(speed.y < 0)
            speed.y = -1 * speed.y;
    }
    Renderer* renderer = entity->getComponent<Renderer>();
    if(renderer)
    {
        size = renderer->dimensions;
    }
}

void BouncingSquare::update(float deltaTime)
{
    if(phys)
    {
        if(entity->position.x > 800 - size.x)
        {
            phys->velocity.x = -speed.x;
        }
        else if(entity->position.x < 0)
        {
            phys->velocity.x = speed.x;
        }
        if(entity->position.y > 800 - size.y)
        {
            phys->velocity.y = -1 * speed.y;
        }
        else if(entity->position.y < 0)
        {
            phys->velocity.y = speed.y;
        }
    }
}

std::shared_ptr<Component> BouncingSquare::clone()
{
    return std::make_shared<BouncingSquare>(entity);
}




Duplicator::Duplicator(Entity* iEntity, Entity* iTarget) : Component(iEntity)
{
    entity = iEntity;
    target = iTarget;
}

float timePast = 0;

void Duplicator::update(float deltaTime)
{
    timePast += deltaTime;
    if(timePast > 0.001)
    {
        Entity* newEntity = entity->game->createEntity(target);
        newEntity->position = entity->position;
        timePast = 0;
    }
}
void Duplicator::start()
{

}
std::shared_ptr<Component> Duplicator::clone()
{
    return std::make_shared<Duplicator>(entity, target);
}

PlayerController::PlayerController(Entity* iEntity) : Component(iEntity)
{

}

void PlayerController::start()
{
    boxCollider = entity->getComponent<BoxCollider>();
    boxCollider->body->SetFixedRotation(true);
}

void PlayerController::update(float deltaTime)
{
    b2Vec2 targetVelocity = boxCollider->body->GetLinearVelocity();

    //Controls
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        targetVelocity.x = -3;
        boxCollider->body->SetLinearVelocity(targetVelocity);
        //std::cout << "Left" << std::endl;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        targetVelocity.x = 3;
        boxCollider->body->SetLinearVelocity(targetVelocity);
        //std::cout << "Right" << boxCollider->body->GetLinearVelocity().x << std::endl;
    }
    else
    {
        targetVelocity.x = 0;
        boxCollider->body->SetLinearVelocity(targetVelocity);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        boxCollider->body->SetLinearVelocity(b2Vec2(targetVelocity.x, 5));

    //Camera Follow
    sf::View view = entity->game->window.getView();
    view.setCenter((entity->position * entity->game->sfmlWorldConversion * entity->game->pixelDensity).sfml());
    entity->game->window.setView(view);
}

std::shared_ptr<Component> PlayerController::clone()
{
    return std::make_shared<PlayerController>(*this);
}
