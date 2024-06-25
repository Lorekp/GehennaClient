#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <map>
#include <string>
#include <assert.h>
#include <regex>
#include <SFML/Graphics.hpp>

class AssetManager {

public:

	AssetManager();

	static AssetManager* getInstance()
	{
		if (sInstance == nullptr)
		{
			sInstance = new AssetManager();
		}
		return sInstance;
	}

	static sf::Texture& getTexture(std::string filename);
	static sf::Font& getFont(std::string filename);

private:

	std::map<std::string, sf::Texture> m_Textures;
	std::map<std::string, sf::Font> m_Fonts;

	//Asset Manager is a singleton, so only one instance can exist at a time 
	//sInstacne holds a static pointer to the single manager instance static AssetManager* sInstance;

	static AssetManager* sInstance;

};
#endif