#ifndef GAME_H
#define GAME_H

#include <Box2D/Box2D.h>
#include <vector>
#include <memory>
#include <set>
#include <SFML/Graphics.hpp>
#include <string>
#include "Entity.h"
#include "Renderer.h"
#include "Collider.h"
#include "TextureManager.h"
#include "Vector2.h"

class Game
{
    public:
        Game();
        Game(std::string fileName);


        Vector2 pixelToWorldRatio = Vector2(1,-1); //For converting between my world coordinates and SFML's coordinates because SFML does everything upside down on the Y axis
        float heightToWidthRatio;
        std::unique_ptr<b2World> world;
        sf::Clock clock;
        float elapsedTime;
        sf::RenderWindow window;
        TextureManager textureManager;
        std::set<Renderer*> renderers; //Renderers register themselves here in their Start() method and unregister in their destructor
        std::set<std::shared_ptr<Entity>> entities; //Entities get registered here whenever createEntity() is run
        std::set<Collider*> colliders;

        //TODO Add collider Vector

      //  Entity* createEntity(Vector2 iPosition); Old Entity creation method replaced by Template below
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
