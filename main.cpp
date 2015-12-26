#include <iostream>
#include "Entity.h"
#include "Component.h"

using namespace std;

class TestComp : public Component
{
public:
    int number = 0;
    TestComp()
    {

    }
    TestComp(int iNumber)
    {
        number = iNumber;
    }
    void shout()
    {
        printf("Number is %i \n",number);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    Entity testEntity(1.2,2.2);
    testEntity.addComponent(std::make_shared<TestComp>(24));
    TestComp* comp = testEntity.getComponent<TestComp>();
    if(comp)
        comp->shout();
    cout << "Position: " << testEntity.position.x << " , " << testEntity.position.y << endl;
    return 0;
}
