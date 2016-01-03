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
   currentEntity->createComponent<Renderer>(currentEntity, Vector2(10,10), sf::Color::Cyan);
   currentEntity->createComponent<BouncingSquare>(currentEntity);
   currentEntity->createComponent<Physics>(currentEntity, Vector2(400,600));

   Entity* currentEntity2 = game->createEntity(Vector2(400,400));
   currentEntity2->createComponent<Duplicator>(currentEntity2, currentEntity);

    game->start();

    //DIAGNOSTICS
    //cout << "Number of Renderers: " << game->renderers.size() << endl;
    //cout << "Number of Entities: " << game->entities.size() << endl;
    float frameCount = 0;
    float counter = 0;

    while (game->window.isOpen())
    {
        game->update();

        //DIAGNOSTICS
        frameCount++;
        if(game->elapsedTime - counter > 1)
        {
            cout << frameCount/(game->elapsedTime - counter) << " FPS" << endl;
            counter = game->elapsedTime;
            frameCount = 0;
            cout << "Number of Entities: " << game->entities.size() << endl;
        }
    }

    getchar();
    return 0;
}
