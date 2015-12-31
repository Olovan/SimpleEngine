#ifndef GAME_H
#define GAME_H

#include <vector>
#include <set>
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
        std::set<Renderer*> renderers; //Renderers register themselves here in their Start() method and unregister in their destructor
        std::set<std::shared_ptr<Entity>> entities; //Entities get registered here whenever createEntity() is run
        //TODO Add collider Vector

      //  Entity* createEntity(Vector2 iPosition);
        void deleteEntity(Entity* iEntity);
        void start();
        void update();
        void handleWindowEvents();

        template <class... ARG> Entity* createEntity(ARG&&... args)
        {
            auto entity = std::make_shared<Entity>(std::forward<ARG>(args)...);
            entities.insert(entity);
            entity.get()->game = this;
            entity.get()->start();
            return entity.get();
        }
    protected:
    private:
};

#endif // GAME_H
