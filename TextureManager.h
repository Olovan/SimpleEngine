#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <SFML/Graphics.hpp>
#include <memory>
#include <set>

class TextureString
{
    public:
        TextureString(std::string path);

        std::string path;
        sf::Texture* texture;
};

class TextureManager
{
    public:
        TextureManager();
        std::set<TextureString*> textures;

        sf::Texture* getTexture(std::string path);
        sf::Texture* addTexture(std::string path);
    protected:
    private:
};

#endif // TEXTUREMANAGER_H
