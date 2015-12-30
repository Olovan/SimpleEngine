#include <iostream>

#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "Game.h"
    #include "Entity.h"
        #include "Component.h"
            #include "Physics.h"
            #include "Renderer.h"
            #include "CustomClasses.h"

using namespace std;

int main()
{
   //TEST CODE
   Game* game = new Game();
   Entity* currentEntity;
   currentEntity = game->createEntity(Vector2(645,478));
   currentEntity->createComponent<Physics>(currentEntity, Vector2(80,80));
   currentEntity->createComponent<Renderer>(currentEntity, Vector2(50,50), sf::Color::Red);
   currentEntity->createComponent<BouncingSquare>(currentEntity);

   currentEntity = game->createEntity(Vector2(200,178));
   currentEntity->createComponent<Physics>(currentEntity, Vector2(140,280));
   currentEntity->createComponent<Renderer>(currentEntity, Vector2(200,50), sf::Color::Yellow);
   currentEntity->createComponent<BouncingSquare>(currentEntity);

   currentEntity = game->createEntity(Vector2(40,678));
   currentEntity->createComponent<Renderer>(currentEntity, Vector2(10,100), sf::Color::Cyan);
   currentEntity->createComponent<BouncingSquare>(currentEntity);
   currentEntity->createComponent<Physics>(currentEntity, Vector2(400,600));

    game->start();
    cout << "Number of Renderers: " << game->renderers.size() << endl;
    cout << "Number of Entities: " << game->entities.size() << endl;

    while (game->window.isOpen())
    {
        game->update();
       // cout << 1 / game->clock.getElapsedTime().asSeconds() << " FPS" << endl;
    }

    getchar();
    return 0;
}
