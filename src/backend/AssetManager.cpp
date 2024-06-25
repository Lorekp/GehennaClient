#include "AssetManager.h"

AssetManager* AssetManager::sInstance = nullptr;

AssetManager::AssetManager()
{
    assert(sInstance == nullptr);
    sInstance = this;
}

sf::Texture& AssetManager::getTexture(std::string filename)
{
#if !defined(WIN_32)
    filename = std::regex_replace(filename, std::regex("\\\\"), "/");
#endif

    auto& texMap = sInstance->m_Textures;

    auto pairFound = texMap.find(filename);

    if (pairFound != texMap.end())
    {
        return pairFound->second;
    }
    else
    {
        auto& texture = texMap[filename];
        texture.loadFromFile(filename);
        return texture;
    }
}

sf::Font& AssetManager::getFont(std::string filename)
{
#if !defined(WIN_32)
    filename = std::regex_replace(filename, std::regex("\\\\"), "/");
#endif

    auto& texMap = sInstance->m_Fonts;

    auto pairFound = texMap.find(filename);

    if (pairFound != texMap.end())
    {
        return pairFound->second;
    }
    else
    {
        auto& font = texMap[filename];
        font.loadFromFile(filename);
        return font;
    }
}
