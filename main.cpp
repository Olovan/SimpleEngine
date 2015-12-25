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
        std::cout << "It seems to work" << std::endl;
        printf("Number is %i",number);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    Entity testEntity(1.2,2.2);
    TestComp* comp = new TestComp(4);
    testEntity.addComponent( comp );
    comp = testEntity.getComponent<TestComp>();
    if(comp == nullptr)
    {
        cout << "It's null" << endl;
    }
    cout << "Position: " << testEntity.position.x << testEntity.position.y << endl;
    return 0;
}
