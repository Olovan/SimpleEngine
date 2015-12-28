#include <iostream>

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
   Entity* currentEntity = game->createEntity(Vector2(0,0));
   currentEntity->createComponent<Physics>(currentEntity);
   currentEntity->createComponent<Renderer>(currentEntity, Vector2(1,1));
   currentEntity = game->createEntity(Vector2(0,0));
   currentEntity->createComponent<Physics>(currentEntity);
   currentEntity->createComponent<Renderer>(currentEntity, Vector2(1,1));
   currentEntity = game->createEntity(Vector2(0,0));
   currentEntity->createComponent<Physics>(currentEntity);
   currentEntity->createComponent<Renderer>(currentEntity, Vector2(1,1));
   currentEntity = game->createEntity(Vector2(0,0));
   currentEntity->createComponent<Physics>(currentEntity);
   currentEntity->createComponent<Renderer>(currentEntity, Vector2(1,1));

    cout << "Number of Renderers: " << game->renderers.size() << endl;
    cout << "Number of Entities: " << game->entities.size() << endl;
    getchar();
    return 0;
}
