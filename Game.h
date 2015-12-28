#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include "Entity.h"
#include "Renderer.h"

class Game
{
    public:
        Game();
        Game(std::string fileName);

        std::vector<std::shared_ptr<Renderer>> renderers; //Renderers register themselves here in their Start() method
        std::vector<std::shared_ptr<Entity>> entities; //Entities get registered here whenever createEntity() is run
        //TODO Add collider Vector

        Entity* createEntity(Vector2 iPosition);
        void update();
    protected:
    private:
};

#endif // GAME_H
