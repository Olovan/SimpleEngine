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

    getchar();
    return 0;
}
