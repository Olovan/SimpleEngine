#include "Window.h"

Window::Window(std::string iName)
{

}

Window::Window(int iWidth, int iHeight, std::string iName)
{
    _window.create(sf::VideoMode(iWidth,iHeight),iName,sf::Style::Close);
}

void Window::handleEvents()
{
    while (_window.isOpen())
    {
        sf::Event event;
        while(_window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                _window.close();
        }
    }
}

void Window::draw(Renderer &iRenderer)
{
    _window.draw(iRenderer.shape);
}
