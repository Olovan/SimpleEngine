#include <iostream>

#include <Box2D/Box2D.h>
#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "Game.h"
    #include "Entity.h"
        #include "Component.h"
            #include "Physics.h"
            #include "Renderer.h"
            #include "CustomClasses.h"
            #include "BoxCollider.h"

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
    currentEntity = game->createEntity(Vector2(0,0));
//    currentEntity->createComponent<Physics>(currentEntity, Vector2(80,80));
    currentEntity->createComponent<Renderer>(currentEntity, Vector2(1,1), sf::Color::Red);
//    currentEntity->createComponent<BouncingSquare>(currentEntity);
    currentEntity->createComponent<BoxCollider>(currentEntity, Vector2(1,1), b2_dynamicBody);

    currentEntity = game->createEntity(Vector2(2,2));
    currentEntity->createComponent<Renderer>(currentEntity, Vector2(1,1), sf::Color::Blue);
    currentEntity->createComponent<BoxCollider>(currentEntity, Vector2(1,1), b2_dynamicBody);

    currentEntity = game->createEntity(Vector2(4,1));
    currentEntity->createComponent<Renderer>(currentEntity, Vector2(1,1), sf::Color::Green);
    currentEntity->createComponent<BoxCollider>(currentEntity, Vector2(1,1), b2_dynamicBody);


    currentEntity = game->createEntity(Vector2(2,8));
    currentEntity->createComponent<Renderer>(currentEntity, Vector2(1,1), sf::Color::Yellow);
    currentEntity->createComponent<BoxCollider>(currentEntity, Vector2(1,1), b2_dynamicBody);

    currentEntity = game->createEntity(Vector2(1,0));
    currentEntity->createComponent<Renderer>(currentEntity, Vector2(1,1), sf::Color::Blue);
    currentEntity->createComponent<BoxCollider>(currentEntity, Vector2(1,1), b2_dynamicBody);


    Entity* whatTheDuck;
    whatTheDuck = game->createEntity(Vector2(0,-9.5));
    whatTheDuck->createComponent<Renderer>(whatTheDuck, Vector2(20,1), sf::Color::Blue);
    whatTheDuck->createComponent<BoxCollider>(whatTheDuck,Vector2(20,1), b2_staticBody);

    for(int n = 0 ; n < 100 ; n++)
    {
        currentEntity = game->createEntity(Vector2(rand()%20 - 10, rand()%10));
        currentEntity->createComponent<Renderer>(currentEntity, Vector2(.1,.1), sf::Color::Cyan);
        currentEntity->createComponent<BoxCollider>(currentEntity, Vector2(.1,.1), b2_dynamicBody);
    }

    currentEntity = game->createEntity(Vector2(3,4));
    currentEntity->createComponent<Renderer>(currentEntity, Vector2(0.5,0.5), "./Pictures/1.png");
    currentEntity->createComponent<BoxCollider>(currentEntity,Vector2(0.5,0.5), b2_dynamicBody);
    currentEntity->createComponent<PlayerController>(currentEntity);



    cout << game->textureManager.textures.size() << " Textures detected" << endl;

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
            cout << "Floor Y Position: " << whatTheDuck->position.y << endl;
            cout << "Player Y Position: " << currentEntity->position.y << endl;
        }
    }

    getchar();
    return 0;
}
