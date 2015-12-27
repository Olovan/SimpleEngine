#include <iostream>
#include "Entity.h"
#include "Component.h"
#include "Vector2.h"
#include "Physics.h"

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
   Vector2 v1(5,2);
   Vector2 v2(sf::Vector2f(2,7));

    cout << (v1+v2).print() << endl;
    cout << (v1-v2).print() << endl;
    cout << (v1*v2).print() << endl;
    cout << (v1/v2).print() << endl;

    Entity* entity1 = new Entity(0,0);
    entity1->createComponent<Physics>(entity1);
    Physics* physComp = entity1->getComponent<Physics>();
    physComp->velocity = Vector2(1,1);
    physComp->update(1);
    cout << entity1->position.print() << endl;
    physComp->update(1);
    cout << entity1->position.print() << endl;
    physComp->update(.5);
    cout << entity1->position.print() << endl;

    getchar();
    return 0;
}
