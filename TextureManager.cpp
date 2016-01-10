#include "TextureManager.h"
#include <locale>

TextureManager::TextureManager()
{
    //ctor
}

TextureString::TextureString(std::string path)
{
    this->path = path;
    texture = new sf::Texture();
    if(!texture->loadFromFile(path))
    {
        texture = nullptr;
    }
}

sf::Texture* TextureManager::getTexture(std::string path)
{
    std::transform(path.begin(),path.end(),path.begin(), ::toupper);
    sf::Texture* result = nullptr;
    for(TextureString* texstring : textures)
    {
        if (texstring->path == path)
        {
            result = texstring->texture;
        }
    }
    if (!result)
    {
        result = addTexture(path);
    }
    return result;
}

sf::Texture* TextureManager::addTexture(std::string path)
{
    TextureString* texture = new TextureString(path);
    if(texture->texture != nullptr)
        textures.insert(texture);
    return texture->texture;
}
