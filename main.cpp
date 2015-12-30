#include <iostream>

#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include "Game.h"
    #include "Entity.h"
        #include "Component.h"
            #include "Physics.h"
            #include "Renderer.h"

using namespace std;

class TestComp : public Component
{
public:
    int number = 0;

    void shout()
    {
        printf("Number is %i \n",number);
    }
};

int main()
{
   //TEST CODE
   Game* game = new Game();
   Entity* currentEntity;
   Component* currentComponent;
   currentEntity = game->createEntity(Vector2(0,0));
   currentEntity->createComponent<Physics>(currentEntity);
   currentEntity->getComponent<Physics>()->velocity = Vector2(30,30);
   currentEntity->createComponent<Renderer>(currentEntity, Vector2(50,50), sf::Color::Red);
   currentEntity = game->createEntity(Vector2(400,400));
   currentEntity->createComponent<Physics>(currentEntity);
   currentEntity->createComponent<Renderer>(currentEntity, Vector2(50,50), sf::Color::Red);
   currentEntity = game->createEntity(Vector2(0,0));
   currentEntity->createComponent<Physics>(currentEntity);
   currentEntity->createComponent<Renderer>(currentEntity, Vector2(50,50), sf::Color::Red);
   currentEntity = game->createEntity(Vector2(0,0));
   currentEntity->createComponent<Physics>(currentEntity);
   currentEntity->createComponent<Renderer>(currentEntity, Vector2(50,50), sf::Color::Red);

    cout << "Number of Renderers: " << game->renderers.size() << endl;
    cout << "Number of Entities: " << game->entities.size() << endl;

    while (game->window.isOpen())
    {
        game->update();
    }

    getchar();
    return 0;
}
