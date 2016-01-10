#include <iostream>

#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "Game.h"
    #include "Entity.h"
        #include "Component.h"
            #include "Physics.h"
            #include "Renderer.h"
            #include "CustomClasses.h"

#include <time.h>


#define PARTICLES_PER_BATCH 1000
#define PARTICLE_BATCHES 100

using namespace std;

int main()
{
    //TEST CODE
    Game* game = new Game();

    srand(time(NULL));

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
    currentEntity->createComponent<Renderer>(currentEntity, Vector2(5,5), sf::Color::Cyan);
    currentEntity->createComponent<BouncingSquare>(currentEntity);
    currentEntity->createComponent<Physics>(currentEntity, Vector2(400,600));

    currentEntity = game->createEntity(Vector2(40,678));
    currentEntity->createComponent<Renderer>(currentEntity, Vector2(5,5), sf::Color::Cyan);
    currentEntity->createComponent<BouncingSquare>(currentEntity);
    currentEntity->createComponent<Physics>(currentEntity, Vector2(400,600));

    currentEntity = game->createEntity(Vector2(40,678));
    currentEntity->createComponent<Renderer>(currentEntity, Vector2(100,100), "./pictures/1.png");
    currentEntity->createComponent<BouncingSquare>(currentEntity);
    currentEntity->createComponent<Physics>(currentEntity, Vector2(400,600));

    currentEntity = game->createEntity(Vector2(40,678));
    currentEntity->createComponent<Renderer>(currentEntity, Vector2(10,10), "./pictures/1.png");
    currentEntity->createComponent<BouncingSquare>(currentEntity);
    currentEntity->createComponent<Physics>(currentEntity, Vector2(200,600));

    currentEntity = game->createEntity(Vector2(40,678));
    currentEntity->createComponent<Renderer>(currentEntity, Vector2(100,100), "./Pictures/1.png");
    currentEntity->createComponent<BouncingSquare>(currentEntity);
    currentEntity->createComponent<Physics>(currentEntity, Vector2(400,100));

    currentEntity = game->createEntity(Vector2(40,678));
    currentEntity->createComponent<Renderer>(currentEntity, Vector2(100,100), "./pictuRes/1.png");
    currentEntity->createComponent<BouncingSquare>(currentEntity);
    currentEntity->createComponent<Physics>(currentEntity, Vector2(100,300));

    cout << game->textureManager.textures.size() << " Texture detected" << endl;

//    Entity* currentEntity2 = game->createEntity(Vector2(400,400));
//    currentEntity2->createComponent<Duplicator>(currentEntity2, currentEntity);

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
