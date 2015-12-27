#include "Renderer.h"

Renderer::Renderer(Entity* iEntity, Vector2 iDimensions) : Component(iEntity)
{
    dimensions = iDimensions;
    entity = iEntity;
}

void Renderer::update(float deltaTime)
{

}

