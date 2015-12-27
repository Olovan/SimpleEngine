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

        std::vector<std::shared_ptr<Renderer>> renderers;
        std::vector<std::shared_ptr<Entity>> entities;
        //TODO Add collider Vector

        Entity* createEntity(Vector2 iPosition);
        void update();
    protected:
    private:
};

#endif // GAME_H
