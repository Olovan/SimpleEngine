#ifndef RENDERER_H
#define RENDERER_H

#include "Component.h"
#include "Vector2.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>


class Renderer : public Component
{
    public:
        Renderer(Entity *entity, Vector2 iDimensions );
        Renderer(Entity *entity, Vector2 iDimensions, sf::Color iColor );
        Renderer(Entity *entity, Vector2 iDimensions, std::string path);
        ~Renderer();


        Vector2 dimensions;
        sf::RectangleShape shape;
        sf::Texture texture;
        void start();
        void update(float deltaTime);
        std::shared_ptr<Component> clone();
    protected:

    private:
};

#endif // RENDERER_H
