#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Renderer.h"

class Window
{
    public:
        //Constructors
        Window(std::string iName); //Fullscreen constructor
        Window(int iWidth, int iHeight, std::string iName); //Windowed Constructor

        //Parameters

        //Methods
        void handleEvents();
        void draw(Renderer &renderer); //TODO create Renderable component for window to draw
        void display();
    protected:
    private:
        sf::RenderWindow _window;
};

#endif // WINDOW_H
