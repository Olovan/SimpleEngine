#ifndef GAME_H
#define GAME_H

#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include "Entity.h"
#include "Renderer.h"

class Game
{
    public:
        Game();
        Game(std::string fileName);

        sf::Clock clock;
        sf::RenderWindow window;
        std::vector<std::shared_ptr<Renderer>> renderers; //Renderers register themselves here in their Start() method
        std::vector<std::shared_ptr<Entity>> entities; //Entities get registered here whenever createEntity() is run
        //TODO Add collider Vector

        Entity* createEntity(Vector2 iPosition);
        void update();
        void handleWindowEvents();
    protected:
    private:
};

#endif // GAME_H
